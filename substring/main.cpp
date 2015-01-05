#include <iostream>
#include "substring.h"

using namespace std;

int test() 
{
  cout << " ==== Test ====" << endl;
  cout << is_prefix("hello","hello world") << endl;
  cout << is_prefix("not","this is not correct") << endl;
  cout << is_prefix("","this could be anythin") << endl;
  cout << is_prefix(" ","grhrhg") << endl;
  cout << is_prefix("","") << endl;
}

int main() {

  test();

  cout << " ==== Main ====" << endl;
  cout << substring_position("this", "this is a simple exercise") << endl;
  cout << substring_position("is", "this is a simple exercise") << endl;
  cout << substring_position("is a", "this is a simple exercise") << endl;
  cout << substring_position("is an", "this is a simple exercise") << endl;
  cout << substring_position("exercise", "this is a simple exercise") << endl;
  cout << substring_position("simple exercise", "this is a simple") << endl;
  cout << substring_position("", "this is a simple exercise") << endl;
  cout << substring_position("", "") << endl;
  return 0;
}
