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

#ifndef APP_UI_WORKSPACE_VIEW_H_INCLUDED
#define APP_UI_WORKSPACE_VIEW_H_INCLUDED
#pragma once

namespace ui {
  class Widget;
}

namespace app {

  class WorkspaceView {
  public:
    virtual ~WorkspaceView() { }

    virtual ui::Widget* getContentWidget() = 0;
    virtual WorkspaceView* cloneWorkspaceView() = 0;
    virtual void onWorkspaceViewSelected() = 0;

    // Called after the view is added in the correct position inside
    // the workspace. It can be used to copy/clone scroll position
    // from the original view.
    virtual void onClonedFrom(WorkspaceView* from) = 0;
  };

} // namespace app

#endif
