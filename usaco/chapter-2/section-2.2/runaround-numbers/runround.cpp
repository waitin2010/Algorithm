/*
  ID: come_1b1
  LANG: C++
  TASK: runround
 */

#include <iostream>
#include <fstream>

int digits[10] = {0};
int index = 0;

int count[10] = { 0 };

int count2[10] = { 0 };

void clean()
{
  for( int i = 0; i < 10; ++i ){
    count[i] = 0;
    count2[i] = 0;
  }
}

void num2array( int num ){
  index = 0;
  clean();
  do{
    digits[index++] = num % 10;
    count[num%10]++;
    num = num / 10;
  }while( num > 0 );
    
}

bool isRunRound1(){
  if( count[0] >= 1 ) return false;
  for( int i = 1; i <= 9; ++i )
    if( count[i] >=2 )
      return false;
  return true;
}

bool isRunRound2() {
  int j = 0;
  for( int i = 0; i < index; ++i ){
    j = ( j + digits[index - j - 1] ) % index;
    count2[j]++;
    if( count2[j] > 1 ) return false;
  }
  return j == 0 ? true : false;
}

bool isRunRound3() {
  for( int i = 0; i < index; ++i )
    if( count2[i] != 1 )
      return false;
  return true;
}
int main()
{
  int n;
  std::ifstream fin( "runround.in", std::ios::in );
  fin >> n;
  fin.close();

  int ret = 0;
  for( int i = n + 1; i < 999999999; ++i ){
    num2array( i );
    if( isRunRound1() && isRunRound2() && isRunRound3() ){
      //      std::cout << index << " " << i << std::endl;
      ret = i;
      break;
    }
  }

  std::ofstream fout( "runround.out", std::ios::out );
  fout << ret << std::endl;
  fout.close();

  return 0;
}
