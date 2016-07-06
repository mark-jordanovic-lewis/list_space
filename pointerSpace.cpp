/* 
   This class is supposed to act as a base class for all other toy and real programs based upon things bound or iteracting with each other.
   There is no limit on the number of pointers which may be held in each existence. To have two separate spaces interating with each other must have wrapper class,
   probably call this interactionSpace (or something).
   All it is is a list of lists of pointers whose first members are pointing at itself, and methods to manipulate it.
   All lists are private and returned in the getters.
   There is a list of list<pointer>.begin()'s (npointers) returned in a get. This list corresponds to the initial conditions
   of the first elements in each of the lists of pointers held in the exist list.
*/

#include "pointerSpace.h"

using namespace std ;
// list<list::iterator> npointers ;
// list<list::iterator>::iterator n ;
// list<list<list::iterator>> exist ;

// CONSTRUCTOR

void pointerSpace::pointerSpace(int N)
{
  //point the first instance of birth at itself                     (birth is temp)
  //populate npointers with the start of each birthed existence
  //put it in existence
  for(int i = 0 ; i <= N ; i++){
    list<list::iterator> birth ;
    n = birth.begin() ;
    birth.push_back(n) ;
    npointers.push_back(n) ;
    exist.push_back(birth) ;
  }
  nExistences = exist.size() ;
  histories = 0 ;
}

// RETURN METHODS

list<list::iterator> pointerSpace::furthests()
{
  list<list::iterator> lasts ;
  list<list<list::iterator>>::iterator e ;
  for(e = exist.begin() ; e != exist.end() ; e++){
    ends.push_back((*e).last()) ;
  }
  return ends ;
}

list<list::iterator> pointerSpace::closest() // unless manipulated this will return the same as addresses()
{
  list<list::iterator> firsts ;
  list<list<list::iterator>>::iterator e ;
  for(e = exist.begin() ; e != exist.end() ; e++){
    firsts.push_back((*e).first()) ;
  }
  return firsts ;
}

list<list::iterator> pointerSpace::closests() ; // this should return the first friend (that is not self)
{
  list<list::iterator> seconds ;
  list<list<list::iterator>>::iterator e ;
  for(e = exist.begin() ; e != exist.end() ; e++){
    n = (*e).begin() ;
    n++ ;
    seconds.push_back((*n)) ;
  }
  return seconds ;
}

list<list<list::iterator>> pointerSpace::state() // this makes exist accessable, maybe dont need to return friends..its here anyway.
{
  histories ++ ;
  return exist ;
}

int pointerSpace::size()
{
  return nExitences ;
}

list<list::iterator> pointerSpace::addresses()
{
  return npointers ;
}

list<list::iterator> pointerSpace::myFriends(/*list<list<list::iterator>::iterator me*/int me)
{
  list<list<list::iterator>::iterator e = exist.begin() ; 
  for(int i = 0 ; i < me ; i++, e++){}
  return *e ;


// TEST METHODS

bool pointerSpace::friendsWith(list<list<list::iterator>>::iterator friend_1, list<list<list::iterator>>::iterator friend_2)
{
  if((*friend_1).contains(friend_2) && (*friend_2).contains(friend_1)) return true ;
  return false ;
}

int pointerSpace::findBinA(list<list<list::iterator>>::iterator A, list<list<list::iterator>>::iterator B)
{
  list<list::iterator>::iterator searcher = (*A).begin() ;
  int i = 0 ;
  for(searcher != (*A).end() ; searcher++, i++){
    if(*searcher == B) return i ;
    i++
  }
  return -1 ;
}

// MANIPULATION METHODS

int pointerSpace::shortenAll(int N)
{
  int n_smaller = 0 ;
  list<list<list::iterator>>::iterator e ;
  for(e = exist.begin() ; e != exist.end() ; e++){
    while((*e).size() > N) (*e).pop_back() ;
    if((*e).size() < N) n_smaller ++ ;
  }
  return n_smaller ;
}

int pointerSpace::meet(list<list<list::iterator>>::iterator friend_1, list<list<list::iterator>>::iterator friend_2) //must make 'shun' method to remove friends.
{
  if(!friends(friend_1, friend_2)){
    (*friend_1).push_back(friend_2) ;
    (*friend_2).push_back(friend_1) ;
    return 0 ;
  }
  if(friends(friend_1, friend_2)) return 2 ;
  else if((*friend_1).contains(friend_2)) return 1 ;
  else if((*friend_2).contains(friend_1)) return -1 ;
}

void pointerSpace::meetAll()
{
  list<list<list::iterator>>::iterator e ;
  for(n = npointers.begin() ; n != npointers.end() ; n++){
    for(e = exist.begin() ; exist != exist.end() ; e++){
      (*e).push_back(*n) ;
    }
  }
}
