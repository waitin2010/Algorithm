/*
  ID:come1_b1
  LANG: C++
  TASK: holstein
*/

#include <iostream>
#include <fstream>


int V;
const int max_v = 25;
int vitamins[max_v];

int G;
const int max_g = 15;
int scoop[max_g][max_v];

int nscoop;
int iscoop[max_g];
int ascoop[max_v];

bool solve( int start, int depth, int cur_d ){
  if( cur_d <= 0 ){
    for( int i = 0; i < V; ++i ){
      if( ascoop[i] < vitamins[i] ){
	//	std::cout << ascoop[i] << " " << vitamins[i] <<std::endl;
	return false;
      }
    }
    //    std::cout << depth << " " << cur_d << std::endl;
    return true;
  }
  
  for( int i = start; i < G; ++i ){
    iscoop[depth-cur_d] = i + 1;
    for( int j = 0; j < V; ++j ){
      ascoop[j] += scoop[i][j];
    }
    if( solve( i + 1, depth, cur_d - 1 ) )
      return true;
    for( int j = 0; j < V; ++j ){
      ascoop[j] -= scoop[i][j];
    }
    iscoop[depth-cur_d] = 0;
  }

  return false;
}
int main( )
{
  std::ifstream fin( "holstein.in", std::ios::in );
  fin >> V;
  for( int i = 0; i < V; ++i )
    fin >> vitamins[i];

  fin >> G;

  for( int i = 0; i < G; ++i ){
    for( int j = 0; j < V; ++j ) {
      fin >> scoop[i][j];
    }
  }

  int i;
  for(  i = 0; i <G; ++i ){
    if( solve( 0, i + 1, i + 1 ) ){
      break;
    }
  }

  std::ofstream fout( "holstein.out", std::ios::out );
  fout << i + 1;
  for( int j = 0; j < i + 1; ++j )
    fout << " " << iscoop[j];
  fout << std::endl;

  
  #if 0
  std::cout <<  V << std::endl;
  for( int i = 0; i < V; ++i ){
    std::cout << vitamins[i] << " ";
  }
  std::cout << std::endl;

  std::cout << G << std::endl;

  for( int i = 0; i < G; ++i ){
    for( int j = 0; j < V; ++j ) {
      std::cout << scoop[i][j] << " ";
    }
    std::cout << std::endl;
  }

  #endif

  return 0;
}

  
