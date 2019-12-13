//
// Created by Aletha Yellin on 13/12/2019.
//

#include <sys/types.h>
#include <sys/stat.h>

#include <assert.h>
#include <dirent.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>

static int ptree(char *curpath, char *const path);

int     main(int argc, char * const argv[])
{
    int k;
    int rval;

    for (rval = 0, k = 1; k < argc; k++)
        if (ptree(NULL, argv[k]) != 0)
            rval = 1;
    return (rval);
}

static int ptree(char *curpath, char *const path)
{
    char            ep[PATH_MAX];
    char            p[PATH_MAX];
    DIR             *dirp;
    struct dirent   entry;
    struct dirent   *endp;
    struct stat     st;

    if (curpath != NULL )
        snprintf(ep, sizeof(ep), "%s/%s", curpath, path);
    else
        snprintf(ep, sizeof(ep), "%s", path);
    if (stat(ep, &st) == -1)
        return (-1);
    if ((dirp = opendir(ep)) == NULL)
        return (-1);
    for (; ;)
    {
        endp = NULL;
        if (readdir_r(dirp, &entry, &endp) == -1)
        {
            closedir(dirp);
            return (-1);
        }
        if (endp == NULL)
            break;
        assert(endp == &entry);
        if (strcmp(entry.d_name, ".") == 0 || strcmp(entry.d_name, "..") == 0)
            continue;
        if (curpath != NULL)
            snprintf(ep, sizeof(ep), "%s/%s/%s", curpath, path, entry.d_name);
        if (stat(ep, &st) == -1)
        {
            closedir(dirp);
            return (-1);
        }
        if (S_ISREG(st.st_mode) || S_ISDIR(st.st_mode))
        {
            printf("%c %s\n", S_ISDIR(st.st_mode) ? 'd' : 'f', ep);
        }
        if (S_ISDIR(st.st_mode) == 0)
            continue;
        if (curpath != NULL)
            snprintf(p, sizeof(p), "%s/%s", curpath, path);
        else
            snprintf(p, sizeof(p), "%s", path);
        snprintf(ep, sizeof(ep), "%s", entry.d_name);
        ptree(p, ep);
    }
    closedir(dirp);
    return (0);
}



void    run_executables(const char *directory, const char *prefix)
{
    if(!directory || !prefix)
        return ;

}

