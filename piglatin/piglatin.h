/*
  Header File for Piglatin
*/

#include <iostream>
using namespace std;

// isVowel detiermines if the given char is a vowel at the position in the
// string of given length
bool isVowel(char ch, int position, int length);

// findFirstVowel returns the position of the first vowel in the given string
int findFirstVowel(const char* word);

// tanslateWord produces a piglatin translation of the given word
void translateWord(const char* word, char translated[]);

// translateStream translates the words in the inputStream into pilatin and
// returns them into the outputStream
void translateStream(istream& inputStream, ostream& outputStream);
