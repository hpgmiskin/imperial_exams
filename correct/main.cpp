#include <iostream>
#include <cstring>
#include "correct.h"

using namespace std;

void test()
{
  cout << character_to_integer('2') << endl;
  cout << character_to_integer('9') << endl;

  cout << parity('1','1','1') << " = odd = 1" << endl;
  cout << parity('1','1','1') << " = odd = 1" << endl;
  cout << parity('1','0','1') << " = even = 0" << endl;

  cout << parity('1','1','1','1') << " = even = 0" << endl;
  cout << parity('1','1','0','1') << " = odd = 1" << endl;
}

int main() {

  cout << "==== TEST ====" << endl;

  test();
  
  /* this section illustrates the use of the pre-supplied helper functions */
  cout << "================== Helper functions ====================" << endl << endl;

  char binary[9];

  ascii_to_binary('A',binary);
  cout << "The ASCII code of 'A' is " << int('A') << " which in binary is " << binary << endl;

  ascii_to_binary('r',binary);
  cout << "The ASCII code of 'r' is " << int('r') << " which in binary is " << binary << endl;

  ascii_to_binary('t',binary);
  cout << "The ASCII code of 't' is " << int('t') << " which in binary is " << binary << endl << endl;

  char ch;
  ch = binary_to_ascii("01000001");
  cout << "The character correspoding to the binary number 01000001 is '" << ch << "'" << endl << endl;

  cout << "====================== Question 1 ======================" << endl << endl;
  
  char encoded[512], text[32];

  text_to_binary("Art",encoded);
  cout << "'Art' encoded as binary is " << encoded << endl << endl;

  binary_to_text("010000010111001001110100", text);
  cout << "010000010111001001110100 decoded as text is '" << text << "'" << 
endl << endl;

  cout << "====================== Question 2 ======================" << endl << endl;

  char correct[512]; 
  add_error_correction("0100", correct);
  cout << "0100" << " with error correction bits inserted is: " << endl << correct << endl << endl;

  add_error_correction("0001", correct);
  cout << "0001" << " with error correction bits inserted is: " << endl << correct << endl << endl;

  add_error_correction("010000010111001001110100", correct);
  cout << "010000010111001001110100 with error correction bits inserted is: " << endl << correct << endl << endl;

  cout << "====================== Question 3 ======================" << endl << endl;

  char decoded[512];
  int errors = 0;

  strcpy(correct,"1001100");  
  errors = decode(correct, decoded);
  cout << correct << " decoded is " << decoded << " (" << errors << " errors corrected)" << endl << endl;  

  strcpy(correct,"1001110");  
  errors = decode(correct, decoded);
  cout << correct << " decoded is " << decoded << " (" << errors << " errors corrected)" << endl << endl;  
                         
  strcpy(correct,"100111011010010001110010101000011011001100");  
  errors = decode(correct, decoded);
  cout << correct << " decoded is:" << endl << decoded << " (" << errors << " errors corrected)" << endl;  
  binary_to_text(decoded, text);
  cout << "which as text is '" << text << "'" << endl << endl;  

  /* but can you decode this? you can only do it if you do what it says */
  strcpy(correct,"00011000001001010001000001001100110011010011101101111110000101111001101100110010010101010100000000100110010000110101010011001101010100110011");
  errors = decode(correct, decoded);
  cout << correct << " decoded is:" << endl << decoded << " (" << errors << " errors corrected)" << endl;  
  binary_to_text(decoded, text);
  cout << "which as text is '" << text << "'" << endl << endl;  

  cout << "======================= The End ========================" << endl << endl;

}
