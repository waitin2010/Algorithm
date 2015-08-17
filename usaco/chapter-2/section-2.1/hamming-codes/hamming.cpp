/*
  ID: come1_b1
  LANG: C++
  TASK: hamming
 */

#include <iostream>
#include <fstream>

int N,B,D;
const int max_n = 64;
int num[max_n];

std::ofstream fout;

int count_1( int num )
{
  int ret = 0;
  int i = B;
  while( i-- > 0 && num != 0 ){
    ret += num & 0x1 == 1 ? 1 : 0;
    num = num >> 1;
  }
  return ret;
}

int hamming_distance( int a, int b ){
  int c = a ^ b;
  return count_1( c );
}

bool is_right( int n, int index ){
  
  for( int i = 0; i < index; ++i )
    if( hamming_distance( n, num[i] ) < D )
      return false;
  return true;
}

bool solve( int start, int n )
{
  if( n >= N ){
    for( int i = 0; i < N; ++i ){
      fout << num[i];
      if( ( i + 1 ) % 10 != 0 && i != N - 1)
	fout << " ";
      else
	fout << std::endl;
    }
    return true;
  }

  int count = 1 << B;
  for( int i = start; i < count; ++i ){
    if( is_right( i, n ) ){
      num[n] = i;
      if( solve( i + 1, n + 1 ) ) return true;
      num[n] = 0;
    }
  }
  return  false;
}
int main()
{


  std::ifstream fin( "hamming.in", std::ios::in );
  fin >> N >> B >> D;
  fin.close();
#if 0
  for( int i = 0; i < 128; ++i )
    std::cout << std::dec << i << " "
	      << std::hex << "0x" << i << " "
	      << count_1( i ) << std::endl;
#endif

  fout.open( "hamming.out", std::ios::out );
  solve( 0, 0 );
  fout.close();
  return 0;
}
  
