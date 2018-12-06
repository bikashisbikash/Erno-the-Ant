#include "Erno.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Implementation of the Erno game.

// Constructor function simply resets the board
    Erno::Erno(){
      reset();
    }
void Erno::printMoveCount(){
  cout << "Number of moves made: " << Erno::moveCount << endl;
}

bool Erno::moveErno (char direction){
    bool  returnValue = false;
      switch (direction){
        case 'N':
        case 'n':
          moveCount++;
          returnValue = move_N();
          break;
        case 'S':
        case 's':
          returnValue = move_S();
          moveCount++;
          break;
        case 'E':
        case 'e':
          returnValue = move_E();
          moveCount++;
          break;
        case 'W':
        case 'w':
          returnValue = move_W();
          moveCount++;
          break;
        case '.':
          cout << "End of the path." << endl;
          moveCount++;
          break;
        default:
          std::cerr << "/* error message */" << '\n';
          cout << "Invalid direction (" << direction << ") in move()!!\n\n";
          returnValue = false;
          exit(1);
       }  // end of switch
       if(returnValue == false)
        exit(1);
      return returnValue;
}

bool Erno::move_N (){
  if(Erno::row!=0){
    cout << "Moving North." << endl;
    Erno::row--;
    world[Erno::row][Erno::col] = 1;
    return true;
  }else{
    std::cerr << "/* error message */" << '\n';
    cout << "Can't move North anymore." << endl;
    return false;
  }
}
bool Erno::move_S (){                                  // Move South
  if(Erno::row!=WORLD_SIZE*2){
    cout << "Moving South." << endl;
    Erno::row++;
    world[Erno::row][Erno::col] = 1;
    return true;
  }else{
    std::cerr << "/* error message */" << '\n';
    cout << "Can't move South anymore" << endl;
    return false;
  }
}
bool Erno::move_W (){                                  // Move West
  if(Erno::col!=0){
    cout << "Moving West." << endl;
    Erno::col--;
    world[Erno::row][Erno::col] = 1;
    return true;
  }else{
    std::cerr << "/* error message */" << '\n';
    cout << "Can't move West anymore." << endl;
    return false;
  }
}
bool Erno::move_E (){                                  // Move East
  if(Erno::col!=2*WORLD_SIZE){                         // if posiible moves Erno one step east
    cout << "Moving East." << endl;                    // and returns true
    Erno::col++;                                       // returns false
    world[Erno::row][Erno::col] = 1;
    return true;
  }else{
    std::cerr << "/* error message */" << '\n';
    cout << "Can't move East anymore." << endl;
    return false;
  }
}

void Erno::printLocation() const{
  cout << "Erno is at: " << row+1 << ", " << col+1 << endl; // prints the current location of the Erno
}

int Erno::getUniqueLocations() const{                       // returns the number of UNIQUE locations visited
      int row, col, count=0;
      for(int row = 0; row <= 2 * WORLD_SIZE; row++){
        for(int col = 0; col <= 2 * WORLD_SIZE; col++){
          if(world[row][col] == 1)
            count++;
        }
      }
    return count;
}

void Erno::printWorld() const{                             // for debugging, prints the world
  int  row, col;
  cout << "\n\nCurrent world:\n";

  for (row = 0; row <= 2 * WORLD_SIZE;  row ++)
    {
    for (col = 0; col <= 2 * WORLD_SIZE;  col ++)
      cout << setw(3) << world [row][col];
    cout << endl;
    }
  cout << endl << endl;
}

void Erno::reset()	{                                       // resets the world for a new game
  int  row, col;

  for (row = 0; row <= 2 * WORLD_SIZE;  row ++)
    for (col = 0; col <= 2 * WORLD_SIZE;  col ++)
      world [row][col] = 0;
  Erno::row = WORLD_SIZE;		       	//  Poor practice, but I used the names "row" and "col" both locally and at the class level
  Erno::col = WORLD_SIZE;		       	//	Therefore I need to resolve the variables when referring to the class level variables
  world [WORLD_SIZE][WORLD_SIZE] = 1;
  moveCount = 0;
}
