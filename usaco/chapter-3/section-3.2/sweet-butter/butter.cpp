/*
  ID: come_1b1
  LANG: C++11
  TASK: butter
 */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <limits>
#include <iomanip>
int n,p,c;

const int max_n = 501;
int cows[max_n];

const int max_p = 801;
int adj[max_p][max_p];

int dist[max_p][max_p];

int ret = std::numeric_limits<int>::max();
int pindex = 0;
  
int max_val = std::numeric_limits<int>::max();

void print_dist(){
  std::cout << "\t";

  for( int i = 1; i <= p; ++i )
    std::cout << std::setw( 3) << i << " ";
  std::cout << std::endl;
  
  for( int i = 1; i <= p; ++i ){
    std::cout << i << "\t";
    for( int j = 1; j <= p; ++j ) {
      if( dist[i][j] == max_val )
	std::cout << std::setw( 3 ) << -1 << " ";
      else
	std::cout << std::setw(3 ) << dist[i][j] << " ";
    }
    std::cout << std::endl;
  }
}
  

void solve(){
  for( int i = 1; i <= p; ++i ){
    for( int j = 1; j <= p; ++j ) {
      if( i == j )
	dist[i][j] = 0;
      else 
	dist[i][j] = max_val;
      if( adj[i][j] != 0 )
	dist[i][j] = adj[i][j];
    }
  }

  //  print_dist();
  for( int k = 1; k <= p; ++k ){
    for( int i = 1; i <= p; ++i ){
      for( int j = i; j <= p; ++j ){
	if( dist[i][k] != max_val
	    && dist[k][j] != max_val
	    && dist[i][k] + dist[k][j] < dist[i][j] ){
	  dist[i][j] = dist[i][k] + dist[k][j];
	  dist[j][i] = dist[i][j];
	}
      }
    }
  }
  //  std::cout << "after algorith:" << std::endl;
  //  print_dist();

  
  for( int i = 1; i <= p; ++i ){
    int ret_temp = 0;
    for( int j = 1; j <= n; ++j ){
      if( dist[i][cows[j]] == max_val ){
	ret_temp = max_val;
	break;
      }
      ret_temp += dist[i][cows[j]];
    }
    //std::cout << i << "\tret_temp\t" << ret_temp << std::endl;
    if( ret > ret_temp ){
      ret = ret_temp;
      pindex = i;
    }
  }

  //  std::cout << ret << std::endl;
  //  std::cout << pindex << std::endl;
  
}

void print_input(){
  std::cout << n << " " << p << " " << c << std::endl;
  std::cout << "adj data:" << std::endl;
  for( int i = 1; i<=p; ++i ){
    for( int j = 1; j <= p; ++j ){
      std::cout << adj[i][j] << " ";
    }
    std::cout << std::endl;
  }
  
}

int main(){
  std::ifstream fin("butter.in");
  fin >> n >> p >> c;
  for( int i = 1; i <= n; ++i )
    fin >> cows[i];
  for( int i = 1; i <= p; ++i ){
    for( int j = 1; j <= p; ++j ){
      if( i != j )
	adj[i][j] = std::numeric_limits<int>::max();
      else
	adj[i][j] = 0;
    }
  }
  for( int i = 0; i < c; ++i ){
    int a,b,c;
    fin >> a >> b >> c;
    adj[a][b] = c;
    adj[b][a] = c;
  }
  fin.close();

  //  print_input();


  solve();

  std::ofstream fout("butter.out");
  fout << ret << std::endl;
  fout.close();

  return 0;
}
