#include "grid.h"

using namespace std ;
ofstream errors ;

void grid()
{
  srand(clock()) ;
  int gridEdge = 3 ;
  int gridArea = gridEdge*gridEdge ;
  pointerSpace Grid = new pointerSpace(gridArea) ;       // initiates the grid (should extend to gridX, gridY)
}
  
// rules for pieces:
//                   Edge:   points to two edge pieces and a bulk, or, a vertex, an edge and a bulk
//                   Vertex: points to two edge pieces
//                   Bulk:   points to an edge and three bulk, or, two edges and two bulk, or, four bulk, or, (in the smallest case, 3x3) four edge.

int buildGrid()
{
  errors.open("buildGridErrs.txt", "+w") ;
  list<list<piece>>::iterator pos = Grid.exist.begin();
  bool notBuilt = true ;
  int neighbour, posin_pos, _posinpos ;
  while(notBuilt){
    for(int i = 0 ; i < gridArea ; i++, pos++){                 //meet a neighbour. Posns:Direction. 1:N 2:E 3:W 4:S
      neighbour = rnd(9) ; 
      Grid.meet(pos, pos+neighbour) ;                            // safe because iterates from pos to pos+neighbour, wrapping round? chreck
    }

    // MAKE TEST OF 'STATICNESS' & 'FRIENDLINESS'
    // an existence is still friendly if it is not completely static (contained in the staticPoints list)
    // and it has less than 4 friends
    //
    // static 0 ; all things may change
    // --------------------------------
    //        a point with no type
    //
    // static 1; does not change edge friends, may make/exchange bulk friends
    // -----------------------------------------------------------------------------
    //        edge with static edge/vertex friends
    //        bulk with static edge friend(s)
    //
    // static 2, nothing changes, hold in staticPoints list
    // ----------------------------------------------------
    //        vertex with static edge friends
    //        edge with static edge and bulk friends
    //        bulk with 4 static friends
    // 

    for(pos = Grid.exist.begin() ; pos != Grid.exist.end() ; pos++){
      for(list<list<piece>>::iterator _pos = Grid.exist.begin() ; _pos != Grid.exist.end() ; _pos++){
	// check this, it needs a bit of a reconfigure. too tired right now.
	if(Grid.friendsWith(pos, _pos)){
	  posin_pos = Grid.findBinA(pos, _pos) ; //this shoudl return a value 1-4 if 0 or -1 then err.
	  _posinpos = Grid.findBinA(_pos, pos) ; 
	  if(posin_pos <= 5 && _posin_pos <= 5){
	    if(posin_pos <= 0 || _posinpos <= 0){
	      errors << "findBinA error : none existent" << endl ;
	      errors << "    posin_pos = " << posin_pos << endl ;
	      errors << "    _posinpos = " << _posinpos << endl ;
	    }
	  }
	  else{
	    errors << "findBinA error : outside range" << endl ;
	    errors << "    posin_pos = " << posin_pos << endl ;
	    errors << "    _posinpos = " << _posinpos << endl ;
	  }
	// we want to check their positons in each others list and shift them to compensate for relative position
	if(posin_pos == _posinpos){
	  if((*pos).size() == 4 && 
	  //if equal move to first possible directional opposites, or, next best possible config based on 2d grid, or, shun each other.
	  // we have a 1d integer space made of 1,2,3,4,1,2,3,4,etc
	
    }
  }  
}
