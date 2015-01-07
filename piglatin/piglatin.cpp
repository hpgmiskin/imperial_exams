/*
  Implimentation File for Piglatin
*/

#include "piglatin.h"

#include <iostream>
#include <cstring>
using namespace std;

bool isVowel(char ch, int position, int length)
{
  unsigned int i = 0;
  const char* properVowels = "aeiou";

  // if character is not a letter return false
  if (!isalpha(ch)) return false;

  // convert to uppercase for comparisons
  ch = tolower(ch);

  // if y check positions are applicable
  if ((ch == 'y') && ((position != 0) && (position != length - 1)))
    return true;

  // loop through properVowels - return true if match
  do {
    if (ch == properVowels[i]) return true;
    i++;
  } while (properVowels[i] != '\0');

  return false;
}

int findFirstVowel(const char* word)
{
  int i = 0;
  int length = strlen(word);

  // loop through word to find first vowel and return position
  do {
    if (isVowel(word[i],i,length)) return i;
    i++;
  } while (word[i] != '\0'); 

  return -1;
}

void translateWord(const char* word, char translated[])
{
  int i,isFirstCapital,vowelPosition;

  // Check if first character is a letter
  if (!isalpha(*word)){
    strcpy(translated,word);
    return;
  }

  // check if first letter is uppercase and find first vowel
  isFirstCapital = isupper(*word);
  vowelPosition = findFirstVowel(word);
  
  // If begins with vowel add "way"
  if (vowelPosition == 0)
    {
      strcpy(translated,word);
      strcat(translated,"way");
    }
  // If no vowel just add "ay"
  else if (vowelPosition == -1)
    {
      strcpy(translated,word);
      strcat(translated,"ay");
    }
  // Vowel in differnt location - take end of word then begining then ad "ay"
  else
    {
      strcpy(translated,word+vowelPosition);
      strncat(translated,word,vowelPosition);
      strcat(translated,"ay");
    }

  //Convert translated to lowercase
  i = 0;
  do {
    translated[i] = tolower(translated[i]);
    i++;
  } while (translated[i] != '\0');

  //Set first letter to captial if original capital
  if (isFirstCapital) translated[0] = toupper(translated[0]);
  
}

void translateStream(istream& inputStream, ostream& outputStream)
{
  int i = 0;
  char ch;
  const int maxLength = 70;
  char word[maxLength] = {""}, translated[maxLength] = {""};
  
  // no word case with eof handler
  while (!isalnum(inputStream.peek())){
    if (inputStream.eof()) return;
    inputStream.get(ch);
    outputStream << ch;
  }

  // word case to obtain words
  while (isalnum(inputStream.peek())){
    inputStream.get(word[i]);
    i++;
  }

  // obtain translation and send to output stream
  translateWord(word,translated);
  outputStream << translated;

  // recusive call
  translateStream(inputStream,outputStream);
}
