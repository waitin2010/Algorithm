/*
  ID: come_1b1
  LANG: C++
  TASK: game1
 */

#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>

int n;
std::vector<int> data;

const int max_n = 100;
int p1[max_n][max_n][2];
int p2[max_n][max_n][2];

void solve_p2( int i, int j );

void solve_p1( int i, int j ){
  if( i+1 == j ){
    if( data[i] >= data[j] ){
      p1[i][j][0] = data[i];
      p1[i][j][1] = i;
      solve_p2( j, j );
    }else{
      p1[i][j][0] = data[j];
      p1[i][j][1] = j;
      solve_p2( i, i );
    }
  }else{
    int i1, j1;
    if( p2[i+1][j][0] == 0 )
      solve_p2( i + 1, j );
    if( p2[i+1][j][1] == i + 1 ){
      i1 = i + 2;
      j1 = j;
    }else{
      i1 = i + 1;
      j1 = j - 1;
    }
    if( p1[i1][j1][0] == 0 )
      solve_p1( i1, j1 );
    int ret_l = data[i] + p1[i1][j1][0];

    int i2, j2;
    if( p2[i][j-1][0] == 0 )
      solve_p2( i, j - 1 );
    if( p2[i][j-1][1] == i ){
      i2 = i + 1;
      j2 = j - 1;
    }else{
      i2 = i;
      j2 = j - 2;
    }
    if( p1[i2][j2][0] == 0 )
      solve_p1( i2, j2 );
    int ret_r = data[j] + p1[i2][j2][0];

    if( ret_l >= ret_r ){
      p1[i][j][0] = ret_l;
      p1[i][j][1] = i;
    }else{
      p1[i][j][0] = ret_r;
      p1[i][j][1] = j;
    }
  }
    
}

void solve_p2( int i, int j ){
  if( i == j ){
    p2[i][j][0] = data[i];
    p2[i][j][1] = i;
  }else{
    //left
    int i1, j1;
    if( p1[i+1][j][0] == 0 )
      solve_p1( i + 1, j );
    if( p1[i+1][j][1] == i + 1 ){
      i1 = i + 2;
      j1 = j;
    }else{
      i1 = i + 1;
      j1 = j - 1;
    }
    if( p2[i1][j1][0] == 0 )
      solve_p2( i1, j1 );
    int ret_l = data[i] + p2[i1][j1][0];

    int i2, j2;
    if( p1[i][j-1][0] == 0 )
      solve_p1( i, j - 1 );
    if( p1[i][j-1][1] == i ){
      i2 = i + 1;
      j2 = j - 1;
    }else{
      i2 = i;
      j2 = j - 2;
    }
    if( p2[i2][j2][0] == 0 )
      solve_p2( i2, j2);
    int ret_r = data[j] + p2[i2][j2][0];

    if( ret_l >= ret_r ){
      p2[i][j][0] = ret_l;
      p2[i][j][1] = i;
    }else{
      p2[i][j][0] = ret_r;
      p2[i][j][1] = j;
    }
  }
}

void solve(){
  if( n % 2 == 0 )
    solve_p1( 0, n - 1);
  else
    solve_p2( 0, n - 1 );
}

int main(){
  std::ifstream fin("game1.in");
  fin >> n;
  std::copy( std::istream_iterator<int>( fin ),
	     std::istream_iterator<int>(),
	     std::back_inserter( data ) );
  fin.close();

  #if 0
  std::copy( std::begin( data ),
	     std::end( data ),
	     std::ostream_iterator<int>( std::cout, " " ) );
  std::cout << std::endl;
  #endif

  solve();

  int np1, np2;
  if( n % 2 == 0 ){
     np1 = p1[0][n-1][0];
     np2 = p1[0][n-1][1] == 0 ? p2[1][n-1][0] : p2[0][n-2][0];
  }else{
    np1 = p2[0][n-1][0];
    np2 = p2[0][n-1][1] == 0 ? p1[1][n-1][0] : p1[0][n-2][0];
  }

  std::ofstream fout("game1.out");

  fout << np1 << " " << np2 << std::endl;
  fout.close();

  return 0;
}
