/* Aseprite
 * Copyright (C) 2001-2013  David Capello
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef APP_CONTEXT_H_INCLUDED
#define APP_CONTEXT_H_INCLUDED
#pragma once

#include "app/context_flags.h"
#include "app/context_observer.h"
#include "app/context_observer_list.h"
#include "app/documents.h"
#include "base/disable_copying.h"
#include "base/exception.h"

#include <vector>

namespace app {
  class Command;
  class Document;
  class DocumentLocation;
  class ISettings;
  class Params;

  class CommandPreconditionException : public base::Exception {
  public:
    CommandPreconditionException() throw()
    : base::Exception("Cannot execute the command because its pre-conditions are false.") { }
  };

  class Context {
  public:
    virtual ~Context();

    virtual bool isUiAvailable() const     { return false; }
    virtual bool isRecordingMacro() const  { return false; }
    virtual bool isExecutingMacro() const  { return false; }
    virtual bool isExecutingScript() const { return false; }

    // TODO Refactor codebase to use ISettings::settings() instead
    ISettings* getSettings() {
      return settings();
    }
    ISettings* settings() { return m_settings; }

    const Documents& getDocuments() const;

    bool checkFlags(uint32_t flags) const { return m_flags.check(flags); }
    void updateFlags() { m_flags.update(this); }

    // Appends the document to the context's documents' list.
    void addDocument(Document* document);
    void removeDocument(Document* document);
    void sendDocumentToTop(Document* document);

    Document* getActiveDocument() const;
    DocumentLocation getActiveLocation() const;

    virtual void executeCommand(Command* command, Params* params = NULL);

    void addObserver(ContextObserver* observer);
    void removeObserver(ContextObserver* observer);

  protected:

    // The "settings" are deleted automatically in the ~Context destructor
    Context(ISettings* settings);

    virtual void onAddDocument(Document* document);
    virtual void onRemoveDocument(Document* document);
    virtual void onGetActiveLocation(DocumentLocation* location) const = 0;

  private:

    // Without default constructor
    Context();

    // List of all documents.
    Documents m_documents;

    // Settings in this context.
    ISettings* m_settings;

    // Last updated flags.
    ContextFlags m_flags;

    ContextObserverList m_observers;

    DISABLE_COPYING(Context);

  };

} // namespace app

#endif
