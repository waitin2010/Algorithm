/*
 ID: come_1b1
 LANG: C++11
 TASK: range
 */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <vector>

int n;
std::vector<std::string> grid;

const int max_n = 250;
int grid_row[max_n][max_n];
int grid_col[max_n][max_n];
int grid_ret[max_n][max_n];

int ret[max_n + 1];

void print_input(){
  std::copy( grid.begin(),
	     grid.end(),
	     std::ostream_iterator<std::string>( std::cout, "\n") );
  
}

void print_grid_data( int array[][max_n]){
  for( int i = 0; i < n; ++i ){
    std::copy( std::begin( array[i] ),
	       std::begin( array[i] ) + n,
	       std::ostream_iterator<int>( std::cout, " " ) );
    std::cout << std::endl;
  }
  std::cout << std::endl;
}

void print_ret( ){
  std::cout << "ret:" << std::endl;
  std::copy( std::begin( ret ),
	     std::begin( ret ) + n,
	     std::ostream_iterator<int>( std::cout, "\n" ) );
  std::cout << std::endl;
}

void solve(){
  for( int i = 0; i < n; ++i){
    for( int j = 0; j < n; ++j ){
      grid_row[i][j] = grid_col[i][j] = grid[i][j] - '0';
      if( i == 0 || j == 0 )
	grid_ret[i][j] = grid_row[i][j];
    }
  }

  for( int i = 0; i < n; ++i ){
    for( int j = 1; j < n; ++j ){
      if( grid_col[i][j] != 0 && grid_col[i][j-1] != 0 )
	grid_col[i][j] += grid_col[i][j-1];
    }
  }
  for( int j = 0; j < n; ++j ){
    for( int i = 1; i < n; ++i ){
      if( grid_row[i][j] != 0 && grid_row[i-1][j] != 0 )
	grid_row[i][j] += grid_row[i-1][j];
    }
  }

  for( int i = 1; i < n; ++i){
    for( int j = 1; j < n; ++j ){
      int ret = grid_ret[i-1][j-1] + 1;
      ret = std::min( ret, grid_col[i][j] );
      ret = std::min( ret, grid_row[i][j] );
      grid_ret[i][j] = ret;
    }
  }

  for( int i = 0; i < n; ++i){
    for( int j = 0; j < n; ++j ){
      ret[grid_ret[i][j]]++;
    }
  }

  for( int i = n-1; i >= 2; --i ){
    ret[i] += ret[i+1];
  }
}

int main(){
  std::ifstream fin("range.in");
  fin >> n;
  for( int i = 0; i < n; ++i){
    std::string str;
    fin >> str;
    grid.push_back(str);
  }

  solve();

  #if 0
  print_grid_data( grid_row );
  print_grid_data( grid_col );
  print_grid_data( grid_ret );

  print_ret();
  #endif

  std::ofstream fout("range.out");
  for( int i = 2; i <= n; ++i ){
    if( ret[i] == 0 )
      break;
    fout << i << " " << ret[i] << std::endl;
  }
  return 0;
}

