// Aseprite UI Library
// Copyright (C) 2001-2013  David Capello
//
// This file is released under the terms of the MIT license.
// Read LICENSE.txt for more information.

#ifndef UI_COMBOBOX_H_INCLUDED
#define UI_COMBOBOX_H_INCLUDED
#pragma once

#include "base/compiler_specific.h"
#include "base/signal.h"
#include "ui/widget.h"

#include <string>
#include <vector>

namespace ui {

  class Button;
  class Entry;
  class ListBox;
  class ListItem;
  class Window;

  class ComboBoxEntry;
  class ComboBoxListBox;

  class ComboBox : public Widget
  {
    friend class ComboBoxEntry;
    friend class ComboBoxListBox;

  public:
    typedef std::vector<ListItem*> ListItems;

    ComboBox();
    ~ComboBox();

    ListItems::iterator begin() { return m_items.begin(); }
    ListItems::iterator end() { return m_items.end(); }

    void setEditable(bool state);
    void setClickOpen(bool state);
    void setCaseSensitive(bool state);

    bool isEditable();
    bool isClickOpen();
    bool isCaseSensitive();

    int addItem(ListItem* item);
    int addItem(const std::string& text);
    void insertItem(int itemIndex, ListItem* item);
    void insertItem(int itemIndex, const std::string& text);

    // Removes the given item (you must delete it).
    void removeItem(ListItem* item);

    // Removes and deletes the given item.
    void removeItem(int itemIndex);

    void removeAllItems();

    int getItemCount() const;

    ListItem* getItem(int itemIndex);
    const std::string& getItemText(int itemIndex) const;
    void setItemText(int itemIndex, const std::string& text);
    int findItemIndex(const std::string& text);

    ListItem* getSelectedItem() const;
    void setSelectedItem(ListItem* item);

    int getSelectedItemIndex() const;
    void setSelectedItemIndex(int itemIndex);

    Entry* getEntryWidget();
    Button* getButtonWidget();

    void openListBox();
    void closeListBox();
    void switchListBox();
    gfx::Rect getListBoxPos() const;

    // Signals
    Signal0<void> Change;
    Signal0<void> OpenListBox;
    Signal0<void> CloseListBox;

  protected:
    bool onProcessMessage(Message* msg) OVERRIDE;
    void onResize(ResizeEvent& ev) OVERRIDE;
    void onPreferredSize(PreferredSizeEvent& ev) OVERRIDE;
    virtual void onChange();
    virtual void onOpenListBox();
    virtual void onCloseListBox();

  private:
    void onButtonClick(Event& ev);

    ComboBoxEntry* m_entry;
    Button* m_button;
    Window* m_window;
    ComboBoxListBox* m_listbox;
    ListItems m_items;
    int m_selected;
    bool m_editable : 1;
    bool m_clickopen : 1;
    bool m_casesensitive : 1;
  };

} // namespace ui

#endif
