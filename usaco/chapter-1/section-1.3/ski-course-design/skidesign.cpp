/*
ID: come_1b1
LANG: C++
TASK: skidesign
 */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <iterator>

const int MAX_N = 1000 + 1;
int N;
std::vector<std::pair<int,int> > hill_data;

void print()
{
  static int n = 0;
  std::cout << std::endl << std::endl;
  std::cout << "the nth:" << n++ << std::endl;
    for( int i = 0; i < N; ++i ){
    std::cout << hill_data[i].first << " " << hill_data[i].second << std::endl;
  }

}

bool compare_hill_data( const std::pair<int,int> &a,
			const std::pair<int,int> &b )
{
  if( a.first == b.first )
    return a.second < b.second;
  return a.first < b.first;
}

bool compare_hill_data_2( const std::pair<int, int> &a,
			  const std::pair<int, int> &b )
{
  return a.second > b.second;
}

void sort_hill_data()
{
  std::sort( hill_data.begin(), hill_data.end(), compare_hill_data );

  int i;
  for( i = N - 2; i >=0; --i )
    if( hill_data[i].first != hill_data[N-1].first )
      break;
  //  std::cout << i << "----" << hill_data[i].first << std::endl;
  std::sort( &hill_data[i+1], &hill_data[i+1] + N - i, compare_hill_data_2 );
}
int solve()
{

  sort_hill_data();

    print();

  while( hill_data[N-1].first - hill_data[0].first >= 18 ){
    hill_data[N-1].first--;
    hill_data[0].first++;
    hill_data[N-1].second++;
    hill_data[0].second++;
    sort_hill_data();

    print();
  }
  
  int result = 0;
  for( int i = 0; i < N; ++i ){
    result += hill_data[i].second * hill_data[i].second;
  }

  return result;
    
}
int main()
{
  std::ifstream fin("skidesign.in", std::ios::in );

  fin >> N;
  for( int i = 0; i < N; ++i ){
    int a;
    fin >> a;

      hill_data.push_back( std::make_pair( a, 0 ) );
  }


  std::ofstream fout("skidesign.out", std::ios::out );
  fout << solve() << std::endl;

  return 0;
  
}
