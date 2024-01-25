#pragma once

#ifndef CBASE_H
#define CBASE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdarg.h>
#include <string.h>

/* TODO docs */

#define cstr(m) #m
#define cxstr(m) cstr(m)

#define clog_label "[" __FILE__ ":" cxstr(__LINE__) "] "

#define clog(message) printf(clog_label "%s\n", message)
#define clogf(format, ...) printf(clog_label format "\n", __VA_ARGS__)
#define clogfv(format, arg_list) \
{ \
    printf(clog_label); \
    vprintf(format, arg_list); \
    printf("\n"); \
}

#define cassert(condition) \
if (!(condition)) \
{\
  clog("assertion failed - " #condition); \
  exit(1); \
}
#define cassertf(condition, format, ...) \
if (!(condition)) \
{ \
  clogf("assertion failed - " format, __VA_ARGS__); \
  exit(1); \
}
#define cassertfv(condition, format, arg_list) \
if (!(condition)) \
{ \
  clogfv("assertion failed - " format, arg_list); \
  exit(1); \
}

#define cmin(a, b) (((a) < (b)) ? (a) : (b))
#define cmax(a, b) (((a) > (b)) ? (a) : (b))

#define ccount(array) (sizeof(array) / sizeof(array[0]))

#define cfield_size(type, field) sizeof(((type*)0)->field)

extern uint8_t* CPTR_TO_ZERO;
extern uint8_t* CPTR_TO_ONE;

#endif
