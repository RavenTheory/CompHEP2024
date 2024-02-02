#include "MyLib.h"
#include <iostream>

MyLib::MyLib(){}
MyLib::~MyLib(){}

void MyLib::print(std::string message){
  std::cout << message << std::endl;
}
