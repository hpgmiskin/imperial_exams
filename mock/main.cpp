#include <iostream>
#include <fstream>

using namespace std;

#include "shrink.h"

int main() {

  const char *dictionary[] = { "iguana", "aardvark", "swimming", "Zambezi", "river", "rescue" , "" };

  int word;

  cout << "====================== Question 1 ======================" << endl;

  word = lookup("aardvark", dictionary);
  cout << "The word 'aardvark' is ";
  if (word == -1)
    cout << "NOT";
  else
    cout << "word " << word;
  cout << " in the dictionary" << endl;
    
  word = lookup("hyena", dictionary);
  cout << "The word 'hyena' is ";
  if (word == -1)
    cout << "NOT";
  else
    cout << "word " << word;
  cout << " in the dictionary" << endl;

  word = lookup("Zambia", dictionary);
  cout << "The word 'Zambia' is ";
  if (word == -1)
    cout << "NOT";
  else
    cout << "word " << word;
  cout << " in the dictionary" << endl;

  word = lookup("river", dictionary);
  cout << "The word 'river' is ";
  if (word == -1)
    cout << "NOT";
  else
    cout << "word " << word;
  cout << " in the dictionary" << endl;

  cout << endl;

  cout << "====================== Question 2 ======================" << endl;

  char compressed[100];

  encode("aardvark", compressed, dictionary);
  cout << "'aardvark' compressed is '" << compressed << "'" << endl;

  encode("Zambezi", compressed, dictionary);
  cout << "'Zambezi' compressed is '" << compressed << "'" << endl;

  encode("hyena", compressed, dictionary);
  cout << "'hyena' compressed is '" << compressed << "'" << endl;

  encode("05", compressed, dictionary);
  cout << "'05' compressed is '" << compressed << "'" << endl;

  cout << endl;

  return 0;
}
