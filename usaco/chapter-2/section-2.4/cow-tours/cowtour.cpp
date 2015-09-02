/*
  ID: come_1b1
  LANG: C++11
  TASK: cowtour
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <cmath>

int N;
const int max_n = 150;

struct Point{
  float x;
  float y;
}point[max_n];

float weight[max_n][max_n];
float dist[max_n][max_n];

float distance( struct Point &p1,
		struct Point &p2 )
{
  return std::sqrt( ( p2.x - p1.x ) * (p2.x - p1.x )
		    + (p2.y - p1.y ) * (p2.y - p1.y ) );
}

bool isConnect( float f )
{
  return ( std::numeric_limits<float>::max() - f ) / std::numeric_limits<float>::max() > std::numeric_limits<float>::epsilon();
}
int main()
{
  std::ifstream fin("cowtour.in", std::ios::in);
  fin >> N;
  for( int i = 0; i < N; ++i )
    fin >> point[i].x >> point[i].y;
  fin.get();
  for( int i = 0; i < N; ++i ){
    char buf[max_n+1];
    fin.getline( buf, max_n + 1 );
    for( int j = 0; j < N; ++j )
      if( buf[j] == '1' )
	weight[i][j] = distance( point[i], point[j] );
  }

  for( int i = 0; i < N; ++i ){
    for( int j = 0; j < N; ++j ){
      //std::cout << std::setw(4) << weight[i][j] << " ";
      dist[i][j] = weight[i][j]?weight[i][j]:std::numeric_limits<float>::max();
      if( i == j )
	dist[i][j] = 0;
    }
    //  std::cout << std::endl;
  }

  for( int k = 0; k < N; ++k ){
    for( int i = 0; i < N; ++i ){
      for( int j = 0; j < N; ++j ){
	if( dist[i][k] + dist[k][j] < dist[i][j] )
	  dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }
#if 0
  for( int i = 0; i < N; ++i ){
    for( int j = 0; j < N; ++j ){
      std::cout << std::setw(4) << dist[i][j] << " ";
    }
    std::cout << std::endl;
  }
#endif

  float ret = std::numeric_limits<float>::max();
  for( int i = 0; i < N; ++i ){
    for( int j = i + 1; j < N; ++j ){
      if( isConnect( dist[i][j] ) ){
	continue;
      }
      float d = distance( point[i], point[j] );
      std::cout << "distance" << d << std::endl;
      float temp_ret = 0.0;
      for( int i1 = 0; i1 < N; ++i1 ){
	for( int j1 = 0; j1 < N; ++j1 ){
	  if( isConnect( dist[i1][i] )
	      && isConnect( dist[j][j1] )
	      && dist[i1][i] + d + dist[j][j1] > temp_ret ){
	    temp_ret = dist[i1][i] + d + dist[j][j1];
	    #if 0
	    std::cout << i1 << " " << i << " "
		      << j << " " << j1 << " "
		      << d << " "
		      << temp_ret << " "
		      << ret << std::endl;
	    #endif
	  }
	}
      }
      if( temp_ret < ret )
	ret = temp_ret;
      std::cout << i << " " << j << " " << temp_ret << " " << ret << std::endl << std::endl;
	    
    }
  }

  
  //  std::cout << "max ret" << std::fixed << std::setprecision(6) << ret << std::endl;
  std::ofstream fout("cowtour.out", std::ios::out);
  fout << std::fixed << std::setprecision(6) << ret << std::endl;
  fout.close();
  return 0;

  
  
}
