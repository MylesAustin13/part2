#include <iostream>
#include "funcs.h"

int main(){

  std::string test = removeLeadingSpaces("       int x = 1;  ");
  std::cout << test << std::endl;
  int counttest = countChar("int main(){ ",'{');
  std::cout << counttest <<std::endl;
  formatCode("bad-code.cpp");
  //formatCode("~/src/bad-code.cpp");
  return 0;
}
