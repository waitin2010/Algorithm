/*
 ID: come_1b1
 LANG: C++11
 TASK: humble
 */

#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

const int max_k = 110;
const int max_n = 100010;

int k,n;
int k_val[max_k];

int point[max_k];
int n_val[max_n];


int solve(){
  // init
  n_val[0] = 1;

  for( int i = 1; i <= n; ++i ){
    int next_val = 0x7fffffff;
    int next_index;
    for( int j = 0; j < k; ++j ){
      while( k_val[j] * n_val[point[j]] <= n_val[i-1] )
	point[j]++;
      if( k_val[j] * n_val[point[j]] < next_val ){
	next_val = k_val[j] * n_val[point[j]];
	next_index = j;
      }
    }
    n_val[i] = next_val;
    point[next_index]++;

    //std::cout << point[next_index] << std::endl;
  }
  #if 0
  std::copy( std::begin( n_val ),
	     std::begin( n_val ) + n + 1,
	     std::ostream_iterator<int>( std::cout, " " ) );
  std::cout << std::endl;
  #endif
  
  return n_val[n];
}

int main(){
  std::ifstream fin("humble.in", std::ios::in );
  fin >> k >> n;
  for( int i = 0; i < n; ++i )
    fin >> k_val[i];
  fin.close();

  std::ofstream fout("humble.out", std::ios::out );
  fout << solve() << std::endl;
  fout.close();

  return 0;
}
  
