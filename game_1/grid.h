// CHANGE ALL LISTS TO VECTORS TO ALLOW FOR EASY ASSIGNS, THIS IS V ANNOYING

#include <iostream>
#include <fstream>
#include <cmath>
#include <ctime>
#include "../list_space/pointerSpace.h"

class grid{
 private:
  std::list<std::list<point>> Grid ;                  // the attempted 2d grid
  std::list<std::list<std::list::iterator>> staticPoints ;          // this holds the currently held grid points that cannot change, returned in get grid when all points are static
  std::list<std::list::iterator> north, east, south, west ;         // the lists surrounding the currently investigated list
  std::list<std::list::iterator> position ;                         // the currently investigated list
  std::list::iterator direction ;                                   // pointing at either north, south, east or west
 public:
  void grid() ;                                                     // initiates Grid.
  int buildGrid() ;                                                 // this builds the grid
  std::list<std::list<std::list::iterator>> getGrid() ;             // returns the completed grid
}

typedef struct piece{                 //Self points at the position in grid that it exists in.
  std::list<std::list<piece>>::iterator Self, North, South, East, West ; // now we have to change grid to reflect that contains these points, not list iterators.
  int staticness = 0 ;
  int friendliness = 0 ;
  int Nhist = 0, Shist = 0, Ehist = 0, Whist = 0 ;   // the length of the history of the directions, upon shun must be reset to zero.
}
