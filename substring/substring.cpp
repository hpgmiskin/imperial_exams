/*
Substring implimentation file
 */

#include <cstring>
#include <iostream>
using namespace std;

#include "substring.h"

bool is_prefix(const char* substring, const char* string)
{
  //check base case of empty substring
  if (!strcmp(substring,""))
    return true;

  //check if first characters are equal
  if (*substring == *string)
    return is_prefix(substring+1,string+1);

  return false;
}


int substring_position(const char* substring, const char* string)
{
  int position = 0;

  //check if is_prefix can be realised for each character in string
  do {
    if (is_prefix(substring,string+position)) return position;
    position++;
  } while (*(string+position) != '\0');

  return -1;
}
