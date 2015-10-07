/*
  ID: come_1b1
  LANG: C++11
  TASK: heritage
 */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <string>

std::string in_order;
std::string pre_order;
std::string post_order;

void step( int in_i, int in_j,
	   int pre_i, int pre_j ){
  #if 0
  std::cout << "in_order\t" << in_i << "\t" << in_j << std::endl;
  std::cout << "pre_order\t" << pre_i << "\t" << pre_j << std::endl;
  std::cout << std::endl;
  #endif
  if( in_i > in_j || pre_i > pre_j )
    return ;
  if( in_i == in_j ){
    post_order += in_order.at(in_i);
  }else{
    char c = pre_order.at( pre_i );
    size_t in_ii = in_order.find( c );
    step( in_i,	in_ii - 1,  pre_i + 1, pre_i + in_ii - in_i);
    step( in_ii + 1, in_j,  pre_i + in_ii - in_i + 1, pre_j );
    post_order += c;
  }
}
void solve(){
  step( 0, in_order.size() - 1, 0, pre_order.size() - 1 );
}
  
int main(){
  std::ifstream fin("heritage.in");
  fin >> in_order >> pre_order;
  fin.close();

  solve();

  std::ofstream fout("heritage.out");
  fout << post_order << std::endl;
  fout.close();
  
  return 0;
}

