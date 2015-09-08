/*
 ID: come_1b1
 LANG: C++11
 TASK: agrinet
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>

int n;

const int max_n = 100;
int distance[max_n];
int intree[max_n];
int source[max_n];

int adj[max_n][max_n];

int solve( ){
  for( int i = 0; i < n; ++i ){
    distance[i] = 10e7;
    intree[i] = 0;
    source[i] = -1;
  }

  distance[0] = 0;
  intree[0] = 1;
  source[0] = -1;
  int tree_size = 1;
    

  for( int i = 1; i < n; ++i ){
    if( distance[i] > adj[0][i] ){
      distance[i] = adj[0][i];
      source[i] = 0;
    }
  }
  int old_index = 0;
  
  while( tree_size < n ){
    int index;
    int temp = 10e7;
    for( int i = 0; i < n; ++i ){
      if( !intree[i] && distance[i] < temp ){
	temp = distance[i];
	index = i;
      }
    }

    intree[index] = 1;
    source[index] = old_index;

    for( int i = 0; i < n; ++i ){
      if( !intree[i] && distance[i] > adj[index][i] ){
	distance[i] = adj[index][i];
	source[i] = index;
      }
    }

    old_index = index;
    tree_size++;
  }

  #if 0
  std::copy( std::begin( distance ),
	     std::begin( distance ) + n,
	     std::ostream_iterator<int>(std::cout, " ") );
  std::cout << std::endl;
  #endif
  
  return  std::accumulate( std::begin( distance ),
			   std::begin( distance ) + n,
			   0,
			   std::plus<int>() );
  #if 0
  std::cout << *std::max_element( std::begin( distance ),
				 std::begin( distance) + n ) << std::endl;
  #endif
      
    
}
int main(){

  std::ifstream fin("agrinet.in");
  fin >> n;
  for( int i = 0; i < n; ++i ){
    for( int j = 0; j < n; ++j ){
      fin >> adj[i][j];
    }
  }
  fin.close();

  #if 0
  for( int i = 0; i < n; ++i ){
    for( int j = 0; j < n; ++j ){
      std::cout << adj[i][j] << " ";
    }
    std::cout << std::endl;
  }
  #endif

  std::ofstream fout("agrinet.out");
  fout << solve() << std::endl;
  fout.close();
  
  return 0;
}

  
