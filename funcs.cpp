#include <iostream>
#include "funcs.h"
#include <cctype>
#include <sstream>
#include <fstream>
#include <string>

std::string removeLeadingSpaces(std::string line){
  std::string result = "";
  char current;
  bool leadflag = false; //True once done with leading spaces
  for(int i = 0; i < line.size(); i++){
    current = line[i];
    
    if(!isspace(current)){ //Not a space
      leadflag = true;
    }

    
    if(isspace(current) && !leadflag){ //Flag not hit, is a space
      continue;
    }
    else{ //Flag is hit or isn't a space
      result += current;
    }
  }
  return result;
}

int countChar(std::string line, char c){
  int count = 0;
  for(int i = 0; i < line.size(); i++){
    if(line[i] == c){
      count += 1; 
    }
  }
  return  count;
}

void formatCode(std::string inputname){
  std::ifstream fin(inputname);
  std::ofstream output;
  output.open("output.cpp");

  std::string line; //To hold each line
  std::string tabstring; //To hold the indentation
  int bracenum = 0; //Block depth
  
  if (fin.fail()) {
    std::cerr << "File cannot be opened for reading." << std::endl;
    exit(1); // exit if failed to open the file
  }
  
  getline(fin,line);
  while(line != ""){
    line = removeLeadingSpaces(line);

    bracenum -= countChar(line,'}');
    for(int i = 0; i < bracenum; i++){
      tabstring += "\t";
    }
    bracenum += countChar(line,'{');

    std::cout << tabstring << line << '\n';
    //output << tabstring << line << '\n';
    tabstring = "";
    getline(fin,line);
  }
  fin.close();
  output.close();
}
