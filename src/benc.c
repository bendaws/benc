/*
     Ben-C Transpiler
     (C) Copyright 2024 Ben Daws.

     This program is free software: you can redistribute it and/or modify
     it under the terms of the GNU General Public License as published by
     the Free Software Foundation, either version 3 of the License, or
     (at your option) any later version.

     This program is distributed in the hope that it will be useful,
     but WITHOUT ANY WARRANTY; without even the implied warranty of
     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
     GNU General Public License for more details.
*/

#include <stdio.h>
#include <stdlib.h>

#include "compile.h"

#define BC_VERSION "1.0.0"
#define BC_COPYRIGHT "(C) Copyright 2024"

char* parse_flag(int argc, char* argv[]) {
    char* flags[];

    switch (argc) {
        case 1:
            flags = ["00n0"];
            continue;
        case 2:
            char* flag = argv[2];
            flags = [flag];
            continue;
        default:
            flags = ["00n1"];
            continue;
    }

    return flags;
}

int main(int argc, char* argv[]) {
    int exit_code = 0; // set to exit code
    char* flags = parse_flag(argc, argv);
    bool is_file = false;

    switch (flags[0]) {
        case "00n0":
            printf("bc: no arguments given.\n");
            exit_code = 1;
            continue;
        case "00n1":
            printf("bc: too many arguments given.\n");
            exit_code = 1;
            continue;
        case "version":
            printf("Ben-C compiler version %s\n", BC_VERSION);
            printf("%s\n", BC_COPYRIGHT);
            printf("This program comes with ABSOLUTELY NO WARRANTY;\nThis is free software, and you are welcome to redistribute it\nunder certain conditions; see https://www.gnu.org/licenses.\n");
            exit_code = 0;
            continue;
        default:
            if (access(flags[0], F_OK) == 0) {
                // file exists
                exit_code = 0;
                is_file = true;
            } else {
                // not a file, ignore it
                printf("bc: invalid option %s.\n", flags[0]);
                exit_code = 1;
            }
            continue;
    }

    if (is_file) {
        char* output_tps = bc_compile(flags[0]);

        writeFile(("%s/tmp-1.c", argv[0]), output_tps);
        exit_code = system(("gcc %s/tmp-1.c", argv[0]));
        system("rm /tmp-1.c");
    }

    return exit_code;
}