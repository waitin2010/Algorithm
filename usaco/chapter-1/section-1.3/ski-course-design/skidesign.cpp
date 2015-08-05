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

const int MAX_N = 1000 + 10;

int N;
int hill[MAX_N];

void print()
{
  for( int i = 0; i < N; ++i )
    std::cout << hill[i] << " ";
  std::cout << std::endl;
}
int solve()
{
  int result = 0;

  std::sort(hill, hill + N );
  print();
  while( hill[N-1] - hill[0] > 18 ){
    hill[N-1]--;
    hill[0]++;
    std::sort(hill, hill + N );
    print();
    result++;
  }
  return 2 * result * result;
}
int main()
{
  std::ifstream fin("skidesign.in", std::ios::in );
  fin >> N;
  int count = 0;
  for( int i = 0; i < N; ++i ){
    int a;
    fin >> a;
    if( a != 0 )
      hill[count++] = a;
  }
  N = count++;

  std::ofstream fout("skidesign.out", std::ios::out );
  fout << solve() << std::endl;

  return 0;
  
}
