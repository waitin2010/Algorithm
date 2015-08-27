/*
  ID: come_1b1
  LANG: C++11
  TASK: concom
 */

#include <iostream>
#include <fstream>
#include <iomanip>
const int max_con = 100 + 1;

int adj[max_con][max_con] = {0};
bool adj2[max_con][max_con] = {false};

int con = 0;

std::ofstream fout;

void solve()
{
  bool bNew = true;
  while( bNew ){
    bNew = false;
    for( int i = 1; i <= con; ++i ){
      for( int j = 1; j <= con; ++j ) {
	if( adj[i][j] >= 50 && !adj2[i][j]){
	  for( int k = 1; k <=con; ++k ) {
	      adj[i][k] += adj[j][k];
	      if( adj[i][k] > 100 )
		adj[i][k] = 100;
	      
	    bNew = true;
	  }
	  adj2[i][j] = true;
	}
      }
    }
  }
  for( int i = 1; i <= con; ++i )
    for( int j = 1; j <= con; ++j )
      if( adj2[i][j] && i != j)
	fout << i << " " << j << std::endl;
}

void print()
{
  for( int i = 1; i <= con; ++i ){
    for( int j = 1; j <= con; ++j ){
      std::cout << std::setw(3) << adj[i][j] << " ";
    }
  std::cout<< std::endl;
  }
}
int main()
{
  std::ifstream fin( "concom.in", std::ios::in );
  int n;
  fin >> n;
  int i, j, c;
  while( n--) {
    fin >> i >> j >> c;
    adj[i][j] = c;
    if( con < i || con < j )
      con = i > j ? i : j;
  }
  fout.open( "concom.out", std::ios::out);
  solve();
  fout.close();

  //  print();
  
  return 0;
}
