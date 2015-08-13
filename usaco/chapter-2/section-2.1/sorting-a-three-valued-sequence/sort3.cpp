/*
  ID: come_1b1
  LANG: C++
  TASK: sort3
 */

#include <iostream>
#include <fstream>
#include <vector>

int a3, b3, c3;
int a2, b2, c2;
int a1, b1, c1;

int N;
std::vector<int> data;
int num[4];
int a[4];
int b[4];
int c[4];
int main(){

  std::ifstream fin("sort3.in", std::ios::in);
  fin>> N;

  for( int i = 0; i < N ; ++i ){
    int a;
    fin >> a;
    data.push_back( a );
    num[a]++;
  }

  fin.close();

  #if 0
  for( int i = 1; i < sizeof( num ) / sizeof( num[0] ); ++i )
    std::cout << i << ":" << num[i] << std::endl;
#endif
  for( int i = 0; i < N; ++i ){
    if( i < num[1] ){
      a[data[i]]++;
    }else if( i < num[2] + num[1] ){
      b[data[i]]++;
    }else{
      c[data[i]]++;
    }
  }
#if 0
  for( int i = 1; i < 4; ++i ){
    std::cout << a[i] << " " << b[i] << " " << c[i] << std::endl;
  }
    
  for( int i = 0; i < N; ++i ){
    std::cout << data[i] << std::endl;
  }

  #endif
  std::ofstream fout( "sort3.out", std::ios::out );
  fout << c[2] + c[1] + b[1] + std::max( 0, b[3] - c[2] ) << std::endl;
  fout.close();
  return 0;
}
    
