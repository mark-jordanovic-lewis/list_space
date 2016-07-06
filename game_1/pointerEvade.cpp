// a four by four block, no player or hunter, simply displayed, as it grows.

#include "pointerSpace.h"
#include <ctime>

using namespace std ;

int main(int argv, char * argc[])
{
  srand(time(NULL)) ;
  bool unstable = true ;
  int worldSize = 4 ;
  pointerSpace testbed(worldSize) ;
  while(unstable){    
    list<list::iterator> blocks = testbed.addresses() ;
    
  }
}





  // nb make a minecraft style thing with this. the type of block can be defined by the way it evolves and interacts with
  // blocks out side of its boundary... nice world regeneration thingy, right?
