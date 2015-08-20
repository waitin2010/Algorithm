/*
  ID: come_1b1
  LANG: C++11
  TASK: lamps
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>

const int nLamps = 100 + 1;
int lamps[nLamps];
int buttons[4];

int n;
int c;

std::vector<std::string> result;


int LampStatus( int num )
{
  int status = 1;
  if( buttons[0] )
    status = 1 - status;
  if( buttons[1] && num % 2 == 0 )
    status = 1 - status;
  if( buttons[2] && num % 2 == 1 )
    status = 1 - status;
  if( buttons[3] && num % 3 == 1 )
    status = 1 - status;
  return status;
}

bool SomeLampsStatus( )
{
  for( int i = 1; i <= n; ++i ){
    if( lamps[i] != -1 && lamps[i] != LampStatus( i ) )
      return false;
  }
  return true;
}

void solve(int depth)
{
  if( depth >=4 ){
    int sum = std::accumulate( std::begin( buttons ),
			       std::end( buttons ),
			       0 );
    if( sum <= c && ( c - sum ) % 2 == 0 && SomeLampsStatus() ){
#if 0
      std::copy( std::begin( buttons),
		 std::end( buttons),
		 std::ostream_iterator<int>(std::cout," "));
      std::cout << std::endl;
#endif

      std::ostringstream strout;
      for( int i = 1; i <= n; ++i ){
	strout << LampStatus( i );
      }
      result.push_back( strout.str() );
    }
    return ;

  }

  for( int i = 0; i < 2; ++i ){
    buttons[depth] = i;
    solve( depth + 1 );
    buttons[depth] = 0;
  }
}


int main()
{
  std::transform( std::begin( lamps ),
		  std::end( lamps ),
		  std::begin( lamps ),
		  std::bind2nd( std::minus<int>(), 1) );

  std::ifstream fin( "lamps.in", std::ios::in );
  fin >> n >> c;
  int k;
  while( fin >> k && k != -1 ){
    lamps[k] = 1;
  }

  while( fin >> k && k != -1 ){
    lamps[k] = 0;
  }
  fin.close();

  #if 0
  std::copy( std::begin( lamps ) + 1,
	     std::begin( lamps ) + n,
	     std::ostream_iterator<int>( std::cout, " ") );
  std::cout << std::endl;
  #endif
  
  solve( 0 );

  std::ofstream fout( "lamps.out", std::ios::out );
  if( result.size() > 0 ){
    std::sort( result.begin(), result.end(), [](std::string a,std::string b) {
	return a < b;
      });
    
    std::copy( result.begin(),
	       result.end(),
	       std::ostream_iterator<std::string>( fout, "\n" ));
  }
  else
    fout << "IMPOSSIBLE" << std::endl;
	       
  return 0;
}
