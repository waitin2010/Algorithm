/*
  ID: come_1b1
  LANG: C++11
  TASK: nocows
 */

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>


const int max_n = 200;
const int max_k = 100;

int pedigrees[max_n][max_k] = {0};

void init()
{
  pedigrees[1][1] = 1;
  pedigrees[3][2] = 1;
}

int solve( int n, int k ){
  
  int nResult = 0;
  int rep = 0;
  if( n % 2 == 0 || k < log(n) || k > n - 2 )
    return 0;

  for( int i1 = 1; i1 < n; ++i1 ){
    int i2 = n - i1 - 1;
    for( int k2 = 1; k2 < k; ++k2 ){
      if( pedigrees[i1][k-1] == 0 )
	pedigrees[i1][k-1] = solve( i1, k - 1);
      if( pedigrees[i2][k2] == 0 )
	pedigrees[i2][k2] = solve( i2, k2 );
      nResult += pedigrees[i1][k-1] * pedigrees[i2][k2];
      if( k - 1 == k2 )
	rep += pedigrees[i1][k - 1] * pedigrees[i2][k2];
      #if 0
      if( pedigrees[i1][k - 1] * pedigrees[i2][k2] != 0 ) {
      std::cout << i1 << "-" << k - 1 << ",";
      std::cout << i2 << "-" << k2 << ":";
      std::cout << nResult << std::endl;
      std::cout << std::endl;
	}
      #endif
    }
  }
  #if 0
  if( nResult != 0 ) {
    std::cout << "----------------------------------" << std::endl;
  std::cout << n << ":" << k << std::setw(10) << nResult * 2 - rep << std::endl;
  std::cout << "----------------------------------" << std::endl;
  }
  #endif
  return nResult * 2 - rep;
}

int solve2( int n, int k )
{
  for( int i = 5; i <= n; i+=2 ){
    for( int j = 1; j <= k; ++j ) {
      if( j < log( i ) || j > i - 2 )
	continue;
      for( int i1 = 1; i1 < i; i1+=2 ){
	int i2 = i - i1 - 1;
	for( int k2 = 1; k2 < j; ++k2 ){
	  pedigrees[i][j] += pedigrees[i1][j-1] * pedigrees[i2][k2] * 2;
	  if( j - 1 == k2 )
	    pedigrees[i][j] -= pedigrees[i1][j-1] * pedigrees[i2][k2];
	  pedigrees[i][j] %= 9901;
	}
      }
    }
  }

  return pedigrees[n][k];
}

int main()
{
  int N, K;
  std::ifstream fin( "nocows.in", std::ios::in );
  fin >> N >> K;
  fin.close();
#if 0
  std::cout << N << K << std::endl;
#endif
  init();
  
  std::ofstream fout( "nocows.out", std::ios::out );
  fout << solve2( N, K ) % 9901 << std::endl;
  fout.close();
#if 0
  for( int i = 1; i <= N; ++i ){
    std::cout << i << " : " ;
    for( int j = 1; j <= K; ++j )
      std::cout << pedigrees[i][j] << " ";
    std::cout << std::endl;
  }
    std::cout << solve2( N, K ) << std::endl;

#endif
  return 0;
}
