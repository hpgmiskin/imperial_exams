#include <iostream>
#include <cstring>
#include <cctype>
#include <cassert>
#include <map>
#include <string>

using namespace std;

#include "sonnet.h"

/* PRE-SUPPLIED HELPER FUNCTIONS START HERE */

/* NOTE: It is much more important to understand the interface to and
   the "black-box" operation of these functions (in terms of inputs and
   outputs) than it is to understand the details of their inner working. */

/* get_word(...) retrieves a word from the input string input_line
   based on its word number. If the word number is valid, the function
   places an uppercase version of the word in the output parameter
   output_word, and the function returns true. Otherwise the function
   returns false. */

bool get_word(const char *input_line, int word_number, char *output_word) {
  char *output_start = output_word;
  int words = 0;

  if (word_number < 1) {
    *output_word = '\0';
    return false;
  }
  
  do {
    while (*input_line && !isalnum(*input_line))
      input_line++;

    if (*input_line == '\0')
      break;

    output_word = output_start;
    while (*input_line && (isalnum(*input_line) || *input_line=='\'')) {
      *output_word = toupper(*input_line);
      output_word++;
      input_line++;
    }
    *output_word = '\0';

    if (++words == word_number)
      return true;

  } while (*input_line);

  *output_start = '\0';
  return false;
}

/* char rhyming_letter(const char *ending) generates the rhyme scheme
   letter (starting with 'a') that corresponds to a given line ending
   (specified as the parameter). The function remembers its state
   between calls using an internal lookup table, such that subsequents
   calls with different endings will generate new letters.  The state
   can be reset (e.g. to start issuing rhyme scheme letters for a new
   poem) by calling rhyming_letter(RESET). */

char rhyming_letter(const char *ending) {

  // the next rhyming letter to be issued (persists between calls)
  static char next = 'a';
  // the table which maps endings to letters (persists between calls)
  static map<string, char> lookup;

  // providing a way to reset the table between poems
  if (ending == RESET) {
    lookup.clear();
    next = 'a';
    return '\0';
  }

  string end(ending);

  // if the ending doesn't exist, add it, and issue a new letter
  if (lookup.count(end) == 0) {
    lookup[end]=next;
    assert(next <= 'z');
    return next++;
  }

  // otherwise return the letter corresponding to the existing ending
  return lookup[end];
}

//is_vowel returns true if the given character is a vowel
bool is_vowel(char ch)
{
  int i = 0;
  const char vowels[7] = "AEIOUY";

  if (!isalpha(ch)) return false;

  do {
    if (toupper(ch) == vowels[i]) return true;
    i++;
  } while (vowels[i] != '\0');

  return false;
}

//has_vowel returns true if the given word contains a vowel
bool has_vowel(const char* word)
{
  int i = 0;

  if (!strlen(word)) return false;

  do {
    if (is_vowel(word[i])) return true;
    i++;
  } while (word[i] != '\0');

  return false;
}

//open_file takes a filename and reference ifstream, if file found ifstream
//set and true returned
bool open_file(const char* filename, ifstream &input)
{
  input.open(filename);
  return input.is_open();
}

//count words counts the number of words in a line
int count_words(const char* sentence)
{
  char word[20];
  int i = 1;

  while (get_word(sentence,i,word)) i++;

  return i-1;
}

// find_phonic ending uses dictionary.txt to find the phonic ending of the
// given word
bool find_phonetic_ending(const char* word, char* ending)
{
  int wordNumber, lastPhonic;;
  bool success;
  char line[256], testWord[20];
  ifstream input;

  if (!open_file("dictionary.txt",input)) return false;
  
  while (!input.eof()){
    input.getline(line,256);
    get_word(line,1,testWord);
    if (input.fail()) continue;
    if (!strcmp(word,testWord)) break;
  }

  if (input.eof()) return false;
  input.close();

  wordNumber = 1;
  do {
    success = get_word(line,wordNumber,testWord);
    //cout << wordNumber << testWord << has_vowel(testWord) << endl;
    if (has_vowel(testWord)) lastPhonic = wordNumber;
    wordNumber++;
  } while (success);

  wordNumber = lastPhonic;
  strcpy(ending,"");
  do {
    success = get_word(line,wordNumber,testWord);
    strcat(ending,testWord);
    wordNumber++;
  } while (success);

  return true;
}

// find_rhyme scheme finds the rhyming scheme in the given file returns false
// if the file does not exist
bool find_rhyme_scheme(const char* filename, char* scheme)
{
  int i(0), wordCount;
  ifstream input;
  char line[1000], word[100], ending[20];

  if (!open_file(filename,input)) return false;
  
  rhyming_letter(RESET);

  do {
    input.getline(line,1000);
    wordCount = count_words(line);
    if (!get_word(line,wordCount,word)) break;
    if (!find_phonetic_ending(word,ending)) cout << "No Dict" << endl;
    scheme[i] = rhyming_letter(ending);

    //cout << line << " - " << word << " - " <<  ending << " - " << scheme[i] << endl;    

    i++;
  } while (!input.fail());
  input.close();

  scheme[i] = '\0';

  return true;
}

// identify sonnet takes the given filename and identifies the sonnet contained
const char* identify_sonnet(const char* filename)
{
  char scheme[100];

  if (!find_rhyme_scheme(filename,scheme)) cerr << "File not found" << endl;

  if (!strcmp(scheme,"ababcdcdefefgg")) return "Shakespearean";
  if (!strcmp(scheme,"abbaabbacdcdcd")) return "Petrarchan";
  if (!strcmp(scheme,"ababbcbccdcdee")) return "Spenserian";

  return "Unknown";
}
