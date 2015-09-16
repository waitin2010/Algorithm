/*
  ID: come_1b1
  LANG: C++11
  TASK: msquare
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <map>
#include <queue>
#include <vector>

std::map<int,std::pair<int, char> > val;
std::queue<int> q;
std::vector<char> ret;

int target;

int step_count;

int do_a( int n ){
  int a1 = n / 10000000 % 10;
  int a2 = n / 1000000 % 10;
  int a3 = n / 100000 % 10;
  int a4 = n / 10000 % 10;
  int a5 = n / 1000 % 10;
  int a6 = n / 100 % 10;
  int a7 = n / 10 % 10;
  int a8 = n / 1 % 10;

  return a8 * 10000000 +
    a7 * 1000000 +
    a6 * 100000 +
    a5 * 10000 +
    a4 * 1000 +
    a3 * 100 +
    a2 * 10 +
    a1;
}

int do_b( int n ){
  int a1 = n / 10000000 % 10;
  int a2 = n / 1000000 % 10;
  int a3 = n / 100000 % 10;
  int a4 = n / 10000 % 10;
  int a5 = n / 1000 % 10;
  int a6 = n / 100 % 10;
  int a7 = n / 10 % 10;
  int a8 = n / 1 % 10;

  return a4 * 10000000 +
    a1 * 1000000 +
    a2 * 100000 +
    a3 * 10000 +
    a6 * 1000 +
    a7 * 100 +
    a8 * 10 +
    a5;
}

int do_c( int n ){
  int a1 = n / 10000000 % 10;
  int a2 = n / 1000000 % 10;
  int a3 = n / 100000 % 10;
  int a4 = n / 10000 % 10;
  int a5 = n / 1000 % 10;
  int a6 = n / 100 % 10;
  int a7 = n / 10 % 10;
  int a8 = n / 1 % 10;

  return a1 * 10000000 +
    a7 * 1000000 +
    a2 * 100000 +
    a4 * 10000 +
    a5 * 1000 +
    a3 * 100 +
    a6 * 10 +
    a8;
}

void test_abc(){
#if 0
  std::cout << "a" << do_a( 12345678 ) << std::endl;
  std::cout << "b" << do_b( 12345678 ) << std::endl;
  std::cout << "c" << do_c( 12345678 ) << std::endl;
#endif
}

void solve(){
  q.push(12345678);
  while( 1 ){
    int t = q.front();
    q.pop();

    int temp = do_a( t );
    if( val.find( temp ) == val.end() ){
      val.insert( std::make_pair( temp, std::make_pair( t, 'A' ) ) );
      q.push( temp );
    }
    if( temp == target )
      break;
    
    temp = do_b( t );
    if( val.find( temp ) == val.end() ){
      val.insert( std::make_pair( temp, std::make_pair( t, 'B' ) ) );
      q.push( temp );
    }
    if( temp == target )
      break;
    
    temp = do_c( t );
    if( val.find( temp ) == val.end() ){
      val.insert( std::make_pair( temp, std::make_pair( t, 'C' ) ) );
      q.push( temp );
    }
    if( temp == target )
      break;
  };

  int temp = target;
  while( temp != 12345678 ){
    
    auto it = val.find( temp );
    ret.push_back( it->second.second );
    temp = it->second.first;
    step_count++;
  }

  #if 0
  std::cout << step_count << std::endl;
  std::copy( ret.rbegin(),
	     ret.rbegin() + step_count,
	     std::ostream_iterator<char>(std::cout,""));
  std::cout << std::endl;
  #endif
  
  

  
}

int main(){
  std::ifstream fin("msquare.in");
  for( int i = 0; i < 8; ++i ){
    int a;
    fin >> a;
    target = target * 10 + a;
  }
  fin.close();

  solve();

  std::ofstream fout("msquare.out");
  fout << step_count << std::endl;
  std::copy( ret.rbegin(),
	     ret.rbegin() + step_count,
	     std::ostream_iterator<char>(fout,""));
  fout << std::endl;

  fout.close();

  return 0;
}
		    
