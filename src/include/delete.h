/*
     Ben-C Transpier
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
#include <string.h>

void strdelete(char string[], char substr[])
{
  // i is used to loop through the string
  int i = 0;

  // store the lengths of the string and substr
  int string_length = strlen(string);
  int substr_length = strlen(substr);
  
  // loop through the string keeping track of our current index with i, 
  // starting at the first index
  while (i < string_length)
  {
    // if we find the substr at the current index, delete it
    if (strstr(&string[i], substr) == &string[i])
    {
      // determine the string's new length after removing the substr occurrence
      string_length -= substr_length;
      
      // shift forward the remaining characters in the string after the substr 
      // occurrence by the length of substr, effectively removing it!
      for (int j = i; j < string_length; j++)
        string[j] = string[j + substr_length];
    }
    else i++;
  }
  
  // put a null terminator at the end of the string 
  string[i] = '\0';
  
}