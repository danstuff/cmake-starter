#include "clist.h"

void clist_set(void* list, uint32_t index, uint32_t length, const void* data)
{
    clist_any* _list = list;
    cassertf(index+length < _list->capacity,
        "data range overflows list capacity [%i, %i] >= %i", 
        index,
        index+length,
        _list->capacity);
    _list->length = cmax(index+length, _list->length);
    memcpy((&_list->data)+(_list->element_size*index), data, _list->element_size*length);
}

void cstring_set(void* str, const char* value)
{
    const size_t len = value ? strlen(value) : 0;
    clist_set(str, len, 1, CPTR_TO_ZERO);
    if (len)
    {
        clist_set(str, 0, len, value);
    }
}
