/*
  Implimentation File for Braile
*/

#include "braille.h"

#include <cstring>
#include <iostream>
#include <map>
#include <string>
using namespace std;

const char* lookup_character(char ch)
{
  map<char,string> database;

  database['a'] = "0.....";
  database['b'] = "00....";
  database['c'] = "0..0..";
  database['d'] = "0..00.";
  database['e'] = "0...0.";
  database['f'] = "00.0..";
  database['g'] = "00.00.";
  database['h'] = "00..0.";
  database['i'] = ".0.0..";
  database['j'] = ".0.00.";
  database['k'] = "0.0...";
  database['l'] = "000...";
  database['m'] = "0.00..";
  database['n'] = "0.000.";
  database['o'] = "0.0.0.";
  database['p'] = "0000..";
  database['q'] = "00000.";
  database['r'] = "000.0.";
  database['s'] = ".000..";
  database['t'] = ".0000.";
  database['u'] = "0.0..0";
  database['v'] = "000..0";
  database['w'] = ".0.000";
  database['x'] = "0.00.0";
  database['y'] = "0.0000";
  database['z'] = "0.0.00";

  database['.'] = ".0..00";
  database[','] = ".0....";
  database[';'] = ".00...";
  database['-'] = "..0..0";
  database['!'] = ".00.0.";
  database['?'] = ".00..0";
  database['('] = ".00.00";
  database[')'] = ".00.00";
  
  return  database[ch].c_str();
}

int encode_character(char ch, char braille[])
{
  int size = 0;

  strcpy(braille,"");
  //if uppercase add uppercase captal sign and convert to lowercase
  if (isupper(ch))
    {
      strcat(braille,".....0");
      ch = tolower(ch);
    }
  //if digit add number sign and convert to letter equivilent
  else if (isdigit(ch))
    {
      strcat(braille,"..0000");
      if (ch == '0') ch = 'j';
      else ch = (char)((int)ch + ((int)'a' - (int)'1'));
    }

  //lookup braille character and add to braille string
  const char* brailleCharacter = lookup_character(ch);
  strcat(braille,brailleCharacter);

  //compute size of braille string
  for (size = 0 ;braille[size] != '\0' ;++size);

  return size;
}

void encode(const char* plaintext, char braille[])
{
  char currentBraille[20];
  
  //base case
  if (*plaintext == '\0') return;

  //find current craille code and add to result
  encode_character(*plaintext,currentBraille);
  strcat(braille,currentBraille);

  //recursive call for next letter
  encode(plaintext+1,braille);
}

void print_braille(const char* plaintext, ostream& output)
{
  int i,size;
  char currentBraille[20];

  //find maximum possible braille size from plaintext
  for (size = 0; plaintext[size] != '\0'; size++);
  size *= 12;

  //dynamically assign character array and compute actual size when encoded
  char* braille = new char[size];
  encode(plaintext,braille);
  for (size = 0; braille[size] != '\0'; size++);

  //loop through dot positions 1 and 4 for all letter adding a space after and 4 dot 
  for (int i=0; i<size; i += 3){
    cout << braille[i];
    if (i%2) cout << " ";
  }
  cout << endl;

  //loop through dot positions 2 and 5 for all letters adding a space adter any 5 dot
  for (int i=1; i<size; i += 3){
    cout << braille[i];
    if (!(i%2)) cout << " ";
  }
  cout << endl;

  //loop through dot positions 3 and 6 for all letters adding a space adter any 6 dot
  for (int i=2; i<size; i += 3){
    cout << braille[i];
    if (i%2) cout << " ";
  }
  cout << endl;

  //delete memory off the heap
  delete [] braille;

  //loop through all plaintext
  i = 0;
  do {
    //compute size of braille for this character
    size = encode_character(plaintext[i],currentBraille);

    //print plaintext accoring to size
    if (size == 12) output << "   ";
    output << plaintext[i] << "  ";

    i++;
  } while (plaintext[i] != '\0');

  output << endl;
  
}
