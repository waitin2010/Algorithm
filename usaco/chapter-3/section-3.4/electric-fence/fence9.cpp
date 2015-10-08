/*
  ID: come_1b1
  LANG: C++11
  TASK: fence9
 */
#include <iostream>
#include <fstream>

int n,m,p;
int point_line( int x1, int y1,
		int x2, int y2,
		int x, int y ){
  if( x1 == x2 )
    return x - x1;
  else{
    return ( y - y1) * ( x2 - x1 ) - (y2 - y1) * (x - x1 );
  }
}
int solve(){
  int sum = 0;
  for( int i = 1; i < m; ++i){
    
    int x1 = float(n) / m * i;
    if( point_line( 0, 0, n, m, x1, i ) >= 0 )
      x1++;
    int x2 = n == p ? p : p - float( p - n ) * i / m;
    if( point_line( n, m, p, 0, x2, i ) >= 0 )
      x2--;
    
    //    std::cout << x1 << "\t" << x2 << std::endl;
    sum += x2 - x1 + 1;
  }
  return sum;
}

int main(){
  std::ifstream fin("fence9.in");
  fin >> n >> m >> p;
  fin.close();

  std::ofstream fout("fence9.out");
  fout << solve() << std::endl;
  fout.close();

  return 0;
}
