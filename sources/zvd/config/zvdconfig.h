/*
-----------------
 Persistent info
-----------------

This file is part of the "Zv3D" project.

MIT License

Copyright (c) 2012-2099 Marat Sungatullin

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

......
 Web:
......

 + https:// (for questions and help)

-------------
 Description
-------------
Purpose: config building of zvd.

----------------------
 For developers notes
----------------------
Original author:    Marat Sungatullin
Created:            jan 11, 2012
*/



#pragma once

#ifdef ZVD_USE_CUSTOM_CONFIG
// This file should be created by you for your own needs.
// Add path to this file in your build system.
#include "zvdcustomconfig.h"
#else
#include "zvddefaultconfig.h"
#endif // zvd config selection


//-----------------------------------------------------------------------------

// Verifies that a build configuration has been selected.
#if !defined(ZVD_CFG_BUILD_DEBUG) && \
    !defined(ZVD_CFG_BUILD_RELEASE) && \
    !defined(ZVD_CFG_BUILD_SHIPPING)
#error One of ZVD_CFG_BUILD_DEBUG, ZVD_CFG_BUILD_RELEASE, or ZVD_CFG_BUILD_SHIPPING must be defined
#endif

