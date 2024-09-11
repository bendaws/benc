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
#include <string.h>
#include <stdbool.h>

#define BC_VERSION "1.0.0"
#define BC_COPYRIGHT "(C) Copyright 2024"

#ifdef WIN32
#include <io.h>
#define access _access
#endif

#define F_OK 0

char* writeFile(char* fname, char* fileContents) {
    FILE *fptr;
    fptr = fopen(fname, "w");
    fprintf(fptr, fileContents);
    fclose(fptr);
}

char* readFile(char* fpath) {
    FILE *fptr;
    fptr = fopen(fpath, "r");

    char* fileContents;

    char* file = &fileContents;
    char* fileTxt;

    while(fgets(fileTxt, 99991, fptr)) {
        file[sizeof(file)] = fileTxt;
    }

    fclose(fptr);

    return file;
}

char* split_characters = " ;,+-*&/(){}#";

bool is_split_character(char character) {
    bool value = false;

    for (int i = 0; i < sizeof(split_characters); i++) {
        if (character == split_characters[i]) {
            value = true;
        }
    }

    return value;
}

// Assuming readFile and is_split_character are defined elsewhere

char* bc_compile(char* fpath) {
    char* lines = readFile(fpath);
    if (lines == NULL) {
        return NULL;
    }

    size_t linesLength = strlen(lines);

    for (size_t i = 0; i < linesLength; i++) {
        // per line
        bool dirty = false;
        char* line = &lines[i];
        char currentKeyword[256] = ""; // Assuming max keyword length is 255
        int keywordPos[256] = {-1}; // Assuming max keyword length is 255
        size_t keywordLength = 0;

        size_t lineLength = strlen(line);

        for (size_t j = 0; j < lineLength; j++) {
            // per character
            char thisChar = line[j];

            if (is_split_character(thisChar)) {
                currentKeyword[0] = '\0';
                keywordLength = 0;
            } else {
                currentKeyword[keywordLength] = thisChar;
                currentKeyword[keywordLength + 1] = '\0';
                keywordPos[keywordLength] = j;
                keywordLength++;
            }

            if (strcmp(currentKeyword, "string") == 0) {
                // string, replace the keyword positions with each character
                char characters[] = {'c', 'h', 'a', 'r', '*'};

                for (size_t k = 0; k < keywordLength; k++) {
                    if (k == 4) {
                        // shifts all characters 1 index ahead to effectively "remove" the extra character.
                        size_t charsToMove = lineLength - keywordPos[k];

                        for (size_t m = keywordPos[k]; m < lineLength - 1; m++) {
                            // shift character ahead in the string
                            line[m] = line[m + 1];
                        }

                        line[lineLength - 1] = '\0'; // finally, get rid of the last character (a dupe)
                    } else {
                        line[keywordPos[k]] = characters[k];
                    }
                }

                dirty = true;
                break; // Exit the inner loop as we have processed the keyword
            }
        }

        if (dirty) {
            // Handle the dirty line if needed
        }
    }

    return lines;
}

int main(int argc, char* argv[]) {
    int exit_code = 0; // set to exit code
    bool is_file = false;

    if (sizeof(argv) == 1) printf("bc: no arguments given.\n"); return 1;
    if (sizeof(argv) > 2) printf("bc: too many arguments given.\n"); return 1;

    char* flag = argv[1];

    if (flag == "--version") {
        printf("Ben-C compiler version %s\n", BC_VERSION);
        printf("%s\n", BC_COPYRIGHT);
        printf("This program comes with ABSOLUTELY NO WARRANTY;\nThis is free software, and you are welcome to redistribute it\nunder certain conditions; see https://www.gnu.org/licenses.\n");
        exit_code = 0;
    } else {
        if (access(flag, F_OK) == 0) {
            // file exists
            exit_code = 0;
            is_file = true;
        } else {
            // not a file, ignore it
            printf("bc: invalid option %s.\n", flag);
            exit_code = 1;
        }
    }

    if (is_file) {
        char* output_tps = bc_compile(flag);
        char* location = "%s/tmp-1.c", argv[0];

        writeFile(location, output_tps);
        exit_code = system(("gcc %s/tmp-1.c", argv[0]));
        system("rm /tmp-1.c");
    }

    return exit_code;
}

/*
I'd just like to interject for a moment. What you're referring to as Linux, is in fact, 
GNU/Linux, or as I've recently taken to calling it, GNU plus Linux. Linux is not an operating
system unto itself, but rather another free component of a fully functioning GNU system made
useful by the GNU corelibs, shell utilities and vital system components comprising a full OS as
defined by POSIX.

Many computer users run a modified version of the GNU system every day, without realizing it.
Through a peculiar turn of events, the version of GNU which is widely used today is often called
"Linux", and many of its users are not aware that it is basically the GNU system, developed by the
GNU Project.

There really is a Linux, and these people are using it, but it is just a part of the system they use.
Linux is the kernel: the program in the system that allocates the machine's resources to the other
programs that you run. The kernel is an essential part of an operating system, but useless by itself;
it can only function in the context of a complete operating system. Linux is normally used in
combination with the GNU operating system: the whole system is basically GNU with Linux added, or
GNU/Linux. All the so-called "Linux" distributions are really distributions of GNU/Linux.
*/