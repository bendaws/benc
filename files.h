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

char* readFile(char* fpath) {
    FILE *fptr;
    fptr = fopen(fpath, "r");

    char* fileContents[] = [];

    char* file = &fileContents;
    char* fileTxt = [];

    while(fgets(fileTxt, 99991, fptr)) {
        file[sizeof(file)] = fileTxt;
    }

    fclose(fptr);

    return file;
}

char* writeFile(char* fname; char* fileContents) {
    FILE *fptr;
    fptr = fopen(fname, "w");
    fprintf(fptr, fileContents);
    fclose(fptr);
}