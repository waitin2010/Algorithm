/*
  ID: come_1b1
  LANG: C++11
  TASK: fracdec
 */

#include <iostream>
#include <fstream>
#include <sstream>

const int max_n = 100000;
int child[max_n];
int num[max_n];
int zero[max_n];
int visited[max_n];
int dec;
int start;

int N,D;

std::ofstream ffout;

void solve(){
  dec = N / D;
  N = N % D;

  start = N;
  
  while( N % D != 0 && !visited[N] ){
    visited[N] = 1;
    int n = N;
    do {
      n *= 10;
      if( n < max_n && visited[n] )
	break;
      zero[N]++;
    }while( n < D );

    if( n < max_n && visited[n] ){
      N = n;
      break;
    }
    num[N] = n / D;
    child[N] = n % D;
    N = n % D;
  }

  std::stringstream fout;
  int first = 0;
  fout << dec << ".";
  for( int i = start; i!= 0 && (i != N || first != 1); i = child[i] ){
    if( i == N ) first++;
    if( i== N && first == 1 )
      fout << "(";
    for( int j = 1; j < zero[i]; ++j )
      fout << '0';
    fout << num[i];
  }
  if( first == 1 )
    fout << ")";
  if( start == N && child[start] == 0 )
    fout << "0";
  fout << std::endl;

  std::string temp = fout.str();
  for( int i = 0; i < temp.size(); ++i ){
    ffout << temp[i];
    if( (i+1) % 76 == 0 )
      ffout << std::endl;
  }
  #if 0
  std::cout << start << std::endl;
  std::cout << N << std::endl;
  std::cout << first << std::endl;
  #endif
}

int main(){
  std::ifstream fin( "fracdec.in", std::ios::in );
  fin >> N >> D;
  fin.close();

  
  ffout.open( "fracdec.out", std::ios::out);
  solve();
  ffout.close();

  return 0;
}
