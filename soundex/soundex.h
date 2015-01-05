/*
Soundex Header File
 */

/*
lookup returns the soundex code for the given character or 0 if no code exists
 */
int lookup(const char character);

/*
encode takes a surname and converts it to a soundex encoding
 */
void encode(const char* surname, char soundex[5]);

/*
compare compares two soundex encodings recusively
Returns 1 if the same and 0 otherwise
 */
int compare(const char* one, const char* two);

/*
count counts the number of words in sentence that share a soundex encoding with surname
Returns the count of encodings which are the same
 */
int count(const char* surname, const char* sentence);
