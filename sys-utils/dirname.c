// lola's not unix (LNU)
// dirname v1.0.0
// Copyright (C) 2024 Lola Robins

#define _UTIL_NAME "dirname"
#define _UTIL_VERS "1.0.0"
#include "common.h"

#include <stdio.h>
#include <libgen.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    // no args
    if (argc < 2)
    {
        fprintf(stderr, _ERR_NO_OPERAND, argv[0]);
        return 1;
    }

    // end char (NL if not zero flag not provided)
    char end = '\n';

    // parse flags
    char c;
    while ((c = getopt(argc, argv, "hvz")) != -1)
    {
        switch (c)
        {
        // help flag
        case 'h':
            printf("%s [opts] <path>\n"
                "get the directory containing the specified path."
                "  -h  help/usage\n  -v  version info\n"
                "  -z  omit newline from end\n", argv[0]);
            return 0;

        // version flag
        case 'v':
            printf(_VERSION_INFO);
            return 0;

        // zero (instead of NL at end)
        case 'z':
            end = 0;
            break;

        default:
            fprintf(stderr, _ERR_UNKNOWN_OPT, argv[0], optopt);
            return 1;
        }
    }

    if (optind >= argc)
    {
        fprintf(stderr, _ERR_NO_PATH, argv[0]);
        return 1;
    }

    printf("%s%c", dirname(argv[optind]), end);

    return 0;
}
