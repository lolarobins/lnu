// lola's not unix (LNU)
// basename v1.0.0
// Copyright (C) 2024 lolasnotunix

#define _UTIL_NAME "basename"
#define _UTIL_VERS "1.0.0"
#include "common.h"

#include <stdio.h>
#include <libgen.h>
#include <string.h>
#include <unistd.h>

char *_basename(char *name, const char *suffix)
{
    // use basename from libgen
    name = basename(name);

    // remove suffix (if exists)
    if (suffix)
    {
        size_t len_suffix = strlen(suffix) ,len_name = strlen(name);
        
        // suffix bigger than basename
        if (len_suffix > len_name)
            return name;

        // suffix doesnt match
        if(strcmp(name + len_name - len_suffix, suffix))
            return name;

        // cut off with null char
        name[len_name - len_suffix] = 0;
    }

    return name;
}

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
            printf("%s [-hvz] [path] [suffix]\n"
                "get the base name for a file with a given path, removing "
                "the provided suffix if present.\n"
                "  -h  print help/usage\n  -v  print version info\n"
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

    printf("%s%c", _basename(argv[optind], 
        (optind + 1) >= argc ? NULL: argv[optind +1]), end);

    return 0;
}
