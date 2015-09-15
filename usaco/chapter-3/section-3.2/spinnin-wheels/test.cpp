#include <iostream>

int solve( int n ){
  int ret = 0;

  int temp = n;
  do {
    temp += n;
    ret++;
  }while( temp % 360 != n );
  return ret;
}

int main(){

  for( int i = 1; i <= 180; ++i )
    std::cout << i << ": " << solve( i ) << std::endl;

  return 0;
}
