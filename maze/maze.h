/* You are pre-supplied with the functions below. Add your own 
   function prototypes to the end of this file. */

/* helper functions to allocate and deallocate dynamic 2D arrays */
char **allocate_2D_array(int rows, int columns);
void deallocate_2D_array(char **m, int rows);

/* pre-supplied function to load a maze from a file */
char **load_maze(const char *filename, int &height, int &width);

/* pre-supplied function to print a maze */
void print_maze(char **m, int height, int width);

// check move checks the current step and updated row and col 
bool check_move(char **m, int height, int width, char dir, int &row, int &col);

// find marker looks for the given marker and returns true if found
bool find_marker(char ch, char **m, int height, int width, int &row, int &col);

// valid_solution checks the given solution to check its valid and returns
// false if it is not valid
bool valid_solution(const char *path, char **maze, int height, int width);

// recursive_path finds a path form the given position to the end
bool recursive_path(char **m, int height, int width, int &row, int &col, char* path, char end);

// find path finds a path through the maze using a recursive helper function
const char* find_path(char **m, int height, int width, char start, char end);
