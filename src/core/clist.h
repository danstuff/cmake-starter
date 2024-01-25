#pragma once

#ifndef CLIST_H
#define CLIST_H

#include "cbase.h"

/* TODO docs */

#define clist(element_type, _capacity) \
struct \
{ \
  uint16_t element_size; \
  uint32_t length; \
  uint32_t capacity; \
  element_type data[_capacity]; \
}

typedef struct _clist_any 
{
  uint16_t element_size;
  uint32_t length;
  uint32_t capacity;
  uint8_t data;
} clist_any;

#define clist_size(list) ((list)->capacity * (list)->element_size)

#define clist_init(list) \
{ \
    (list)->element_size = sizeof((list)->data[0]); \
    (list)->capacity = (sizeof((list)->data) / (list)->element_size); \
    (list)->data[0] = 0; \
}

#define clist_clear(list, val) memset((list)->data, val, clist_size(list))

#define cstring(_capacity) clist(char, _capacity)

#define cstring_init(cstr) clist_init(cstr)

void clist_set(void* list, uint32_t index, uint32_t length, const void* data);

void cstring_set(void* str, const char* value);

#endif
