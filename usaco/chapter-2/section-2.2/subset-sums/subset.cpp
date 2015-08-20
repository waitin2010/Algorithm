/*
  ID: come_1b1
  LANG: C++
  TASK: subset
 */
#include <iostream>
#include <fstream>

int n;
const int max_n = 39;
long long sum[ (max_n + 1 ) * max_n  / 2 + 1 ];


int solve( int n )
{
  sum[1] = 1;
  for( int i = 2; i <= n; ++i ){
    for( int j = (i-1) * i/2; j>=1; --j ){
      sum[j+i] += sum[j];
    }
    sum[i]++;
    #if 0
    std::cout << "i:" << i << std::endl;
    for( int j = 1; j <= (i+1) * i/2; ++j )
      std::cout << j << ":" << sum[j] << " ";
    std::cout << std::endl;
    #endif
  }
#if 0
  std::cout << "(n+1)*n/4:" << (n+1)*n/4 << std::endl;
#endif
  return sum[(n+1)*n/4] / 2;
}
int main()
{
  std::ifstream fin( "subset.in", std::ios::in );
  fin >> n;
  fin.close();

  #if 0
  std::cout <<  "n: " << n << std::endl;
  std::cout << "ret: " << solve( n ) << std::endl;
  #endif
  
  std::ofstream fout( "subset.out", std::ios::out);
  if( (( n + 1) * n / 2) % 2 == 0 )
    fout << solve( n ) << std::endl;
  else
    fout << 0 << std::endl;

  fout.close();


  return 0;
}
