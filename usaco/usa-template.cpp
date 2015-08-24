/*
  ID: come_1b1
  LANG: C++11
  TASK: nocows
 */

#include <iostream>
#include <fstream>

const int max_n = 200;
const int max_k = 100;

int pedigrees[max_n][max_k] = {0};

int solve( int n, int k ){
  int nResult = 0;
  if( n % 2 == 0 )
    return 0;
  for( int i1 = 1; i1 < n; ++i1 ){
    int i2 = n - i1;
    for( int k2 = 1; k2 < k - 1; ++k2 ){
      if( pedigrees[i1][k-1] == 0 )
	pedigrees[i1][k-1] = solve( i1, k - 1);
      if( pedigrees[i2][k2] == 0 )
	pedigrees[i2][k2] = solve( i2, k2 );
      nResult += pedigrees[i1][k-1] * pedigrees[i2][k2];
    }
  }
  return nResult * 2;
}

int main()
{
  int N, K;
  std::ifstream fin( "nocows.in", std::ios::in );
  fin >> N >> K;
  fin.close();

  std::ofstream fout( "nocows.out", std::ios::out );
  fout << solve( N, K ) << std::endl;
  fout.close();
  return 0;
}
