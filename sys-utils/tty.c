// lola's not unix (LNU)
// tty v1.0.0
// Copyright (C) 2024 lolasnotunix

#define _UTIL_NAME "tty"
#define _UTIL_VERS "1.0.0"
#include "common.h"

#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char c;
    while ((c = getopt(argc, argv, "hvz")) != -1)
    {
        switch (c)
        {
        case 'h':
            printf("%s [-hv] [path] [suffix]\n"
                "get the path of the active tty.\n"
                "  -h  print help/usage\n  -v  print version info\n", argv[0]);
            return 0;

        case 'v':
            printf(_VERSION_INFO);
            return 0;
        default:
            fprintf(stderr, _ERR_UNKNOWN_OPT, argv[0], optopt);
            return 1;
        }
    }

    if (optind != argc)
    {
        fprintf(stderr, _ERR_TOO_MANY_OPERANDS, argv[0]);
        return 1;
    }

    printf("%s\n", ttyname(STDIN_FILENO));

    return 0;
}