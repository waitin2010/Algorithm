/*
  ID: come_1b1
  LANG: C++11
  TASK: camelot
 */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <iomanip>


int r, c;

const int max_rc = 30 * 26;
const int max_dist = 100000;

int kdist[max_rc];
int dist[max_rc][max_rc];
int kkdist[max_rc][max_rc];

int king;
int knight[max_rc];
int kcount = 0;

void king_short_path(){
  int rr = king / c;
  int cc = king % c;
  for( int i = 0; i < r * c; ++i){
    int ri = i / c;
    int ci = i % c;
    kdist[i] = std::max( std::abs( ri - rr ), std::abs( ci - cc ));
  }

  #ifdef FILE_OUT
  std::ofstream fout("kdist.out");
  for( int i = 0; i < r * c; ++i ){
    fout << kdist[i] << ( (i+1)%c==0?"\n":" ");
  }
  fout << std::endl;
  fout.close();
  #endif
}

  
void knight_short_path(){
  for( int i = 0; i < r * c; ++i ){
    for( int j = 0; j < r * c; ++j ){
      if( i == j )
	dist[i][j] = 0;
      else {
	int ri = i / c;
	int ci = i % c;
	int rj = j / c;
	int cj = j % c;
	if( ( ri - rj == 1 && ci - cj == 2 )
	    || ( ri - rj == 2 && ci - cj == 1 )
	    || ( ri - rj == 2 && cj - ci == 1 )
	    || ( ri - rj == 1 && cj - ci == 2 )
	    || ( rj - ri == 1 && cj - ci == 2 )
	    || ( rj - ri == 2 && cj - ci == 1 )
	    || ( rj - ri == 2 && ci - cj == 1 )
	    || ( rj - ri == 1 && ci - cj == 2 ) )
	  dist[i][j] = 1;
	else
	  dist[i][j] = max_dist;
      }
    }
  }
  
  for( int k = 0; k < r * c; ++k ){
    for( int i = 0; i < r * c; ++i){
      for( int j = 0; j < r * c; ++j){
	if( dist[i][k] + dist[k][j] < dist[i][j] ){
	  dist[i][j] = dist[i][k] + dist[k][j];
	}
      }
    }
  }
  #ifdef FILE_OUT
  std::ofstream fout("dist.out");
  for( int i = 0; i < kcount; ++i ){
    for( int j = 0; j < r * c; ++j ){
      fout << std::setw( 3 ) << dist[knight[i]][j] << ((j+1)%c==0?"\n":" ");
    }
    fout << std::endl;
  }
  fout.close();
  #endif
}

void king_knight_short_path(){
  for( int i = 0; i < r * c; ++i){
    for( int j = 0;j < r * c; ++j ){
    	kkdist[i][j] = max_dist;
    }
  }
  for( int i = 0; i < r * c; ++i){
    for( int j = 0; j < kcount; ++j ){
      for( int k = 0; k < r * c; ++k ){
	if( dist[knight[j]][i] + dist[i][k] + kdist[i] < kkdist[knight[j]][k] )
	  kkdist[knight[j]][k] = dist[knight[j]][i] + dist[i][k] + kdist[i];
      }
    }
  }

  #ifdef FILE_OUT
  std::ofstream fout("kkdist.out");
  for( int i = 0; i < kcount; ++i){
    for( int j = 0; j < r * c; ++j ){
      fout << kkdist[knight[i]][j] << ((j+1)%c==0?"\n":" ");
    }
    fout << std::endl;
  }
  fout.close();
  #endif
}

int solve(){
  king_short_path();
  knight_short_path();
  king_knight_short_path();

  int d = max_dist;
  for( int i = 0; i < r * c; ++i){
    int dd = 0;
    for( int j = 0; j < kcount; ++j ){
      dd += dist[i][knight[j]];
    }
    int ddd = max_rc;
    for( int k = 0; k < kcount; ++k ){
      int j = knight[k];
      if( kkdist[j][i] < dist[j][i] + kdist[i]){
	if( dist[j][i] + kdist[i] - kkdist[j][i] < ddd )
	  ddd = dist[j][i] + kdist[i] - kkdist[j][i];
	if( dist[j][i] == kkdist[j][i] )
	  ddd = 0;
      }
    }
    //    std::cout << i << " " << dd << " " << ddd << " " << kdist[i] << std::endl;
    if( ddd < kdist[i] ){
      dd += ddd;
    }
    else{
      dd += kdist[i];
    }
    if( dd < d ){
      d = dd;
      //  std::cout << i << " " << d << " " << dd  << std::endl;
    }
  }

  return d;
}

int main(){
  std::ifstream fin("camelot.in");
  fin >> r >> c;
  fin.get();
  bool first = true;
  int ch;
  int rr, cc;
  int count = 0;
  while( (ch = fin.get()) != EOF ){
    if( isdigit( ch ) ){
      rr = rr * 10 + ch - '0';
      count++;
    }else if( ch >= 'A' && ch <= 'Z' ){
      cc = ch - 'A';
      count++;
    }else if( (ch == ' ' || ch == '\n' ) && count >= 2 ){
      --rr;
      if( first ){
	king = rr * c + cc;
	first = false;
      }else{
	knight[kcount++] = rr * c + cc;
      }
      rr = 0;
      cc = 0;
      count = 0;
    }
  }
#if 0
  std::cout << "king at\t" << king / c << " " << king % c << std::endl;
  for( int i = 0; i < kcount; ++i ){
    std::cout << knight[i] / c << " " << knight[i] % c << std::endl;
  }
  #endif

  std::ofstream fout("camelot.out");
  fout << solve() << std::endl;
  fout.close();
  
  return 0;
}
  
