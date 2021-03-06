#ifndef _DEFAULT_SOURCE
#define _DEFAULT_SOURCE
#endif
#ifndef _XOPEN_SOURCE
#define _XOPEN_SOURCE
#endif

#include "jcasdb.h"
#include <time.h>
#include <stdlib.h>

int
dbinfo (DBM *db)
{
    char *version = db_fetch (db, DB_VERSION_KEY);
    char *created = db_fetch (db, DB_INIT_KEY);
    char *updated = db_fetch (db, DB_UPDATE_KEY);

    struct tm created_tm;
    struct tm updated_tm;
    strptime (created, "%s", &created_tm);
    strptime (updated, "%s", &updated_tm);

    char *created_string = asctime (&created_tm);
    char *updated_string = asctime (&updated_tm);

    log_print ("version: %s", version);
    log_print ("created: %s", strsep (&created_string, "\n"));
    log_print ("updated: %s", strsep (&updated_string, "\n"));

    return (0);
}
