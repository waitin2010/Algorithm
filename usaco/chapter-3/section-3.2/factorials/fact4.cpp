/*
  ID: come_1b1
  LANG: C++11
  TASK: fact4
 */
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

int n;

int solve(){
  int ret = 1;
  for( int i = 1; i <=n; ++i ){
    ret *= i;
    while( ret % 10 == 0 )
      ret /= 10;
    ret = ret % 10000;
  }

  
  return ret % 10;
}

int main(){
  std::ifstream fin("fact4.in" );
  fin >> n;
  fin.close();

  std::ofstream fout("fact4.out");
  fout << solve() << std::endl;
  fout.close();

  return 0;
}
  
