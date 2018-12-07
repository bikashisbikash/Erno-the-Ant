//
//   Erno.h file
//

#ifndef ERNO_H
#define ERNO_H

const int WORLD_SIZE = 15;

class Erno{
  public:
          Erno();
    void printMoveCount();
    bool  moveErno (char direction);  // given a direction (NSWE) determines which private function needs to be called
					// also checks for a valid character.
					// returns true if move can be made
    int   getUniqueLocations() const;	// returns the number of unique locations visited
    void  printWorld() const;		// for debugging, prints the world
    void  printLocation() const;	// for debugging, prints the current location
    void  reset();		// resets the world for a new game; zeros out the board, puts Erno in the middle,
				// 		and sets the counter for the middle location to one

  private:
    int row, col; 	// current position
    int moveCount;	// the number of moves made, (not currently used)
    int world [2*WORLD_SIZE+1][2*WORLD_SIZE+1];

    bool  move_N ();	// makes the move North, checking erno doesn't fall off the world.  Returns true if move can be made
    bool  move_S ();  	// ditto South, ditto
    bool  move_W ();	// ditto West
    bool  move_E ();	// ditto East
 };

#endif
