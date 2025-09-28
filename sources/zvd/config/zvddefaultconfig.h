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
Purpose: config building of zvd (default).

----------------------
 For developers notes
----------------------
Original author:    Marat Sungatullin
Created:            jan 11, 2012
*/

#pragma once

//#define ZVD_CFG_USE_EXCEPTIONS
#define ZVD_CFG_BUILD_DEBUG



#define ZVD_CFG_MIN_MSVC_VER 1930

#define ZVD_CFG_MIN_GNUC_MAJOR 13
#define ZVD_CFG_MIN_GNUC_MINOR 0
#define ZVD_CFG_MIN_GNUC_PATCHLEVEL 0

// Compiler warnings (msvc)
//#define ZVD_CFG_DISABLE_WARN4996



//== std string utils =========================================================
#ifdef ZVD_CFG_DISABLE_WARN4996
#	define ZVD_CFG_USE_NOSECURE_VSNPRINTF

#endif

#define ZVD_CFG_MAX_CSTR_LEN 16384

//== memory ===================================================================

#define ZVD_CFG_ALLOC_UP_LIMIT (256 * 1024 * 1024)
#define ZVD_CFG_DEBUG_MEMORY
#define ZVD_CFG_UNITTEST_MEMORY
