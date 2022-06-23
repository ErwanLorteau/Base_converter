#include <iostream>
#include <string> 
using namespace std ;

int convertChar(char c);
int convertBaseTenHorner(string s, int fromBase) ; 
string convertBaseX(int numberBaseTen, int toBase) ;
char convertInt(int c) ;


//Given a string of a number in FromBase, give the a string of the same number in base ToBase
string base_converter(string s, int fromBase ,int toBase) {
  std::cout<<"Initial number in base "<< fromBase << " : "<< s << endl ; 
  
  int numberBaseTen = convertBaseTenHorner ( s, fromBase ) ;   
  std::cout<<"Number in base 10 : " << numberBaseTen << endl ;  

  string g = convertBaseX(numberBaseTen,toBase) ; 
  std::cout<<"Number in base " << toBase <<" : " << g << endl ;  
  return g ; 
}

/*Convert any number from base X to base 10.
  *We assume any characther is not in capital
*/


int convertBaseTenHorner(string s, int fromBase) {
  int numberBaseTen = 0 ; //Returned result   
  
  //String convertion sing horner form
  for (char c : s) {        
    numberBaseTen = (numberBaseTen * fromBase) + convertChar(c) ;     
  } 
  return  numberBaseTen ; 
}


/*Given a char and a base, return the base ten value*/
/*'c' is also an int (ascii code) */ 
int convertChar(char c) {

  if (c >= '0' && c <= '9' ) { //if c € [0;9] 
    return (c - '0') ; 
  } else { 
    return ( c - 'a' + 10 ) ; 
  }
}

//Could have problems
char convertInt(int c) {
  string s = "0123456789abcdefghijklmnopqrstuvwxyz" ; 
  char returned = s.at(c) ; 
  return returned ; 
}

//Convert a number in base ten into any base (cant go over ASCCI Limits)
string convertBaseX(int numberBaseTen, int toBase) {
  string result ; 
  int rest = 0 ; 
  int quotient = 0  ; 

 
  do {
    quotient  = numberBaseTen / toBase ; //Division entiere si deux entier
    
    rest = numberBaseTen % toBase ; 
    numberBaseTen = numberBaseTen / toBase ;
    result = convertInt(rest) + result ; 
  }

   while (quotient != 0 )  ;  

   return result ; 
  
}

int main() {
  /***How to use***/
  /*Base 18*/
  //Number to convert
  string s = "3eh12" ; 
  
  //Bases from and baseTo go
  int fromBase = 18 ; 
  int toBase = 2 ;

  string numberConverted = base_converter(s,fromBase,toBase) ;   
}