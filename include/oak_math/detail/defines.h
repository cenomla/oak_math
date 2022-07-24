#pragma once

#ifdef _MSC_VER

#ifdef OAK_MATH_DYNAMIC_LIB

#ifdef OAK_MATH_EXPORT_SYMBOLS
#define OAK_MATH_API __declspec(dllexport)
#else
#define OAK_MATH_API __declspec(dllimport)
#endif // OAK_MATH_EXPORT_SYMBOLS

#else

#define OAK_MATH_API

#endif // OAK_MATH_DYNAMIC_LIB

#else

#define OAK_MATH_API __attribute__((visibility("default")))

#endif // _MSC_VER


#ifndef __OSIG_REFLECT_MACRO__
#define __OSIG_REFLECT_MACRO__

#ifdef __OSIG__
#define _reflect(...) __attribute__((annotate("reflect;" #__VA_ARGS__)))
#else
#define _reflect(...)
#endif

#endif //__OSIG_REFLECT_MACRO__
