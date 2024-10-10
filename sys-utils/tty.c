// lola's not unix (LNU)
// tty v1.0.0
// Copyright (C) 2024 lolasnotunix

#define _UTIL_NAME "tty"
#define _UTIL_VERS "1.0.0"
#include "common.h"

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    char c;
    while ((c = getopt(argc, argv, "hv")) != -1)
    {
        switch (c)
        {
        case 'h':
            printf("%s [-hv]\n"
                "get the path of the active tty.\n"
                "  -h  print help/usage\n"
                "  -v  print version info\n", argv[0]);
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
    
    char *tty_name = ttyname(STDIN_FILENO);
    if (!tty_name)
    {
        fprintf(stderr, _ERR_CALL_FAIL, "ttyname", strerror(errno));
        return 1;
    }

    printf("%s\n", tty_name);

    return 0;
}