/*
Implimentation File
 */

#include <cstring>
#include <cctype>
#include <iostream>
using namespace std;

#include "shrink.h"

int lookup(const char* word, const char* dictionary[])
{
  int index = 0;
  char currentWord[100];

  do {
    //assign currentWord to the dictionany of given index
    strcpy(currentWord, dictionary[index]);
    //if currentWord same as word return current index
    if (!strcmp(word,currentWord)) return index; 
    index++;
  } while (strcmp(currentWord,""));

  return -1;
}

void encode(const char* word, char compressed[100], const char* dictionary[])
{
  int position;

  //check length of word
  if (strlen(word) == 2)
    {
    //check if both characters are alphanumeric
    if (isalnum(word[0]) && isalnum(word[1]))
      {
      compressed[0] = '!';
      compressed[1] = word[0];
      compressed[2] = word[1];
      compressed[3] = '\0';
      return;
      }
    }

  //check if word is in dictionary
  position = lookup(word,dictionary);
  if (position > -1)
    {
    //if word in position 0-9
    if (position < 10)
      {
      compressed[0] = '0';
      compressed[1] = (char)(((int)'0')+position);
      }    
    //if word in position 10 - 99
    else if (position < 100)
      {
      compressed[0] = (char)(((int)'0')+position/10);
      compressed[1] = (char)(((int)'0')+position%10);
      }
    //if word in out of range 0 - 99
    else 
      {
      cerr << "Position out of 00 - 99 range with value: " << position << endl;
      }
    //add sentinal character and return
    compressed[2] = '\0';
    return;
    }

  //otherwise return same word
  strcpy(compressed,word);
  return;
}
