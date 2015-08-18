/*
  ID: come_1b1
  LANG: C++
  TASK: subset
 */
#include <iostream>
#include <fstream>


const int max_n = 39;

int data[39];

int n;

int sum;

int half_sum;

long long count;

int GetSum( int num )
{
  return ( 1 + num ) * num / 2;
}

bool solve( int start, int depth )
{
  if( half_sum * 2 == sum ){
    #if 0
    for( int i = 0; i < n - depth; ++i )
      std::cout << data[i] << " ";
    std::cout << std::endl;
    #endif
    count++;
    return true;
  }
    
  if( half_sum * 2 < sum && depth > 0 ) {
    for( int i = start; i <= n; ++i ){
      half_sum += i;
      data[n-depth] = i;
      solve( i + 1, depth-1);
      data[n-depth] = 0;
      half_sum -= i;
    }
  }

  return false;
}

int main()
{
  std::ifstream fin( "subset.in", std::ios::in );
  fin >> n;
  fin.close();

  sum = GetSum( n );
#if 0
  std::cout << "sum is: " << sum << std::endl;
#endif

  std::ofstream fout( "subset.out", std::ios::out );
  if( sum % 2 != 0 )
    fout << 0 << std::endl;
  else{
    solve( 1, n);
    fout << count/2 << std::endl;
  }
  fout.close();
  return 0;
}
