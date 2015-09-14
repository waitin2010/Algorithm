/*
 ID: come_1b1
 LANG: C++11
 TASK: stamps
 */

#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

int k, n;

const int max_n = 50;
int stv[max_n];
int max_stv;

const int ret_n = 200 * 10000;
int ret[ret_n];

int solve(){
  for( int i = 0; i < n; ++i ){
    ret[stv[i]] = 1;
    for( int j = stv[i]+1; j <= k * max_stv; ++j){
      if( ret[j] != 0
	  && ret[j-stv[i]]!= 0
	  &&  ret[j] > ret[j-stv[i]]+1 )
	ret[j] = ret[j-stv[i]] + 1;
      else if( ret[j] == 0 && ret[j-stv[i]] != 0 )
	       ret[j] = ret[j-stv[i]] + 1;
      //      std::cout << j << " " << ret[j] << " " << ret[j-stv[i]] << std::endl;
    }
  }

  for( int i = 1; i <= k * max_stv + 1; ++i ){
    //    std::cout << i << " " << ret[i] << " " << k << std::endl;
    if( ret[i] == 0 || ret[i] > k )
      return i - 1;
  }
  return -1;
}


int main(){
  std::ifstream fin("stamps.in" );
  fin >> k >> n;
  for( int i = 0; i < n; ++i ){
    fin >> stv[i];
    if( stv[i] > max_stv )
      max_stv = stv[i];
  }
  fin.close();

  std::ofstream fout("stamps.out" );
  fout << solve() << std::endl;
  fout.close();

  return 0;
}
  
