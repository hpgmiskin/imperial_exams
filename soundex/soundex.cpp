/*
Soundex Implimentation File
 */
#include "soundex.h"

#include <iostream>
#include <cctype>
using namespace std;

int lookup(const char character)
{
  unsigned int i, j;
  const char* map[7];

  //define codes through map index
  map[0] = NULL;
  map[1] = "bfpv";
  map[2] = "cgjkqsxz";
  map[3] = "dt";
  map[4] = "l";
  map[5] = "mn";
  map[6] = "r";

  //for map indexes 1-6
  for (i = 1; i<7; i++){
    j = 0;
    //loop through the string - if character found return index
    do {
      if (*(map[i]+j) == character) return i;
      j++;
    } while (*(map[i]+j) != '\0');
  }

  return 0;
}

void encode(const char* surname, char soundex[5])
{
  int currentCode,lastCode = 0;
  unsigned int i = 1, j = 1;

  soundex[0] = toupper(*surname);

  do {
    currentCode = lookup(*(surname+i));
    
    if (currentCode){
      if (currentCode != lastCode){
	soundex[j] = (char)(((int)'0')+currentCode);
	j++;
	}
    }
    
    lastCode = currentCode;
    i++;
  } while (*(surname+i) != '\0');

  for (j; j<4; j++){
    soundex[j] = '0';
  }
  soundex[4] = '\0';

}

int compare(const char* one, const char* two)
{
  //base case where both empty strings
  if ((*one == '\0') && (*two == '\0'))
    return 1;

  //recusive call where both first characters are the same
  if (*one == *two)
    return compare(one+1,two+1);

  //otherwise return 0
  return 0;
}

int count(const char* surname, const char* sentence)
{
  unsigned int count = 0, sentenceIndex = 0, wordIndex = 0;
  char baseCode[5], testWord[100], testCode[5];
  
  //find surname given
  encode(surname,baseCode);

  //work through the sentence
  do {
    //reset wordIndex
    wordIndex = 0;

    //while the current character is a letter asign to testWord
    while (isalpha(*(sentence + sentenceIndex + wordIndex))){
      testWord[wordIndex] = *(sentence + sentenceIndex + wordIndex);
      wordIndex++;
    }

    //if word of any length found
    if (wordIndex){
      //add sentinal character at end of word
      testWord[wordIndex] = '\0';
      //encode to soundex
      encode(testWord,testCode);
      //compare with base soundex and if the same increment count
      count += compare(baseCode,testCode);
      //put the sentence position to after the current word
      sentenceIndex += wordIndex;
    } else sentenceIndex++;

    // loop until sential character reached
  } while (*(sentence + sentenceIndex) != '\0');

  return count;
}
