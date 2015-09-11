/*
  ID: come_1b1
  LANG: C++11
  TASK: contact
 */
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cstring>

std::ofstream fout;

int a, b, n;

const int max_a = 13;
const int max_s = 0x1 << 13;

char str[200010];
int count[max_a][max_s];
int base2[max_a] = { 0x1,
		     0x1 << 1,
		     0x1 << 2,
		     0x1 << 3,
		     0x1 << 4,
		     0x1 << 5,
		     0x1 << 6,
		     0x1 << 7,
		     0x1 << 8,
		     0x1 << 9,
		     0x1 << 10,
		     0x1 << 11,
		     0x1 << 12 };
struct Ret{
  int x;
  int num;
  int c;
}ret[max_s];

bool compareRet( const struct Ret &a,
		 const struct Ret &b )
{
  return a.c > b.c;
}

std::ostream& operator << ( std::ostream &out, const struct Ret &a )
{
  //  out << a.num << " " << a.c << std::endl;
  int t = a.num;
  int tt = 0x1 << ( a.x - 1 );
  for( int i = 0; i < a.x; ++i ){
    out << (t & tt ? '1' : '0');
    t = t << 1;
  }
  return out;
}

void solve_x( int x ){
  char *p = str;
  char *q = str + x;

  int i = 0;
  int num = 0;
  while ( i < x ){
    num = num * 2 + str[i] - '0';
    ++i;
  }

  count[x][num]++;
  
  while( *q != '\0' ){
    num = num * 2 + *q - '0' - ( *p - '0' ) * (0x1 << x );
    count[x][num]++;
    q++;
    p++;
  }
  
}

void solve( ){

  for( int i = a; i <=b; ++i )
    solve_x ( i );

  int k = 0;
  for( int i = a; i <= b; ++i ){
    int m = 0x1 << i;
    //    std::cout << m << std::endl;
    for( int j = 0; j < m; ++j ){
      ret[k].x = i;
      ret[k].num = j;
      ret[k].c = count[i][j];
      ++k;
    }
  }

  std::stable_sort( std::begin( ret ),
		    std::end( ret ),
		    compareRet );
  #if 0
  std::copy( std::begin( ret ),
	     std::begin( ret ) + n,
	     std::ostream_iterator<struct Ret>( std::cout, "\n" ) );
  #endif

  for( int i = 0, j = 0; i < n ; ++i ) {
    if( ret[j].c == 0 )
      break;
    int c = ret[j].c;
    fout << c << std::endl;

    int ccc = 0;
    bool first = true;
    while( ret[j].c == c ){
  if( ccc++ % 6 == 0 ){
  if( !first )
	fout << std::endl;
  first = false;
	
}
      else if( ccc > 1 )
	fout << " ";
      fout << ret[j];
      ++j;
    }
    fout << std::endl;
  }
	     
  
}


int main(){
  std::ifstream fin( "contact.in" );
  fin >> a >> b >> n;
  fin.get();
  int c;
  char *p = str;
  while( (c = fin.get()) != EOF ){
    //std::cout << char(c) << std::endl;
    if( c != '\n' )
      *p++ = c;
  }
  *p = '\0';
  //  std::cout << a << b << n << std::endl;
  //  std::cout << str << std::endl;
  fin.close();

  
  fout.open( "contact.out" );
  solve();

  return 0;
}
