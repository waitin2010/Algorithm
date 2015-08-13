/*
  ID: come_1b1
  LANG: C++
  TASK: frac1
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <utility>

int gcd( int a, int b ){
  return b ==0 ? a : gcd( b, a % b );
}

bool compare_func( const std::pair<int, int> &a,
		   const std::pair<int, int> &b )
{

  return float(a.first)/a.second < float(b.first)/b.second;
}

bool equal_func( const std::pair<int, int> &a,
		 const std::pair<int, int> &b )
{
  return a.first == b.first && a.second == b.second ;
}
		 

int main()
{
  std::vector<std::pair<int, int> > frac_list;
  typedef std::vector<std::pair<int, int> >::iterator IterType;
  frac_list.push_back( std::make_pair( 0, 1 ) );
  frac_list.push_back( std::make_pair( 1, 1 ) );

  std::ifstream fin( "frac1.in", std::ios::in );
  int N;
  fin >> N;


  for( int i = 1; i < N; ++i ){
    for( int j = N; j > i; --j ){
      int d = gcd( j, i );
      frac_list.push_back( std::make_pair( i / d , j / d ) );
    }
  }
  
  std::sort( frac_list.begin(), frac_list.end(), compare_func );
  
  IterType last = std::unique( frac_list.begin(), frac_list.end(), equal_func );
  frac_list.erase( last, frac_list.end() );

  std::ofstream fout( "frac1.out", std::ios::out );
  for( IterType it = frac_list.begin();
       it != frac_list.end();
       ++it)
    {
      fout << it->first << "/" << it->second << std::endl;
    }
  return 0;
}


