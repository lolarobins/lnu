// lola's not unix (LNU)
// basename v1.0.0
// Copyright (C) 2024 Lola Robins

#include <stdio.h>
#include <libgen.h>
#include <string.h>

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
    char *input = argv[1];
    char *suffix = NULL;
    int arg_offset = 0;

    // accommodate leading --
    if (argc != 1 && !strcmp(argv[1], "--"))    
    {
        input = argv[2];
        arg_offset = 1;
    }

    // no path
    if (argc < 2 + arg_offset)
    {
        fprintf(stderr, "%s: no operand\n", argv[0 + arg_offset]);
        return 1;
    }

    // check suffix
    if (argc == 3 + arg_offset)
        suffix = argv[2 + arg_offset];

    // result
    puts(_basename(input, suffix));

    return 0;
}
