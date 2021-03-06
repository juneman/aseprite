// SHE library
// Copyright (C) 2012-2013  David Capello
//
// This file is released under the terms of the MIT license.
// Read LICENSE.txt for more information.

#ifndef SHE_LOCKED_SURFACE_H_INCLUDED
#define SHE_LOCKED_SURFACE_H_INCLUDED
#pragma once

namespace she {

  class LockedSurface {
  public:
    virtual ~LockedSurface() { }
    virtual void unlock() = 0;
    virtual void clear() = 0;
    virtual void blitTo(LockedSurface* dest, int srcx, int srcy, int dstx, int dsty, int width, int height) const = 0;
    virtual void drawAlphaSurface(const LockedSurface* src, int dstx, int dsty) = 0;
  };

} // namespace she

#endif
