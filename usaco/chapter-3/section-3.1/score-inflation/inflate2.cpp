/*
  ID: come_1b1
  LANG: C++11
  TASK: inflate
 */

#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

const int max_n = 10000;

int M, N;
struct Cls{
  int p;
  int m;
}cls[max_n];

int visited[max_n];

int solve(){
  int ret  = 0;
  
  while( 1 ){
    int index = - 1;
    float unit_big = 0.0;
    for( int i = 0; i < N; ++i ){
      if( !visited[i] && float(cls[i].p) / cls[i].m > unit_big ){
	unit_big = float( cls[i].p ) / cls[i].m ;
	index = i;
      }
    }

    if( index == -1 ) break;

    ret += M / cls[index].m * cls[index].p;
    visited[index] = 1;

    M = M % cls[index].m;
  }
    
    
  return ret;
}

int main(){
  std::ifstream fin("inflate.in");
  fin >> M >> N;
  for( int i = 0; i < N; ++i )
    fin >> cls[i].p >> cls[i].m;
  fin.close();

  #if 0
  for( int i = 0; i < N; ++ i )
    std::cout << cls[i].p << " " << cls[i].m << std::endl;
  #endif
  
  std::ofstream fout("inflate.out");
  fout << solve() << std::endl;
  fout.close();

  return 0;
}
