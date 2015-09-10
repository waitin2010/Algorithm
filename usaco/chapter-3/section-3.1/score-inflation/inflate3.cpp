/*
  ID: come_1b1
  LANG: C++11
  TASK: inflate
 */

#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

const int max_n = 10000+1;

int M, N;
struct Cls{
  int p;
  int m;
}cls[max_n];

int ret[max_n];

int solve(){
  for( int i = 0; i != N; ++i ){
    for( int j = cls[i].m; j <=M; ++j ){
      //      std::cout << ret[j] << " " << ret[j-cls[i].m] + cls[i].p << " " << cls[i].p << std::endl;
      ret[j] = std::max( ret[j], ret[j-cls[i].m] + cls[i].p );
    }
  }
  return ret[M];
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
