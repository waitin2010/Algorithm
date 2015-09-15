/*
  ID: come_1b1
  LANG: C++11
  TASK: kimbits
 */
#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>

unsigned int n,l,k;
unsigned int bits[31];

bool solve( unsigned int d, unsigned int c, unsigned int &nth ){
  //  std::cout << d << " " << c << " " << nth << std::endl;
  bool ret = false;
  if( c == 0 && d != 0 && nth != 1){
    nth--;
    return false;
  }
    
  if( d == 0 ){
    if( nth == 1 )
      return true;
    else{
      //  std::cout << "right node" << std::endl;
      nth--;
      return false;
    }
  }
  
  if( d == c && (nth > (0x1 << d )) ){
    //      std::cout << nth << "-" << (0x1 << d ) << std::endl;
      nth -= 0x1 << d;
      return false;
  }
  
  if( d == c && nth > (0x1 <<( d - 1 )) ){
    nth -= (0x1 << ( d - 1 ));
  }else {
      ret = solve( d - 1, c, nth );
  }

  bits[n-d] = 0;
  if( ret ) return true;
  
  bits[n-d] = 1;
  return solve( d - 1, c - 1, nth );
}

int main(){
  std::ifstream fin("kimbits.in");
  fin >> n >> l >> k;
  fin.close();

  solve( n, l, k );
  
  std::ofstream fout("kimbits.out");
  std::copy( std::begin( bits ),
	     std::begin( bits ) + n,
	     std::ostream_iterator<int>(fout,"") );
  fout<<std::endl;
	     
  fout.close();

  return 0;
}
