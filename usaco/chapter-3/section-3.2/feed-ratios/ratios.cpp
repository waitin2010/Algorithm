/*
  ID: come_1b1
  LANG: C++11
  TASK: ratios
 */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>

int ret[3];

int data[3][3];

int a, b, c;

int i1, i2, i3;

void calc( int &a, int &b, int &c, int i, int j ){
  a += data[i][0] * j;
  b += data[i][1] * j;
  c += data[i][2] * j;
}

void recv( int &a, int &b, int &c, int i, int j ){
  a -= data[i][0] * j;
  b -= data[i][1] * j;
  c -= data[i][2] * j;
}

bool is_finished( ){
  int d = a / ret[0];

  if( d!= 0 && d * ret[0] == a
      && d * ret[1] == b
      && d * ret[2] == c )
    return true;
  else
    return false;
}
    
bool solve(){
  for( int i = 0; i <= 100; ++i ){
    i1 = i;
    a = b = c = 0;
    calc( a, b, c, 0, i );
    for( int j = 0; j <= 100; ++j ){
      i2 = j;
      calc( a, b, c, 1, j );
      for( int k = 0; k <= 100; ++k ){
	i3 = k;
	calc( a, b, c, 2, k );
	if( is_finished( )  )
	  return true;
	recv( a, b, c, 2, k);
      }
      recv( a, b, c, 1, j );
    }
    recv( a, b, c, 0, i );
  }
  return false;
}

int main(){
  std::ifstream fin("ratios.in");
  fin >> ret[0] >> ret[1] >> ret[2];
  for( int i = 0; i < 3; ++i )
    for( int j = 0;j < 3; ++j )
      fin >> data[i][j];
  #if 0
  for( int i = 0; i < 3; ++i ){
    for( int j = 0; j < 3; ++j )
      std::cout << data[i][j] << " ";
    std::cout << std::endl;
  }
  #endif

  std::ofstream fout("ratios.out");
  if( solve() )
    fout << i1 << " " << i2 << " " << i3 << " " << a / ret[0] << std::endl;
  else
    fout << "NONE" << std::endl;

  return 0;
}
