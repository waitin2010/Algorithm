/*
  ID: come_1b1
  LANG: C++11
  TASK: kimbits
 */
#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>

int n,l,k;
unsigned int bits[31];

std::ofstream fout;

void int2binstr( int num ){
  for( int i = n-1; i >= 0; --i )
    if( num & bits[i] )
      fout << "1";
    else
      fout << "0";
  fout << std::endl;
}

int main(){
  std::ifstream fin("kimbits.in");
  fin >> n >> l >> k;
  fin.close();
  
  unsigned int len = 0x1 << n;
  //  std::cout << len << std::endl;
  int cc = 0;
  for( int i = 0; i < n; ++i )
    bits[i] = 0x1 << i;

  #if 0
  std::copy( std::begin( bits),
	     std::end( bits ),
	     std::ostream_iterator<int>(std::cout, " " ) );
  std::cout << std::endl;
  #endif
	     

  int ret = 0;
  int len1 = 0x1 <<( n - 1);
  for( int i = len1; i <= len; ++i ){
    int c = 0;
    for( int j = 0; j < n; ++j )
      if( bits[j] & i )
	c++;
    if( c <= l ){
      cc++;
      //      std::cout << i << std::endl;
      ret = i;
    }
    if( cc >= k )
      break;
  }

  //  std::cout << cc << " " << ret << std::endl;
  fout.open("kimbits.out");
  int2binstr( ret );
  fout.close();

  return 0;
}
