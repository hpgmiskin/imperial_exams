#include <fstream>
using namespace std;

// RESET is a constant used by function rhyming_letter(...)
#define RESET NULL

/* get_word(...) retrieves a word from the input string input_line
   based on its word number. If the word number is valid, the function
   places an uppercase version of the word in the output parameter
   output_word, and the function returns true. Otherwise the function
   returns false. */

bool get_word(const char *input_line, int number, char *output_word);

/* char rhyming_letter(const char *ending) generates the rhyme scheme
   letter (starting with 'a') that corresponds to a given line ending
   (specified as the parameter). The function remembers its state
   between calls using an internal lookup table, such that subsequents
   calls with different endings will generate new letters.  The state
   can be reset (e.g. to start issuing rhyme scheme letters for a new
   poem) by calling rhyming_letter(RESET). */

char rhyming_letter(const char *ending);

//is_vowel returns true if the given character is a vowel
bool is_vowel(char ch);

//has_vowel returns true if the given word contains a vowel
bool has_vowel(const char* word);

//open_file takes a filename and reference ifstream, if file found ifstream
//set and true returned
bool open_file(const char* filename, ifstream &input);

//count words counts the number of words in a line
int count_words(const char* sentence);

// find_phonic ending uses dictionary.txt to find the phonic ending of the
// given word
bool find_phonetic_ending(const char* word, char* ending);

// find_rhyme scheme finds the rhyming scheme in the given file returns false
// if the file does not exist
bool find_rhyme_scheme(const char* filename, char* scheme);

// identify sonnet takes the given filename and identifies the sonnet contained
const char* identify_sonnet(const char* filename);
