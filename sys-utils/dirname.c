// lola's not unix (LNU)
// dirname v1.0.0
// Copyright (C) 2024 Lola Robins

#include <stdio.h>
#include <libgen.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int arg_offset = 0;

    // accommodate leading --
    if (argc != 1 && !strcmp(argv[1], "--"))
        arg_offset = 1;

    // no path
    if (argc < 2 + arg_offset)
    {
        fprintf(stderr, "%s: no operand\n", argv[arg_offset]);
        return 1;
    }

    puts(dirname(argv[1 + arg_offset]));

    return 0;
}
