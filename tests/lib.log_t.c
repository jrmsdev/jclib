#include "../lib/log/log.c"
#include "../lib/log/log_dbg.c"
#include "../lib/log/log_err.c"
#include "../lib/log/log_print.c"
#include "../lib/log/log_warn.c"
#include <jcaslib/test.h>


void
fake_t (test_suite_T *ts)
{
    int expect = 1;
    test_T *t = t_start (ts, "fake", expect);

    t_check (t, 0, "");

    t_end (t);
}


int
main (int argc, char *argv[])
{
    if (argc < 1)
        errx (1, "ERROR: argc < 1???");

    int expect = 1;
    test_suite_T *ts = tsuite_start (argv[0], expect);

    fake_t (ts);

    return (tsuite_end (ts));
}
