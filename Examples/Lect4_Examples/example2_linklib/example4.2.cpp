#include "MyLib.h"

int main(int argc, char *argv[]){
  MyLib* myObj = new MyLib;
  for(int i = 0; i < argc; ++i){
    myObj->print("Command line parameters " + std::string(argv[i]));
  }
}
