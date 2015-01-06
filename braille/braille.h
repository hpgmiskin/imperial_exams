/*
  Header File for Braile
*/

#include <iostream>
using namespace std;

// lookup value of lower case character or punctuation
const char* lookup_character(char ch);

// encode character and return length of braille encoding
int encode_character(char ch, char braille[]);

// encode plaintext into a string of braile characters
void encode(const char* plaintext, char braille[]);

// print braille correctly formatted above plaintext
void print_braille(const char* plaintext, ostream& output);
