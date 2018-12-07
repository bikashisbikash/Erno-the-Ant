//
//Test file
//
//Terminal Comands:
//  g++ Erno.cc testErno.cc
//  ./a.out
//

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include "Erno.h"
#include <string>

using namespace std;

int main(){
  Erno ERNO;
  ifstream INFILE;
  INFILE.open("/Users/bikash/Documents/Computer Programming/Erno-the-Ant/direction.txt", ios::in);
  if(!INFILE){
    std::cerr << "error message " << '\n' << "Unable to open the file!" << endl;
    exit(1);
  }
  char x;
  while(INFILE>>x){
    ERNO.Erno::printWorld();
    ERNO.Erno::printMoveCount();
    cout<<"Unique locations visited: " << ERNO.Erno::getUniqueLocations()<< endl;
    ERNO.Erno::printLocation();
    ERNO.Erno::moveErno(x);

  }
  INFILE.close();
  return 0;
}
