#include <jcaslib/os.h>

#include <err.h>
#include <stdlib.h>
#include <sys/stat.h>

int
os_isdir (const char *dpath)
{
    struct stat *sb = calloc (1, sizeof (struct stat));
    int s = stat (dpath, sb);
    if (s == -1)
    {
        warn ("stat error");
        free (sb);
        return (-1);
    }
    mode_t m = sb->st_mode;
    free (sb);
    return (S_ISDIR (m));
}