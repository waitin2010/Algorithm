/*
ID: come_1b1
LANG: C++
TASK: skidesign
 */

#include <fstream>
#include <vector>
#include <algorithm>




int main()
{
  std::ifstream fin("skidesign.in", std::ios::in );

  int N;
  std::vector<int> hill_height_data;
  fin >> N;
  for( int i = 0; i < N; ++i ) {
    int hill_height;
    fin >> hill_height;
    hill_height_data.push_back( hill_height );
  }

  int max_hill_height = *std::max_element( hill_height_data.begin(),
					  hill_height_data.end() );
  int min_hill_height = *std::min_element( hill_height_data.begin(),
					 hill_height_data.end() );

  int ret = 0x7FFFFFFF;
  for( int i = min_hill_height; i<= max_hill_height; ++i ){
    int ret_temp = 0;
    for( int j = 0; j < N; ++j ) {
      if( hill_height_data[j] < i )
	ret_temp += ( i - hill_height_data[j] ) * ( i - hill_height_data[j] );
      if( hill_height_data[j] > i + 17 )
	ret_temp += ( hill_height_data[j] - i - 17 ) *
	  ( hill_height_data[j] - i - 17 );
    }
    ret = std::min( ret_temp, ret );
  }

  std::ofstream fout("skidesign.out", std::ios::out );

  fout << ret << std::endl;

  return 0;


    
  
}
