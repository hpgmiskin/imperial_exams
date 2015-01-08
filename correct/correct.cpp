#include "correct.h"

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

void ascii_to_binary(char ch, char *binary) {
  for (int n = 128; n; n >>= 1) 
    *binary++ = (ch & n) ? '1' : '0';
  *binary = '\0';
}

char binary_to_ascii(const char *binary) {
  int ch = 0;
  for (int n=0, slide=128; n<8; n++, slide >>= 1) {
    if (binary[n] == '1')
      ch = ch | slide;
  }
  return ch;
}

void text_to_binary(const char *text, char *binary)
{
  //base case
  if (*text == '\0') return;

  // convert ascii digit and recall function
  ascii_to_binary(*text,binary);
  text_to_binary(text+1,binary+8);
}

void binary_to_text(const char *binary, char *text)
{
  //base case
  if (*binary == '\0') return;

  // convert binary byte and recall function
  *text = binary_to_ascii(binary);
  binary_to_text(binary+8,text+1);
}

int character_to_integer(char ch)
{
  // If character is not numeric return -1
  if (!isdigit(ch)) return -1;

  // Return integer representation numerical character
  return (int)(ch - '0');
}

char parity(char a, char b, char c, char d)
{
  char string[5] = {a,b,c,d,'\0'};
  int i(0), sum(0), integer;

  do {
    integer = character_to_integer(string[i]);
    if (integer == -1){
      cerr << "Error in parity function with character: "
	   << string[i] << endl;
    }
    sum += integer;
    i++;
  } while (string[i] != '\0');

  return (char)('0' + sum%2);
  
}

void add_error_correction(const char *data, char *correct)
{
  char c1, c2, d1, c3, d2, d3, d4;
  
  // base case
  if (*data == '\0'){
    *correct = '\0';
    return;
  }

  // define d1-d4 given memory accessible
  d1 = data[0];
  d2 = data[1];
  d3 = data[2];
  d4 = data[3];

  //calculate parity bits
  c1 = parity(d1,d2,d4);
  c2 = parity(d1,d3,d4);
  c3 = parity(d2,d3,d4);

  //add parity and normal bits to correct
  *correct = c1;
  *(correct+1) = c2;
  *(correct+2) = d1;
  *(correct+3) = c3;
  *(correct+4) = d2;
  *(correct+5) = d3;
  *(correct+6) = d4;
  
  //recursive call
  add_error_correction(data+4,correct+7);
}

int decode(const char *received, char *decoded)
{
  int errorPosition;
  char currentDecoded[8], binary[9] ="00000";
  char b1, b2, b3, b4, b5, b6, b7, p1, p2, p3;

  //base case
  if (*received == '\0'){
    *decoded = '\0';
    return 0;
  }

  //define b1 - b7
  b1 = received[0];
  b2 = received[1];
  b3 = received[2];
  b4 = received[3];
  b5 = received[4];
  b6 = received[5];
  b7 = received[6];

  //compute p1 - p3
  p1 = parity(b4,b5,b6,b7);
  p2 = parity(b2,b3,b6,b7);
  p3 = parity(b1,b3,b5,b7);
  
  //create current docoded
  strncpy(currentDecoded,received,7);

  //if error compute bit position
  binary[5] = p1;
  binary[6] = p2;
  binary[7] = p3;
  errorPosition = binary_to_ascii(binary) - 1;
  
  //flip binary bit in given position
  if (errorPosition != -1){
    if (currentDecoded[errorPosition] == '0') currentDecoded[errorPosition] = '1';
    else if (currentDecoded[errorPosition] == '1') currentDecoded[errorPosition] = '0';
    else cerr << "Error in binary received" << endl;
  }
  
  //add bits to decoded
  decoded[0] = currentDecoded[2];
  decoded[1] = currentDecoded[4];
  decoded[2] = currentDecoded[5];
  decoded[3] = currentDecoded[6];

  // reccursive call for error and no erro case
  if (errorPosition == -1) return decode(received+7,decoded+4);
  return decode(received+7,decoded+4) + 1;
}

