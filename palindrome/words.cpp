/*
Implimentation file for words
 */

#include "words.h"

#include <iostream>
#include <cstring>
using namespace std;

void reverse(const char* word, char reversed[])
{
  //find length of word
  unsigned int index, length;
  for (index=0; *(word+index) != '\0'; index++);

  length = index - 1;

  //iterate backwards through word populating reverse
  for (index=0; index<=length; index++){
    reversed[index] = *(word + length - index);
  }

  //add sentinal character to reversed
  reversed[index] = '\0';
}

int compare(const char* one, const char* two)
{
  //base case
  if ((*one == '\0') && (*two == '\0'))
    return 1;

  //check for non punctuation one
  if (!isalpha(*one) && (*one != '\0'))
    return compare(one+1,two);

  //check for non punctuation two
  if (!isalpha(*two) && (*two != '\0'))
    return compare(one,two+1);
  
  //itterative call
  if (tolower(*one) == tolower(*two))
    return compare(one+1,two+1);
  
  return 0;
}

int palindrome(const char* sentence)
{
  int isPalindrome;

  //find length of sentence
  unsigned int length;
  for (length=0; *(sentence+length) != '\0'; length++);

  //create memory on heap for reversed sentence and compute
  char* reversed = new char[length];
  reverse(sentence,reversed);

  //compare sentence and reversed sentence then delete memort off heap
  isPalindrome = compare(sentence,reversed);
  delete []reversed;
  
  return isPalindrome;
}

int compare(char one, char two)
{
  int oneAlpha = isalpha(one), twoAlpha = isalpha(two);

  //if both alpha compare else return if one is alpha
  if (oneAlpha && twoAlpha)
    return (tolower(one) < tolower(two));
  else
    return oneAlpha;
  
}

void sort(char string[])
{
  char temp;
  unsigned int i=0,j;

  //work through string pulling letters high in the alphabet to the begining
  do {
    j = i;
    do {
      // if a swap is required use tempory value to swap characters
      if (compare(string[j],string[i])){
	temp = string[j];
	string[j] = string[i];
	string[i] = temp;
      }	
      j++;
    } while (string[j] != '\0');
    i++;
  } while (string[i] != '\0');
  
}

int anagram(const char* one, const char* two)
{
  int isAnagram;
  unsigned int lengthOne, lengthTwo;

  //find length of both strings
  for (lengthOne=0; *(one+lengthOne) != '\0'; lengthOne++);
  for (lengthTwo=0; *(one+lengthTwo) != '\0'; lengthTwo++);

  //create memory on the heap for one and sort
  char* newOne = new char[lengthOne];
  strcpy(newOne,one);
  sort(newOne);

  //create memory on the heap for two and sort
  char* newTwo = new char[lengthTwo];
  strcpy(newTwo,two);
  sort(newTwo);

  //check if the sorted strings hold the same letters
  isAnagram = compare(newOne,newTwo);

  //delete memory from the heap
  delete [] newOne;
  delete [] newTwo;

  return isAnagram;
}
