/*
Header file for words
 */

/*
  reverse takes two arguments string1 and stirng2
  string1 is vreversed and set as string2
 */
void reverse(const char* word, char reversed[]);

/*
  compare compares two strings to see if the alpha characters are the same
  regardless of the case and any spaces or punctionation
  return 1 if the strings are the same and 2 otherwise
*/
int compare(const char* one, const char* two);

/*
  palindrome asseses if a given string is a palindrome
  returns 1 if it is a palindrome and 0 otherwise
*/
int palindrome(const char* sentence);

/*
  compare compares two characters independent of case
  returns 1 if one is before two in the alphabet or if one is a letter and two is not
  returns 0 if two is before one in the alphabet or if two is a letter and one is not
 */
int compare(char one, char two);

/*
  sort sorts the given string case insensetively
  sorted is updated as the sorted version of the string
 */
void sort(char string[]);

/*
  anagram asseses if the two given strings are anagrams of one and other
  returns 1 if one is an anagram of the other and 0 otherwise
 */
int anagram(const char* one, const char* two);
