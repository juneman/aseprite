// Aseprite UI Library
// Copyright (C) 2001-2014  David Capello
//
// This file is released under the terms of the MIT license.
// Read LICENSE.txt for more information.

#ifndef UI_PANEL_H_INCLUDED
#define UI_PANEL_H_INCLUDED
#pragma once

#include "base/compiler_specific.h"
#include "ui/widget.h"

namespace ui {

  class Panel : public Widget {
  public:
    Panel();

    void showChild(Widget* widget);

  protected:
    virtual void onResize(ResizeEvent& ev) OVERRIDE;
    virtual void onPreferredSize(PreferredSizeEvent& ev) OVERRIDE;
  };

} // namespace ui

#endif