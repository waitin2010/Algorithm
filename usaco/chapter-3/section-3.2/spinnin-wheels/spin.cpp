/*
  ID: come_1b1
  LANG: C++11
  TASK: spin
 */
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>

const int w = 5;

struct Wheel{
  int speed;
  int num;
  int start[w];
  int extent[w];
}wheels[w];

std::ostream& operator<<(std::ostream &out, struct Wheel &w ){
  out << w.speed << " " << w.num;
  for( int i = 0; i < w.num; ++i )
    out << " " << w.start[i] << " " << w.extent[i];
  out << std::endl;
  return out;
}

void print(){
  for( int i = 0; i < w; ++i )
    std::cout << wheels[i];
}
  
void one_step( struct Wheel &w ){
  for( int i = 0; i < w.num; ++i ){
    w.start[i] += w.speed;
    w.start[i] %= 360;
  }
}


bool is_can_pass( struct Wheel &w, int angle ){
  int i = 0;
  while( i < w.num ){
    if( w.start[i] <= angle && angle <= w.start[i] + w.extent[i] ){
      //std::cout << angle << " " << w.start[i] << " " << w.start[i] + w.extent[i] << std::endl;
      break;
    }
    if( w.start[i] + w.extent[i] >=360
	&& w.start[i] <= angle + 360
	&& angle + 360 <= w.start[i] + w.extent[i] ){
      //      std::cout << angle << " " << w.start[i] << " " << w.start[i] + w.extent[i] << std::endl;
      break;
    }
    ++i;
  }

  return i < w.num;
}

int solve(){

  int sec = 0;
  do {
    //    std::cout << "sec:" << sec << std::endl;
    int j = 0;

    for( ; j < 360; ++j ){
      //      std::cout << "angle: " << j << std::endl;
      int i = 0;
      for( ; i < w; ++i ){
	if( is_can_pass( wheels[i], j ) ){
	  //	  std::cout << "pass on wheel\t" << i << std::endl;
	  continue;
	}else{
	  //std::cout<<wheels[i] << "angle" << j << std::endl;
	  break;
	}
      }
      if( i >= w ){
	//std::cout << "pass on whole" << std::endl;
	break;
      }
    }
    if( j < 360 ){
      //      std::cout << j << "\tcan pass the whole wheels" << std::endl;
      break;
    }
 
    for(int i = 0; i < w; ++i )
      one_step( wheels[i] );
    
  }while( sec++ < 360 );

  return sec;
}
    
int main(){
  std::ifstream fin("spin.in");
  for( int i = 0; i < w; ++i ){
    fin >> wheels[i].speed >> wheels[i].num;
    for( int j = 0; j < wheels[i].num; ++j )
      fin >> wheels[i].start[j] >> wheels[i].extent[j];
  }
  fin.close();

  int ret = solve();
  std::ofstream fout("spin.out");
  if( ret >=360 )
    fout << "none" << std::endl;
  else
    fout << ret << std::endl;
  fout.close();

  print();
  
  return 0;
}
