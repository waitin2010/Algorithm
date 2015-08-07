/*
ID: come_1b1
LANG: C++
TASK: sprime
*/

#include <iostream>
#include <fstream>
#include <cstdlib>

bool is_prime( int num )
{
  if( num < 2 ) return false;
  if( num == 2 ) return true;
  if( num %2 == 0 ) return false;
  for( int i = 3; ( i * i ) <= num; i += 2 ){
    if( num % i == 0 ) return false;
  }
  return true;
}


int N;
char num[9];

std::ofstream fout;
void solve( int depth ){
  int a = atoi( num );
  if( depth != N && !is_prime( a ) ) return ;
  if( depth <= 0 ){
      fout << a << std::endl;
  }else {
    if( depth == N ){
      num[N-depth] = '2';
      solve( depth - 1 );
      num[N-depth] = '\0';
    }else{
      num[N-depth] = '1';
      solve( depth - 1 );
      num[N-depth] = '\0';
    }
      
    for( int i = 3; i <=9; ++i ){
      num[N-depth] = '0' + i;
      solve( depth - 1 );
      num[N-depth] = '\0';
    }
  }
}
      
int main()
{
  std::ifstream fin( "sprime.in", std::ios::in );
  fin >> N;

  fout.open( "sprime.out", std::ios::out );
  solve( N );
  //  fout<< solve( ) << std::endl;

  return 0;
}
