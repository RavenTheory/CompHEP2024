#include <string>
#include <vector>
#include <iostream>

#include <regex>

#include <stdlib.h>

int main(){
  std::vector<std::string> data; // container
  data.push_back("qwerty");
  data.push_back("asdfgh");
  data.push_back("zxcvbn");
  data.push_back("xcvbn");

  std::string re_str = ".+xc.*"; // regex
  std::regex example_re(re_str);
  std::cout << "regex search pattern " << re_str << std::endl;

  std::vector<std::string>::const_iterator i; //iterator
  for(i = data.begin(); i!=data.end(); ++i){
    if (std::regex_match(*i,example_re)) std::cout << "string " << *i << " \x1B[32mmatches\033[0m" << std::endl; // colored output
    else std::cout << "string " << *i << " \x1B[31mdoes not match\033[0m" << std::endl;
  }
}

