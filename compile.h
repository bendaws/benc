#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "files.h"

#ifdef WIN32
#include <io.h>
#define access _access
#endif

#define F_OK 0

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