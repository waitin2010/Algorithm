/* 
   ID: come_1b1
   LANG: C++11
   TASK: zerosum
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>

char A[] = " +-";
int nA = sizeof( A ) / sizeof( A[0] );

char O[18];
int iO = 0;

int N;

int iO2 = 0;

std::ofstream fout;

int get_int()
{
  int ret = 0;
  while( O[iO2] != '\0' && ( O[iO2] != '+' && O[iO2] != '-' )){
    if( O[iO2] != ' ' )
      ret = ret * 10 + O[iO2] - '0';
    iO2++;
  }
  return ret;
}

int get_op( )
{
  return O[iO2++];
}


bool zero_sum( )
{
  iO2 = 0;
  int a = get_int();
  int b = 0;
  int c = 0;
  while( ( c = get_op() ) != '\0' ){
    switch( c ){
    case '+':
      b = get_int();
      a += b;
      break;
    case '-':
      b = get_int();
      a -= b;
      break;
    default:
      std::cout << "error" << c << std::endl;
    }
  }
  return a == 0;
}

void solve( int d ){

  O[iO++] = '0' + d;
  
  if( d >=N ){
    if( zero_sum() )
      //std::cout << O << std::endl;
      fout << O << std::endl;
  }else{
    for( int i = 0; i < nA - 1; ++i ){
      O[iO++] = A[i];
      solve( d + 1 );
      O[--iO] = '\0';
    }
  }
  O[--iO] = '\0';
}

int main()
{
  std::ifstream fin( "zerosum.in", std::ios::in );
  fin >> N;
  fin.close();

  fout.open( "zerosum.out", std::ios::out );
  solve( 1 );

  fout.close();
  return 0;
}
