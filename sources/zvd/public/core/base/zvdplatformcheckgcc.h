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
Purpose: detect the target operating system.

----------------------
 For developers notes
----------------------

*/

#pragma once

#ifndef ZVD_COMPILER_GNUC
#   error "This file is for gnu c++ compiler only"
#endif

//-------------------------------
// Identify the Operating System

// We use this guard to ensure platform is defined only once.
#ifdef ZVD_PLATFORM_DEFINED
#   error "Platform is already defined!"
#endif


// ============================================================================
// 1. Supported Platforms
// ============================================================================

#if defined(_WIN64)
#	if !defined(ZVD_PLATFORM_WIN64)
#		define ZVD_PLATFORM_WIN64 1
#       define ZVD_PLATFORM_WINDOWS 1 // Generic Windows flag
#       define ZVD_PLATFORM_STRING "Windows x64"
#		define ZVD_OS_WINDOWS64
#		define ZVD_OS_STRING "Win64"
#       if !defined(ZVD_OS_64)
#           define ZVD_OS_64
#       endif
#       define ZVD_PLATFORM_DEFINED 1
#	endif


#elif defined(__linux__) || defined(linux)
#   if !defined(ZVD_PLATFORM_LINUX)
#       define ZVD_PLATFORM_LINUX 1
#       define ZVD_PLATFORM_STRING "Linux"
#       define ZVD_PLATFORM_UNIX 1
#       define ZVD_PLATFORM_POSIX 1
#		define ZVD_OS_LINUX
#		define ZVD_OS_STRING "Linux"
#       define ZVD_PLATFORM_DEFINED 1
#   endif


// ============================================================================
// 2. Future Platforms (Stubs with errors) - Per your request (2) & (3)
// ============================================================================

#elif defined(__PROSPERO__) || defined(ZVD_PLATFORM_PS5) // PROSPERO is the common name for PS5
    #error "Platform PlayStation 5 is planned but not yet supported."
    #define ZVD_PLATFORM_DEFINED 0

#elif defined(_GAMING_XBOX_SCARLETT)
    #error "Platform Xbox Series X/S is planned but not yet supported."
    #define ZVD_PLATFORM_DEFINED 0

#elif defined(__APPLE__)
#   error "Platform macOS / iOS is not yet supported."
#   if !defined(ZVD_PLATFORM_MACOS)
#       define ZVD_PLATFORM_MACOS 1
#		define ZVD_OS_MACOS
#		define ZVD_OS_STRING "MacOS"
#       define ZVD_PLATFORM_DEFINED 0
#   endif

#elif defined(__ANDROID__)
    #error "Platform Android is not yet supported."
    #define ZVD_PLATFORM_DEFINED 0


// ============================================================================
// 3. Legacy Platforms (Explicitly unsupported) - Per your request (1)
// ============================================================================

#elif defined(_WIN32) || defined(__WIN32__)  || defined(WIN32)
#   error "Legacy platform Win32 is not supported. Please compile for x64."
#	if !defined(ZVD_PLATFORM_WIN32)
#		define ZVD_PLATFORM_WIN32 1
#		define ZVD_OS_WINDOWS32
#		define ZVD_OS_STRING "Win32"
#       define ZVD_PLATFORM_DEFINED 0
#	endif


#elif defined(SN_TARGET_PS3) || defined(_PS3) || defined(PS3)
#   error "Legacy platform PlayStation 3 is not supported."
#   if !defined(ZVD_PLATFORM_PS3)
#       define ZVD_PLATFORM_PS3 1
#		define ZVD_OS_PS3
#		define ZVD_OS_STRING "PS3"
#		define ZVD_BIG_ENDIAN 1
#       define ZVD_PLATFORM_DEFINED 0
#   endif

#elif defined(EA_PLATFORM_PS4) // Or whatever macro EABase uses for PS4
    #error "Legacy platform PlayStation 4 is not supported."
    #define ZVD_PLATFORM_DEFINED 0

#elif defined(EA_PLATFORM_XBOXONE)
    #error "Legacy platform Xbox One is not supported."
    #define ZVD_PLATFORM_DEFINED 0

#else
#   error "Your platform is not identified"
#endif


// ============================================================================
// 4. CPU Architecture & Endianness (cleaned up)
// ============================================================================
#if defined(_M_X64) || defined(__x86_64__)
#   define ZVD_ARCH_X64
#   define ZVD_ARCH_64_BIT
#   define ZVD_LITTLE_ENDIAN 1

#elif defined(_M_IX86) || defined(__i386__) || defined(__i386) || defined(i386)
#   error "Legacy 32-bit platforms are not supported"
#   define ZVD_ARCH_X86
#   define ZVD_ARCH_32_BIT
#   define ZVD_LITTLE_ENDIAN 1
#else
    #error "Unsupported CPU architecture."
#endif