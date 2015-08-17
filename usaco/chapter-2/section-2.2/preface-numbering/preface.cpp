/*
  ID: come_1b1
  LANG: C++
  TASK: preface
*/
#include <iostream>
#include <fstream>
#include <cstring>

int BaseRomanNum[] = { 1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000 };
char BaseRomanChar[][3] = { "I",  // 1
			    "IV", // 4
			    "V",  // 5
			    "IX", // 9
			    "X",  // 10
			    "XL", // 40
			    "L",  // 50
			    "XC", // 90
			    "C",  // 100
			    "CD", // 400
			    "D",  // 500
			    "CM", // 900
                            "M"   // 1000
                         };

char BaseRomanChar2[] = "IVXLCDM";
int  BaseRomanCount[256] = {  0 };

void Dec2Roman( int num ){
  int i = sizeof( BaseRomanNum ) / sizeof( BaseRomanNum[0] ) - 1;
  while( i >= 0 ){
    int div = num / BaseRomanNum[i];
    for( int j = 0; j < div; ++j ){
      for( int k = 0; k < strlen( BaseRomanChar[i] ); ++k )
	BaseRomanCount[BaseRomanChar[i][k]]++;
    }
    num = num % BaseRomanNum[i];
    --i;
  }
}

int main( ){

  int n;
  std::ifstream fin( "preface.in", std::ios::in );
  fin >> n;
  while( n){
    Dec2Roman( n );
    --n;
  }

  std::ofstream fout( "preface.out", std::ios::out );
  for( int i = 0; i < sizeof( BaseRomanChar2 ) / sizeof( BaseRomanChar2[0] ); ++i ){
    if( BaseRomanCount[BaseRomanChar2[i]] != 0 )
      fout << BaseRomanChar2[i] << " " << BaseRomanCount[BaseRomanChar2[i]] << std::endl;
  }
  return 0;
}
