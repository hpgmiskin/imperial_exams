#ifndef CORRECT_H
#define CORRECT_H

void ascii_to_binary(char letter, char *output);
char binary_to_ascii(const char *binary);

/*
  Question 1
*/

// Convert constant text input to binary
void text_to_binary(const char *text, char *binary);

// Convert constant binry input to text
void binary_to_text(const char *binary, char *text);

/*
  Question 2
 */

// Returns the integer of any numeric character else returns -1
int character_to_integer(char ch);

// Computes the parity of 3 or 4 characters
char parity(char a, char b, char c, char d = '0');

// Add error correction digits to data
void add_error_correction(const char *data, char *correct);

/*
  Question 3
*/

// Decode recieved stream and correct errors
int decode(const char *received, char *decoded);

#endif
