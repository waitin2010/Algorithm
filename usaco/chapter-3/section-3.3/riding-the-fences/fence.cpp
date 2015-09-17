/*
  ID: come_1b1
  LANG: C++11
  TASK: fence
 */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>

// input
int f;


const int max_v = 501;
int nodes[max_v];
int adj[max_v][max_v];

// temp
int circuit_pos;
int start_node;

// output
const int max_circuit = 1024 + 1;
int circuit[max_circuit];

int neighbors_count( int node ){
  int nRet = 0;
  for( int i = 1; i <= max_v; ++i )
    if( adj[node][i] >= 1 )
      nRet++;
  //  std::cout << "nieghbors_count\t" << node << "\t" << nRet << std::endl;

  return nRet;
}

void delete_edges( int i, int j ){
  adj[i][j]--;
  adj[j][i]--;
}

int next_node( int node ){
  int nn = 0;
  for( int i = 1; i <= max_v; ++i ){
    if( adj[node][i] >= 1 ){
      nn = i;
      break;
    }
  }
  return nn;
}  
void find_circuit( int node ){
  #if 0
  std::cout << "find_circuit\t" << node << std::endl;
  std::cout << "Location:\t" << circuit_pos << std::endl;
  std::copy( std::begin( circuit ),
	     std::begin( circuit ) + circuit_pos,
	     std::ostream_iterator<int>(std::cout, " " ) );
  std::cout << std::endl;
  #endif
	     
  if( !neighbors_count( node ) ){
    circuit[circuit_pos++] = node;
  }else{
    while( neighbors_count( node ) ){
      int nn = next_node( node );
      delete_edges( nn, node );
      find_circuit( nn );
    }
    circuit[circuit_pos++] = node;
  }
}

int find_start_node( ){
  for( int i = 1; i < max_v; ++i ){
    int odd = 0;
    for( int j = 1; j <max_v; ++j ){
      if( adj[i][j] >= 1 )
	odd += adj[i][j];
    }
    if( odd % 2 == 1 )
      return i;
  }
  return 0;
}
  
void find_euler_circuit(){
  circuit_pos = 0;
  if( find_start_node() )
    start_node = find_start_node();
  find_circuit( start_node );
}


  
void solve(){
  find_euler_circuit();
}

void test_input(){
  for( int i = 1; i <= max_v; ++i ){
    for( int j = 1; j <= max_v; ++j ){
      if( adj[i][j] >= 1 )
	std::cout << i << " " << j << " " << adj[i][j] << std::endl;
    }
  }
}
    

int main(){
  std::ifstream fin("fence.in");
  fin >> f;
  start_node = max_v;
  for( int i = 0; i < f; ++i ){
    int a, b;
    fin >> a >> b;
    if( start_node > a )
      start_node = a;
    if( start_node > b )
      start_node = b;
    adj[a][b]++;
    adj[b][a]++;
  }
  fin.close();

  //  test_input();

  solve();
  
  std::ofstream fout("fence.out");
  #if 0
  std::copy( std::begin( circuit ),
	     std::begin( circuit ) + circuit_pos,
	     std::ostream_iterator<int>(fout, " " ) );
  #endif
  for( int i = circuit_pos - 1; i >= 0; --i )
    fout << circuit[i] << std::endl;
  fout.close();

  return 0;
}
