/*
  ID: come_1b1
  LANG: C++11
  TASK: money
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>

int V;
int N;


const int max_v = 25;
int coins[max_v] = {0};

int num[max_v] = {0};

int count = 0;
int sum = 0;

const int max_n = 10000;
 long long ret[max_n] = {1};
 long long ret2[max_n] = {0};

void init();

long long solve2()
{
  init();

  for( int i = 0; i < V; i++ ){
    for( int j = 1;j <=num[i]; ++j ){
      int t = j * coins[i];
      for( int k = 0; k <= N - t; ++k ){
	  ret2[t+k] = ret[k] + ret2[t+k];
      }
    }
    std::copy( std::begin( ret2 ),
	       std::begin( ret2 ) + N + 1,
	       std::begin( ret ) );
      ret[0] = 1;
#if 0
      std::cout << i << " "
		<< num[i] << " "
		<< coins[i] << " "
		<<std::endl;
      std::copy( std::begin( ret ),
		 std::begin( ret ) + N + 1,
		 std::ostream_iterator<long long>(std::cout, " " ));
      std::cout << std::endl;
      #endif

  }
  return ret[N];
}
void init()
{
  for( int i = 0; i < V; ++i )
    if( coins[i] != 0 )
      num[i] = N/coins[i];
}

bool solve( int index ){
  #if 0
  std::cout << V << " " << N << std::endl;
  std::copy( std::begin( coins ),
	     std::begin( coins ) + V,
	     std::ostream_iterator<int>( std::cout, " " ));
  std::cout << std::endl;
  std::copy( std::begin( num ),
	     std::begin( num ) + V,
	     std::ostream_iterator<int>( std::cout, " " ) );
  std::cout << std::endl;
  #endif
  if( N == sum ){
    count++;
    return true;
  }
  if( sum > N || index == V  )
    return false;


  for( int i = 0; i <= num[index]; ++i ){
    sum += i * coins[index];
      if( solve( index + 1 ) ){
	sum-= i * coins[index];
	break;
      }
    sum -= i * coins[index];
    
  }
  return false;
}
int main()
{
  std::ifstream fin( "money.in", std::ios::in );
  fin >> V >> N;
  std::copy( std::istream_iterator<int>(fin),
	     std::istream_iterator<int>(),
	     std::begin(coins) );
  
  for( int i = 0; i < V; ++i )
    fin >> coins[i];
  fin.close();

  //init();
  //  solve( 0 );
  std::ofstream fout( "money.out", std::ios::out);
  fout << solve2() << std::endl;
  fout.close();

  //std::cout << solve2() << std::endl;
  //  std::cout << sizeof( long long ) << std::endl;
  return 0;
}
