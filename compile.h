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
#include <unistd.h>
#include "files.h"

char split_characters[] = [' ', ';', ',', '+', '-', '*', '&', '/', '(', ')', '{', '}', '#'];

bool is_split_character(char character)

char* bc_compile(char* fpath) {
    char* lines = readFile(fpath);

    for (int i = 0; i < sizeof(lines); i++) {
        // per line
        bool dirty = false;
        char* line = lines[i];
        char* currentKeyword = "";
        int keywordPos[] = [];

        for (int j = 0; j < sizeof(line); j++) {
            // per character
            char thisChar = line[j];

            if (is_split_character(thisChar) == true) {
                currentKeyword = "";
                keywordPos = [];
            } else {
                currentKeyword[sizeof(currentKeyword)] = thisChar;
                keywordPos[sizeof(keywordPos)] = j;
            }

            switch (currentKeyword) {
                case "string":
                    // string, replace the keyword positions with each character
                    char characters[] = ['c', 'h', 'a', 'r', '*'];

                    for (int k = 0; i < sizeof(keywordPos); k++) {
                        if (k == 4) {
                            // shifts all characters 1 index ahead to effectively "remove" the extra character.
                            int charsToMove = sizeof(line) - line[keywordPos[k]];

                            for (int m = 0; m < charsToMove; m++) {
                                // shift character ahead in the string
                                line[m] = line[m + 1];
                            }

                            line[sizeof(line) - 1] = NULL; // finally, get rid of the last character (a dupe)
                        } else {
                            line[keywordPos[k] = characters[k];
                        }
                    }

                    dirty = true;

                    continue;
                default:
                    // ignore
                    continue;
            }
        }
    }

    return lines;
}

bool is_split_character(char character) {
    bool value = false;

    for (int i = 0; i < sizeof(split_characters); i++) {
        if (character == split_characters[i]) {
            value = true;
        }
    }

    return value;
}