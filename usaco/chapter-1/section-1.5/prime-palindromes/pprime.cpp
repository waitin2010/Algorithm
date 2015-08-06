/*
ID: come_1b1
LANG: C++
TASK: pprime
*/
#include <iostream>
#include <fstream>
#include <cstdlib>

std::ofstream fout( "pprime.out", std::ios::out );

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

char num[10];
int count;

int a, b;

void construct_one_palindromic( int len, int pos ){
  if( pos >= ( len + 1) / 2 || pos == len){
    int n = atoi( num );
    if( n >=a && n <= b && is_prime( n ) ) 
      fout << num << std::endl;
  }
  else{
    for( int i = 0; i <= 9; ++i ) {
      if( pos == 0 && i == 0) continue;
      num[pos] = '0' + i;
      num[len-pos-1] = '0' + i;

      construct_one_palindromic( len, pos + 1 );

      num[pos] = '\0';
      num[len-pos-1] = '\0';
      
    }
  }
}

int main()
{
  std::ifstream fin("pprime.in", std::ios::in );
  fin >>  a >> b;

  for( int i = 1; i <= 9; ++i )
    construct_one_palindromic( i, 0 );

  return 0;
}
