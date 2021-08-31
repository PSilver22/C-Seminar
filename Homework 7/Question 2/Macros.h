#ifndef _MACROS_H_
#define _MACROS_H_
#include <stdio.h>

#ifdef _DEBUG

#define TRACE_VAR(var, placeholder_string) printf("%s = " placeholder_string "\n", (#var), (var))

#endif // _DEBUG

#endif //_MACROS_H_