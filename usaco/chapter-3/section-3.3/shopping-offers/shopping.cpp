/*
  ID: come_1b1
  LANG: C++11
  TASK: shopping
 */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>

int s;

const int max_s = 99 + 1;
int ss[max_s][12];

int b;
const int max_b = 5 + 1;
int bb[max_b][3];

int mmap[10000];

int mcount = 1;
int mm[55556];
int m[55556];

void test_input(){
  for( int i = 0; i < s; ++i ){
    std::cout << ss[i][0];
    for( int j = 1; j <= ss[i][0] * 2; j += 2 )
      std::cout << " " << ss[i][j] << " " << ss[i][j+1];
    std::cout << " " << ss[i][ss[i][0] * 2 + 1] << std::endl;
  }

  for( int i = 0; i < b; ++i ){
    std::cout << bb[i][0] << " " << bb[i][1] << " " << bb[i][2] << std::endl;
  }
  for( int i = 0; i < b; ++i ){
    std::cout << mmap[bb[i][0]] << std::endl;
  }
}

void Init(){
  for( int i = 0; i < s; ++i ){
    int k[max_b] = { 0, 0, 0, 0, 0, 0 };
    int v[max_b] = { 0, 0, 0, 0, 0, 0 };
    int p = ss[i][0];
    int val = ss[i][ss[i][0]*2+1];
    int t = 1;
    for( int j = 1; j <= p * 2; j+=2 ){
      if( mmap[ss[i][j]] != 0 ){
	k[t] = mmap[ss[i][j]];
	v[t] = ss[i][j+1];
	++t;
      }else{
	break;
      }
    }
    //    std::cout << t << " " << ss[i][0] << std::endl;
    if( t < ss[i][0] )
      continue;
    #if 0
    std::cout << "k" << std::endl;
    for( int i = 0; i < max_b; ++ i )
      std::cout << k[i] << " ";
    std::cout << std::endl;
    std::cout << "v" << std::endl;
    for( int i = 0; i < max_b; ++i )
      std::cout << v[i] << " ";
    std::cout << std::endl;
    std::cout << "val:\t" << val << std::endl;
    #endif

    t = 0;
    for( int j = 1; j <= 5; ++j ){
      int tt = 1;
      for( int i = 1; i <= 5 - k[j]; ++i )
	tt *= 10;
      t = t + tt * v[j];
    }

    for( int i = 0; i < mcount; ++i ){
      if( mm[i] + t <= 55555 ){
	if( m[mm[i]+t] == 0 )
	  mm[mcount++] = mm[i] + t;
	if( m[mm[i] + t ] == 0 )
	  m[mm[i]+t] = m[mm[i]] + val;
	else
	  m[mm[i]+t] = std::min( m[mm[i]] + val, m[mm[i]+t] );
      }
    }
    //std::cout << "End \t" << i << std::endl;
      
  }

  #if 0
  std::cout << "Result" << std::endl;
  for( int i = 0; i <= mcount; ++i ){
    std::cout << mm[i] << " " << m[mm[i]] << std::endl;
  }
  std::cout << "End Result" << std::endl;
  #endif
}

int calc_price( int num ){
  int n = num;
  int digit[5];
  for( int i = 4; i >= 0; --i){
    digit[i] = n % 10;
    n = n / 10;
  }

  int nRet = 0;
  for( int i = 0; i < b; ++i ){
    nRet += bb[i][2] * digit[i];
  }
  return nRet;
}

int solve(){
  int nRet = 0;
  int ii = 0;
  for( int i = 0; i < 5; ++i){
    if( i < b ){
      nRet += bb[i][1] * bb[i][2];
      ii = ii * 10 + bb[i][1];
    }else
      ii = ii * 10;
  }
  //  std::cout << "count" << ii << std::endl;
  
  Init();

  
  for( int i = 0; i < mcount; ++i){
    if( ii >= mm[i] ){
      int a = mm[i];
      int b = ii - a;
      int t = 0;
      if( m[a] == 0 )
	t = calc_price( a );
      else
	t = m[a];
      if( m[b] == 0 )
	t += calc_price( b );
      else
	t += m[b];

      //    std::cout << a << " " << b << " " << t << " " << nRet << std::endl;
      if( t < nRet ){
	nRet =t ;
      }
    }
    
  }

  //    std::cout << nRet << std::endl;
  
  return nRet;
}
int main(){
  std::ifstream fin("shopping.in");
  fin >> s;
  for( int i = 0; i < s; ++i ){
    fin >> ss[i][0];
    for( int j = 1; j <= 2 * ss[i][0]; j += 2 ){
      fin >> ss[i][j] >> ss[i][j+1];
    }
    fin >> ss[i][ss[i][0] * 2 + 1];
  }
  fin >> b;
  for( int i = 0; i < b; ++i ){
    fin >> bb[i][0] >> bb[i][1] >> bb[i][2];
    mmap[bb[i][0]] = i + 1;
  }

  //  test_input();
  std::ofstream fout("shopping.out");
  fout << solve() << std::endl;
  fout.close();
     
  
      
  return 0;
  
}
