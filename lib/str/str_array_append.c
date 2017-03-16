#include <jclib/str.h>

void
str_array_append (str_array_type *arr, const char *str)
{
    size_t idx = arr->last + 1;
    str_array_insert (arr, idx, str);
}