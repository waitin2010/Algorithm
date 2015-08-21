/*
  ID: come_1b1
  LANG: C++11
  TASK: prefix
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>

int bn[200000+1];

std::string s = "";

int solve( std::vector<std::string> const&  p,
	   std::string const& s,
	   int i )
{
  int nResult = 0;
  for( auto it = p.begin();
       it != p.end();
       ++it )
    {
      if( i + it->size() < s.size() && (*it) == s.substr( i, it->size() ) ){
	if( bn[i+it->size()] == 0 )
	  bn[i+it->size()]= it->size() + solve( p, s, i + it->size() );
	if( nResult < bn[i+it->size()] )
	  nResult = bn[i+it->size()];
      }
    }

  return nResult;
}


int main()
{
  std::vector<std::string> p;

  
  std::ifstream fin( "prefix.in", std::ios::in );

  std::string t;
  while( fin >> t && t != "." )
    p.push_back( t );

  while( fin >> t )
    s += t;

  fin.close();
#if 0
  std::copy( p.begin(),
	     p.end(),
	     std::ostream_iterator<std::string>( std::cout, "\n" ) );
  std::cout << s << std::endl;
#endif
  std::cout << s.size() << std::endl;
  std::ofstream fout( "prefix.out", std::ios::out );
  fout << solve( p, s, 0 ) << std::endl;
  fout.close();
  
  return 0;
}
