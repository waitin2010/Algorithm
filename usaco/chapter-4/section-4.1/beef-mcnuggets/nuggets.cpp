/*
  ID: come_1b1
  LANG: C++11
  TASK: nuggets
 */
#include <iostream>
#include <fstream>
#include <map>
#include <queue>
#include <algorithm>
#include <iterator>

int n;
const int max_n = 10;
int data[max_n];

const int temp = 257;

int result[temp];

int solve(){
  int ret = 0;
  int i = 0;
  for( i = 0; i < n; ++i ){
    if( data[i] % 2 != 0 )
      break;
  }
  if( i >= n ) return 0;
  
  for( int i = 1; i<= 2000000000; ++i){
    result[i%temp] = 0;
    for( int j = 0; j < n; ++j){
      if( i == data[j] ){
	result[i] = result[i - 1] + 1;
	break;
      }
      else{
	if( i - data[j] >= 0 && result[(i - data[j])%temp] > 0 ){
	  result[i%temp] = result[(i - 1)%temp] + 1;
	  break;
	}
      }
    }
    if( result[i%temp] >= data[0] ){
      ret = i - data[0];
      break;
    }

  }
#if 0
  std::copy( std::begin( result ),
	     std::end( result ),
	     std::ostream_iterator<int>(std::cout, " ") );
  std::cout << std::endl;
  #endif
  std::cout << ret << std::endl;
  return ret;
}

void print_input(){
  std::cout << n << std::endl;
  for( int i = 0; i < n; ++i){
    std::cout << data[i] << "\t";
  }
  std::cout << std::endl;
}

int main(){
  std::ifstream fin("nuggets.in");
  fin >> n;
  for( int i = 0; i < n; ++i )
    fin >> data[i];
  fin.close();

  std::sort( std::begin( data ), std::begin( data ) + n );
  //print_input();

  int ret = solve();

  std::ofstream fout("nuggets.out");
  fout << ret << std::endl;
  fout.close();

  return 0;
}


