#include "../lib/lib.c"
#include "str_alloc.c"
#include "str_free.c"
#include "../../tests/test.h"


void
str_alloc_t (void)
{
    t_start ("str_alloc");
    str_type *s = str_alloc ();

    t_log ("sizeof -> %zu", sizeof (*s));
    t_check (EQ (sizeof (*s), 24), "sizeof != 24");

    t_log ("STR_ALLOC -> %d", STR_ALLOC);
    t_log ("allocated -> %zu", s->allocated);
    t_check (EQ (s->allocated, STR_ALLOC), "allocated != STR_ALLOC");

    t_log ("str_len -> %zu", str_len (s));
    t_check (EQ (str_len (s), 0), "str_len != 0");

    str_free (s);
    t_end ("str_alloc");
}


void
str_realloc_t (void)
{
    t_start ("str_realloc");
    str_type *s = str_alloc ();

    t_log ("sizeof -> %zu", sizeof (*s));
    t_check (EQ (sizeof (*s), 24), "sizeof != 24");

    t_log ("STR_ALLOC -> %d", STR_ALLOC);
    t_log ("allocated -> %zu", s->allocated);
    t_check (EQ (s->allocated, STR_ALLOC), "allocated != STR_ALLOC");

    str_realloc (s);
    t_log ("reallocated -> %zu", s->allocated);
    t_check (EQ (s->allocated, (STR_ALLOC * 2)),
                    "reallocated != (STR_ALLOC * 2)");

    str_free (s);
    t_end ("str_realloc");
}


int
main (void)
{
    str_alloc_t ();
    str_realloc_t ();
    return (0);
}
