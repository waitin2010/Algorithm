/*
  ID: come_1b1
  LANG: C++11
  TASK: ttwo
 */

#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

std::ofstream fout;

std::vector<std::string> forest;

int fd = 0;
int cd = 0;
int x_dir[] = { -1, 0, 1,  0 };
int y_dir[] = {  0, 1, 0, -1 };

int fc;
int cc;
std::vector<int> f_p;
std::map<int, int> f_path;

std::vector<int> c_p;
std::map<int, int> c_path;


int find_pos( char const &c)
{
  for( int i = 0; i < 10; i++ )
    for( int j = 0; j < 10; ++j )
      if( forest[i].at(j) == c )
	return  i * 10 + j ;
  return -1;
}

int next_step( int &c )
{
  int i = c % 100 / 10;
  int j = c % 10;
  int d = c / 100;

  //  std::cout << i << " " << j << " " << d << std::endl;
  if( i + x_dir[d] < 0
      || i + x_dir[d] > 9
      || j + y_dir[d] < 0
      || j + y_dir[d] > 9
      || forest[i+x_dir[d]].at(j+y_dir[d]) == '*' )
    return (++d)%4 * 100 + i * 10 + j * 1;
  else
    return  d * 100 + ( i + x_dir[d] ) * 10 + j + y_dir[d];
}

void simulation( int &c,
		 std::vector<int> &vp,
		 std::map<int, int> &path )
{

  do {
    path.insert( std::make_pair(c, vp.size() ));
    vp.push_back( c );
    c = next_step( c );
  }while( path.find( c) == path.end() );

  vp.push_back( c );
#if 0
  for( auto it = path.begin();
       it != path.end();
       ++it){
    int i = it->first;
    std::cout << it->second << ":";
    std::cout << (i % 100) / 10 << " "
	     <<  i % 10 << " "
	      << i / 100 << std::endl;
  }
  int j = 0;
  for( auto it = vp.begin();
       it != vp.end();
       ++it )
    {

      int i = *it;
      std::cout << j++ << ":";
      std::cout << (i % 100) / 10 << " "
		<<  i % 10 << " "
		<< i / 100 << std::endl;

    }

  std::cout << path[vp[vp.size()-1]] << std::endl;
  #endif
	     
}

int process()
{
  int iff = 0;
  int icc = 0;
  for( int i = 0; i< 100 * 100; ++i )
    {
      
      if( iff > f_p.size() - 2 ){
	std::cout << "iff:" << iff << std::endl;
	iff = f_path[f_p[f_p.size() - 1]];
	std::cout << "after iff:" << iff << std::endl;
      }
      if( icc > c_p.size() - 2 )
	icc = c_path[c_p[c_p.size() - 1]];

      int i1,j1;
      int i2,j2;
      i1 = f_p[iff] % 100 / 10;
      j1 = f_p[iff] % 10;

      i2 = c_p[icc] % 100 / 10;
      j2 = c_p[icc] % 10;

      if( i1 == i2 && j1 == j2 )
	return i;

      iff++;
      icc++;
    }
  return 0;
}
void solve()
{
  fc = find_pos( 'F' );
  cc = find_pos( 'C' );

  simulation( fc, f_p, f_path );
  simulation( cc, c_p, c_path );

  fout << process() << std::endl;
}

int main()
{
  std::ifstream fin( "ttwo.in", std::ios::in );
  int i = 0;
  std::copy( std::istream_iterator<std::string>( fin ),
	     std::istream_iterator<std::string>(),
	     std::back_inserter( forest ) );
#if 0
  std::copy( std::begin( forest ),
	     std::end( forest ),
	     std::ostream_iterator<std::string>( std::cout, "\n" ) );

  std::cout << forest[i].at(i) << std::endl;
#endif

  fout.open( "ttwo.out", std::ios::out);
  solve();
  fout.close();
  return 0;
}
