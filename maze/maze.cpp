#include <iostream>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>

using namespace std;

/* You are pre-supplied with the functions below. Add your own 
   function definitions to the end of this file. */

/* helper function which allocates a dynamic 2D array */
char **allocate_2D_array(int rows, int columns) {
  char **m = new char *[rows];
  assert(m);
  for (int r=0; r<rows; r++) {
    m[r] = new char[columns];
    assert(m[r]);
  }
  return m;
}

/* helper function which deallocates a dynamic 2D array */
void deallocate_2D_array(char **m, int rows) {
  for (int r=0; r<rows; r++)
    delete [] m[r];
  delete [] m;
}

/* helper function for internal use only which gets the dimensions of a maze */
bool get_maze_dimensions(const char *filename, int &height, int &width) {
  char line[512];
  
  ifstream input(filename);

  height = width = 0;

  input.getline(line,512);  
  while (input) {
    if ( (int) strlen(line) > width)
      width = strlen(line);
    height++;
    input.getline(line,512);  
  }

  if (height > 0)
    return true;
  return false;
}

/* pre-supplied function to load a maze from a file*/
char **load_maze(const char *filename, int &height, int &width) {

  bool success = get_maze_dimensions(filename, height, width);
  
  if (!success)
    return NULL;

  char **m = allocate_2D_array(height, width);
  
  ifstream input(filename);

  char line[512];

  for (int r = 0; r<height; r++) {
    input.getline(line, 512);
    strcpy(m[r], line);
  }
  
  return m;
}

/* pre-supplied function to print a maze */
void print_maze(char **m, int height, int width) {
  cout << setw(4) << " " << " ";
  for (int c=0; c<width; c++)
    if (c && (c % 10) == 0) 
      cout << c/10;
    else
      cout << " ";
  cout << endl;

  cout << setw(4) << " " << " ";
  for (int c=0; c<width; c++)
    cout << (c % 10);
  cout << endl;

  for (int r=0; r<height; r++) {
    cout << setw(4) << r << " ";    
    for (int c=0; c<width; c++) 
      cout << m[r][c];
    cout << endl;
  }
}

// check move checks the current step and updated row and col 
bool check_move(char **m, int height, int width, char dir, int &row, int &col)
{
  bool success = true;
  int rowStep, colStep;
  char goodCh[5] = "> MX";

  // find the correct row and column step
  switch (dir){
  case 'N':
    rowStep = -1;
    colStep = 0;
    break;
  case 'E':
    rowStep = 0;
    colStep = 1;
    break;
  case 'S':
    rowStep = 1;
    colStep = 0;
    break;
  case 'W':
    rowStep = 0;
    colStep = -1;
    break;
  default:
    return false;
  }
  
  // move row and column by given steps
  row += rowStep;
  col += colStep;

  // check still within map bounds
  if ((row < 0) || (row >= height)) success = false;
  if ((col < 0) || (col >= width)) success = false;

  // if no issue thus far check allowable route character
  if (success){
    for (int i=0; i<4; i++){
      if (m[row][col] == goodCh[i]) return true;
    }
  }

  // no return means bad move therefore revert step
  row -= rowStep;
  col -= colStep;
  
  return false;
}

// find marker looks for the given marker and returns true if found
bool find_marker(char ch, char **m, int height, int width, int &row, int &col)
{
  // loop through all map positions, if marker found return true
  for (row = 0; row<height; row++){
    for (col = 0; col<width; col++){
      if (ch == m[row][col]) return true;
    }
  }

  row = col = -1;
  return false;
}

// valid_solution checks the given solution to check its valid and returns
// false if it is not valid
bool valid_solution(const char *path, char **maze, int height, int width)
{
  int i(0), row, col;

  //get start location
  if (!find_marker('>',maze,height,width,row,col)) return false;

  //loop through path
  do {
    if (!check_move(maze,height,width,path[i],row,col)) return false;
    i++;
  } while (path[i] != '\0');

  //return logic result of if the path ends at the end
  return (maze[row][col] == 'X');
}

// recursive_path finds a path form the given position to the end
bool recursive_path(char **m, int height, int width, int row, int col, char* path, char end)
{
  int tempRow, tempCol;
  char tempCh, directions[5] = {'N','E','S','W','\0'};
  
  //base case
  if (m[row][col] == end){
    m[row][col] = '#';
    *path = '\0';
    return true;
  }
    
  //loop directions
  for (int i = 0; i<4; i++){

    // save temporary values
    tempRow = row;
    tempCol = col;
    tempCh = m[row][col];

    // record route
    m[row][col] = '#';

    // check move allowavle then check onward route
    if (check_move(m,height,width,directions[i],row,col)){      
      if (recursive_path(m,height,width,row,col,path+1,end)){
	*path = directions[i];
	return true;
      }
    }

    //If no route revert temporary values
    row = tempRow;
    col = tempCol;
    m[row][col] = tempCh;
  }

  //if no direction exists return false
  return false;
}

// find path finds a path through the maze using a recursive helper function
const char* find_path(char **m, int height, int width, char start, char end)
{
  int row, col;
  static char path[1000] = {'\0'};

  if (!find_marker(start,m,height,width,row,col)) return "no solution";

  if (!recursive_path(m,height,width,row,col,path,end)) return "no solution";

  return path;
}
