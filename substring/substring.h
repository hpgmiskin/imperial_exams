/*
Substring header file
 */

/*
is prefix returns true if the first string is fully contained in the second
true if the first string is empty
 */
bool is_prefix(const char* substring, const char* string);

/*
substring position returns the position of a substring in a sentence
The returned intger takes the value of the position of the start of the substring
If the substring is not present then the value -1 is returned
 */
int substring_position(const char* substring, const char* string);
