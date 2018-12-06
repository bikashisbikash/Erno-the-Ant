#include "Erno.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Implementation of the Erno game.

// Constructor function simply resets the board
    Erno::Erno(){
      reset();
    }

bool Erno::moveErno (char direction){
    bool  returnValue;
    moveCount ++;
    switch (direction){
    	case 'N':
    	case 'n':
    	    returnValue = move_N();
    	    break;
      case 'S':
      case 's':
          returnValue = move_S();
          break;
      case 'E':
      case 'e':
          returnValue = move_S();
          break;
      case 'W':
      case 'w':
          returnValue = move_W();
          break;
      default:
	        cerr << "Invalid direction (" << direction << ") in move()\n\n";
	        returnValue = false;
	   }  // end of switch
    return returnValue;
}

bool Erno::move_N (){
  if(Erno::row!=1){
      Erno::row = Erno::row-1;
      return true;
  }else
    return false;
}
bool  Erno::move_S (){
  if(Erno::row!=WORLD_SIZE*2+1){
      Erno::row = Erno::row+1;
      return true;
  }else
    return false;
}
bool  Erno::move_W (){
  if(Erno::col!=1){
    Erno::col = Erno::col-1;
    return true;
  }else
    return false;
}
bool  Erno::move_E (){
  if(Erno::col!=2*WORLD_SIZE+1){
    Erno::col=Erno::col+1;
    return true;
  }else
    return false;
}

void  Erno::printLocation() const{
  cout << "Erno is at: " << row << ", " << col << endl;
}

int   Erno::getUniqueLocations() const{// returns the number of locations visited
    return -1;
}

void  Erno::printWorld() const{// for debugging, prints the world
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

void  Erno::reset()	{// resets the world for a new game
  int  row, col;

  for (row = 0; row <= 2 * WORLD_SIZE;  row ++)
    for (col = 0; col <= 2 * WORLD_SIZE;  col ++)
      world [row][col] = 0;
  Erno::row = WORLD_SIZE;			//  Poor practice, but I used the names "row" and "col" both locally and at the class level
  Erno::col = WORLD_SIZE;			//	Therefore I need to resolve the variables when referring to the class level variables
  world [WORLD_SIZE][WORLD_SIZE] = 1;
  moveCount = 0;
}
