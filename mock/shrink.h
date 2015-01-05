/*
Header File
 */

/*
Lookup looks for the word word in the given dictionary
If the word is located in the dictionary the position is returned as an integer
If the word is not located in the dictionary -1 is returned
 */
int lookup(const char* word, const char* dictionary[]); 

/*
Encode encodes the given word to shortened form if there is a dictionary entry
If the word given is a number then the number is prefixed with !
If the word is not in the dictionary the word is returned unchanged
If the word is in the dictionary the shorted two digit version is returned
 */
void encode(const char* word, char compressed[100], const char* dictionary[]);
