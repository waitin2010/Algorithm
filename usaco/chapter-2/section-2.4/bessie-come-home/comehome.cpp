/* 
   ID: come_1b1
   LANG: C++11
   TASK: comehome
 */

#include <iostream>
#include <fstream>
#include <algorithm>

const int max_n = 256;
int distance[256];
int visited[256];
int parent[256];

const int max_e = 10000 + 1;
struct Edge{
  int i;
  int j;
  int d;
}edge[max_e];

const int max_dist = 10e8;

int nodes_visited = 0;
int graph_size = 0;
int n;
bool nodes[256];


std::ofstream fout;

std::ostream& operator << ( std::ostream &out, struct Edge const & e ){
  out << e.i << " " << e.j << " " << e.d;
  return out;
}

void solve()
{
  for( int i = 0; i < 256; ++i ){
    distance[i] = max_dist;
    visited[i] = 0;
    parent[i] = 0;
  }

  for( int i = 0; i < n; ++i ){
    if( !nodes[edge[i].i] ){
      graph_size++;
      nodes[edge[i].i] = true;
    }
    if( !nodes[edge[i].j] ) {
      graph_size++;
      nodes[edge[i].j] = true;
    }
  }

  std::cout << graph_size << std::endl;
  
  distance['Z']=0;
  parent['Z'] = 0;

  int node = 'Z';
  int next_node;
  while( nodes_visited++ < graph_size ){
    int temp_min = max_dist;
    for( int i = 0; i < n; ++i ){
      if( node == edge[i].i && !visited[edge[i].j]
	  && distance[node] + edge[i].d < distance[edge[i].j] ){
	distance[edge[i].j] = distance[node] + edge[i].d;
	parent[edge[i].j] = node;
      }else if( node == edge[i].j && !visited[edge[i].i]
		&& distance[node] + edge[i].d < distance[edge[i].i] ){
	distance[edge[i].i] = distance[node] + edge[i].d;
	parent[edge[i].i] = node;
	}
      }
    for( int i = 0; i < 256; ++i ){
      if( !visited[i] && distance[i] < temp_min ){
	temp_min = distance[i];
	next_node = i;
      }
    }
    visited[next_node] = 1;
    node = next_node;
  }
  #if 0
  for( int i = 0; i < 256; ++i ){
    if( i >= 'A' && i <= 'Z' && distance[i] < max_dist )
      std::cout << char(i) << " " << distance[i] << std::endl;
    if( i >= 'a' && i <= 'z' && distance[i] < max_dist )
      std::cout << char(i) << " " << distance[i] << std::endl;
  }
  #endif
  int   temp_min = max_dist;
  char ret = 'Z';
  for( char i = 'A'; i <'Z'; ++i ){
    if( distance[i] < temp_min ){
      temp_min = distance[i];
      ret = i;
      std::cout << "ret" << ret << std::endl;
    }
    //std::cout << i << std::endl;
  }

  fout.open( "comehome.out", std::ios::out );

  fout << ret << " " << temp_min << std::endl;
  fout.close();
  
}


int main()
{
  std::ifstream fin( "comehome.in", std::ios::in );
  fin >> n;
  for( int i = 0; i < n; ++i ){
    char c1, c2;
    fin >> c1;
    fin.get();
    fin >> c2;
    edge[i].i = c1;
    edge[i].j = c2;
    fin >> edge[i].d;
    fin.get();
  }

  #if 0
  for( int i = 0; i < n; ++i ){
    std::cout << edge[i] << std::endl;
  }
  #endif

  solve();
  
  return 0;
}
