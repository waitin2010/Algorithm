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

char seq[max_s][max_a];
char temp[max_a];
int count = 0;

char str[200010];
struct Num{
  int i;
  int c;
}num[max_s];

bool compareNum( const struct Num &a,
		 const struct Num &b )
{
  return a.c > b.c;
}

void gen_n( int i, int n, char *p){
  if( i < n ){
    for( int j = 0; j < 2; ++j ){
      *p = '0' + j;
      gen_n( i + 1, n, p+1 );
      *p = '\0';
    }
  }else{
    strncpy( seq[count], temp, n );
    count++;
  }
}

void init(){
  for( int i = a; i <=b; ++i )
    gen_n( 0, i, temp );
  
#if 0  
  for( int i = 0; i < count; ++i )
    std:: cout << i << " .... " << seq[i] << std::endl;

  std::copy( std::begin( seq ),
	     std::begin( seq ) + count,
	     std::ostream_iterator<char*>( std::cout, "\n" ) );
#endif
}

int solve_x( int x ){
  int ret = 0;
  int len = strlen( seq[x] );

for( int i = 0; i <= std::max( -1, int(strlen( str ) - len )); ++i ){

    int j = 0;
    for( j = 0; j < len; ++j ){
      if( str[i+j] != seq[x][j] ){
	break;}
    }
    if( j >= len )
      ret++;
  }
  return ret;
}

void computeLPSArray( char *pat, int M, int *lps ){
  int len = 0;
  int i;

  lps[0] = 0;
  i = 1;

  while ( i < M ){
    if( pat[i] == pat[len] ){
      len++;
      lps[i] = len;
      i++;
    }else {
      if( len != 0 ){
	len = lps[len-1];
      }else{
	lps[i] = 0;
	++i;
      }
    }
  }
}

int KMPSearch( char *pat, char *txt ){

  
  int ret = 0;

  #if 1
  int M = strlen( pat );
  int N = strlen( txt );

  //  int *lps = (int * ) malloc( sizeof( int ) * M );
  int lps[14];
  int j = 0;

  computeLPSArray( pat, M, lps );

  int i = 0;
  while( i < N ){
    if( pat[j] == txt[i] ){
      ++j;
      ++i;
    }

    if( j == M ){
      ++ret;
      j = lps[j-1];
    }else if( i < N && pat[j] != txt[i] ){
      if( j != 0 )
	j = lps[j-1];
      else
	i = i+1;
    }
  }
  //  free(lps);
  return ret;
  #endif
}
    

    
      
  
void solve( ){
  for( int i = 0; i < count; ++i ){
    num[i].i = i;
    //num[i].c = solve_x( i );
    num[i].c = KMPSearch( seq[i], str );
  }
  std::cout << strlen( str ) << " " << count  << std::endl;

  std::stable_sort( std::begin( num ),
	     std::begin( num ) + count,
	     compareNum );

  for( int i = 0,j = 0; i < n && i < count; ++i  ){
if( num[j].c == 0 )
  break;
    int c = num[j].c;
    fout << num[j].c << std::endl;

    int cc = 1;
    while( num[j].c == c ){
      if( cc++ % 6 == 0 )
	fout << std::endl;
      else if( cc >2 )
	fout << " ";
fout << seq[num[j].i];
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

  init();

  fout.open( "contact.out" );
  solve();

  return 0;
}
