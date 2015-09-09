/*
  ID: come_1b1
  LANG: C++11
  TASK: inflate
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <map>

const int max_v = 10000+10;
//int data[max_v][max_v];

std::map<std::pair<int, int>, int> data;

int M,N;

struct Cls{
  int p;
  int m;
}cls[max_v];
#if 0
void print(){
  for( int i = 0; i < N; ++i ){
    std::copy( std::begin( data[i] ),
	       std::begin( data[i] ) + M,
	       std::ostream_iterator<int>( std::cout, " " ) );
    std::cout << std::endl;
  }
}
#endif


int solve( int m, int n ){
  int ret = -1;
  if( m < 0  ){
    return -1;
  }
  int ret1,ret2;
    
  if( n==0 ){
    if( m < cls[n].m )
      ret =  -1;
    else
    //data[n][m] = m / cls[n].m * cls[n].p;
    ret = m / cls[n].m * cls[n].p;
  }else {
  
    if( data.find( std::make_pair( n - 1, m ) ) == data.end() )
      ret1 = solve( m, n - 1 );
    else
      ret1 = data[std::make_pair( n -1, m )];

    if( data.find( std::make_pair( n, m - cls[n].m ) ) == data.end() )
      ret2 = solve( m - cls[n].m, n );
    else
      ret2 = data[std::make_pair( n, m - cls[n].m )];
  
    //    data[n][m] = std::max( data[n-1][m],
    //			   data[n][m-cls[n].m] >=0 ?data[n][m-cls[n].m] + cls[n].p:0);
      ret = std::max( ret1, ret2 >= 0 ? (ret2 + cls[n].p ): 0 );
  }

  //  std::cout << n << ":" << m << " " << data[n][m] << std::endl;
  //  return data[n][m];
  //  std::cout << m << " " << n << ":" << ret1 << " " << ret2 << " " << ret << std::endl;
  data.insert( std::make_pair( std::make_pair( n, m ), ret ) );
  
  return ret;
}

int main(){
  std::ifstream fin("inflate.in");
  fin >> M >> N;
  for( int i = 0; i < N; ++i )
    fin >> cls[i].p >> cls[i].m;
  fin.close();

  //  print();
  std::ofstream fout("inflate.out");
  fout << solve( M, N-1 ) << std::endl;
  fout.close();

  // std::cout << solve( 20, 3 ) << std::endl;

  return 0;
 
}
