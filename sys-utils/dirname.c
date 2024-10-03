// lola's not unix (LNU)
// dirname v1.0.0
// Copyright (C) 2024 Lola Robins

#include <stdio.h>
#include <libgen.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int o = argc > 1 && !strcmp(argv[1], "--");
    if (argc < 2 + o) {
        fprintf(stderr, "%s: no operand\n", argv[o]);
        return 1;
    }
    puts(dirname(argv[++o]));
    return 0;
}
