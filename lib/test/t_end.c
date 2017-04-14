#include <jcaslib/test.h>

static void free_log (test_T *t);
static void show_log (test_T *t);
static void free_t (test_T *t);

int
t_end (test_T *t)
{
    t_check (t, EQ (t->run, t->expect), "check(s) run != expect");
    t->run--; /* discount previous call to t_check */
    int stat = t->failed;
    if (stat == 0)
    {
        warnx ("[ OK ] %s: %d/%d check(s)", t->name, t->run, t->expect);
    }
    else
    {
        t_log (t, "check(s) run: %d/%d - fail: %d", t->run, t->expect, stat);
        show_log (t);
    }
    free_log (t);
    free_t (t);
    return stat;
}

void
free_log (test_T *t)
{
    for (size_t i = 0; i < t->loglines; i++)
    {
        free (t->log[i]);
        t->log[i] = NULL;
    }
    free (t->log);
    t->log = NULL;
}

void
show_log (test_T *t)
{
    for (size_t i = 0; i < t->loglines; i++)
        warnx ("[....] %s: %s", t->name, t->log[i]);
}

void
free_t (test_T *t)
{
    t->name = NULL;
    t->expect = 0;
    t->run = 0;
    t->failed = 0;
    t->log = NULL;
    t->loglines = 0;
    t->fatal_error = 0;
    free (t);
    t = NULL;
}
