/*
  ID: come_1b1
  LANG: C++
  TASK: castle
*/
#include <iostream>
#include <fstream>
#include <queue>
#include <cstdlib>

int M,N;
int room[50*50];
int room_state[50*50];
int room_num[50*50];
  
int count = 1;
int max_count = 0;
std::queue<int> q;

int edge_count = 0;
int edge1[50*50*4];
int edge2[50*50*4];

int new_max_count = 0;
  
int path[50][50];

void add_up( int index )
{
  if( index - M >= 0 && room_state[index - M] == 0){
    q.push( index - M );
    room_state[index - M] = count;
  }
}

void add_left( int index ){
  if( index - 1 >= 0 && room_state[index -1 ] == 0 ){
    q.push( index - 1 );
    room_state[index - 1] = count;
  }
}

void add_right( int index ) {
  if( index + 1 < M * N && room_state[index + 1] == 0 ){
    q.push( index + 1 );
    room_state[index+1] = count;
  }
}

void add_down( int index ) {
  if( index + M < M * N && room_state[index+M] == 0 ){
    q.push( index + M );
    room_state[index+M] = count;
  }

}

void add_left_edge( int index ){
  if( index - 1 >= 0 && index / M == (index-1) / M ){
    edge1[edge_count] = index - 1;
    edge2[edge_count] = index;
    edge_count++;
  }
}

void add_up_edge( int index ) {
  if( index - M >= 0 ){
    edge1[edge_count] = index - M;
    edge2[edge_count] = index;
    edge_count++;
  }
}

void add_right_edge( int index  ){
  if( index + 1 < M * N && index / M == (index+1) / M ){
    edge1[edge_count] = index + 1;
    edge2[edge_count] = index;
    edge_count++;
  }

}

void add_down_edge( int index )
{
  if( index + M < M * N ){
    edge1[edge_count] = index + M;
    edge2[edge_count] = index;
    edge_count++;
  }

}

int main()
{
  std::ifstream fin("castle.in", std::ios::in);
  
  fin>>M>>N;

  for( int i = 0; i < M * N; ++i ) fin >> room[i];

  for( int i = 0; i < M * N; ++i ) room_state[i] = 0;
  
#if 0
  for( int i = 0; i < M * N; ++i ) {
    std::cout << room[i];
    if( i % M == M-1 ) std::cout << std::endl;
    else std::cout << " ";
  }
    std::cout << M << " " << N << " "
	    <<  M * N << std::endl;
#endif

  for( int i = 0; i < M * N; ++i ){
    if( room_state[i] == 0 ){
      int temp_max_count = 0;
      q.push( i );
      while( !q.empty() ){
	int index = q.front();
	temp_max_count++;
	room_state[index] = count;
	q.pop();
#if 0
	std::cout << count << ":" << index/M + 1 << " " << index % M + 1 << std::endl;
#endif
	switch( room[index] ){
	case 0:
	  add_left( index );
	  add_up( index );
	  add_right( index );
	  add_down( index );
	  break;
	case 1:
	  {
	    add_left_edge( index );
	    add_up( index );
	    add_right( index );
	    add_down( index );
	  }
	  break;
	case 2:
	  {
	    add_left( index );
	    add_up_edge( index );
	    add_right( index );
	    add_down( index );
	  }
	  break;
	case 3:
	  {
	    add_left_edge( index );
	    add_up_edge( index );
	    add_right( index );
	    add_down( index );
	  }
	  break;
	case 4:
	  {
	    add_left( index );
	    add_up( index );
	    add_right_edge( index );
	    add_down( index );
	  }
	  break;
	case 5:
	  {
	    add_left_edge( index );
	    add_up( index );
	    add_right_edge( index );
	    add_down( index );
	  }
	  break;
	case 6:
	  {
	    add_left( index );
	    add_up_edge( index );
	    add_right_edge( index );
	    add_down( index );
	  } 
	  break;
	case 7:
  	  {
	    add_left_edge( index );
	    add_up_edge( index );
	    add_right_edge( index );
	    add_down( index );
	  } 
	  break;
	case 8:
  	  {
	    add_left( index );
	    add_up( index );
	    add_right( index );
	    add_down_edge( index );
	  } 
	  break;
	case 9:
	  {
	    add_left_edge( index );
	    add_up( index );
	    add_right( index );
	    add_down_edge( index );
	  } 
	  break;
	case 10:
	  {
	    add_left( index );
	    add_up_edge( index );
	    add_right( index );
	    add_down_edge( index );
	  } 
	  break;
	case 11:
	  {
	    add_left_edge( index );
	    add_up_edge( index );
	    add_right( index );
	    add_down_edge( index );
	  } 
	  break;
	case 12:
	  {
	    add_left( index );
	    add_up( index );
	    add_right_edge( index );
	    add_down_edge( index );
	  } 
	  break;
	case 13:
	  {
	    add_left_edge( index );
	    add_up( index );
	    add_right_edge( index );
	    add_down_edge( index );
	  } 
	  break;
	case 14:
	  {
	    add_left( index );
	    add_up_edge( index );
	    add_right_edge( index );
	    add_down_edge( index );
	  } 
	  break;
	case 15:
	  {
	    add_left_edge( index );
	    add_up_edge( index );
	    add_right_edge( index );
	    add_down_edge( index );
	  }
	  break;
	default:
	  break;
	}
      }
      room_num[count] = temp_max_count;
      max_count = std::max( max_count, temp_max_count );
      count++;
    }
  }
  std::ofstream fout("castle.out", std::ios::out );
#if 0
  std::cout << count - 1 << std::endl;
  std::cout << max_count << std::endl;
#endif
  fout << count - 1 << std::endl;
  fout << max_count << std::endl;
  int a, b, c;
  a = N;
  b = M;
  c = 4;
  
  for( int i = 0; i < edge_count; ++i ){
#if 0
    std::cout << edge1[i] / M  + 1 << ":" << edge1[i] % M + 1 << " "
	      << edge2[i] / M  + 1 << ":" << edge2[i] %M + 1 << std::endl;
#endif
    if( room_state[edge1[i]] != room_state[edge2[i]] ){
      if( new_max_count < room_num[room_state[edge1[i]]] + room_num[room_state[edge2[i]]] ){
	new_max_count = room_num[room_state[edge1[i]]] + room_num[room_state[edge2[i]]];
	if( abs( edge2[i] - edge1[i] ) == 1 ) {
	  int temp = std::min( edge1[i], edge2[i] );
	  a = temp / M + 1;
	  b = temp % M + 1;
	  c = 4;
	}else{
	  int temp = std::max( edge1[i], edge2[i] );
	  a = temp / M + 1;
	  b = temp % M + 1;
	  c = 2;
	}
      }else if( new_max_count == room_num[room_state[edge1[i]]] + room_num[room_state[edge2[i]]] ) {
	if( abs( edge1[i] - edge2[i] ) == 1 ){
	  int temp = std::min( edge1[i], edge2[i] );
	  if( temp % M + 1< b || (temp % M + 1 == b && temp / M + 1 > a)){
	    a = temp / M + 1;
	    b = temp % M + 1;
	    c = 4;
	  }
	}else {
	  int temp = std::max( edge1[i], edge2[i] );
	  if( temp % M + 1 < b || ( temp % M + 1 == b && temp / M + 1 > a ) ){
	    a = temp / M + 1;
	    b = temp % M + 1;
	    c = 2;
	  }
	}
	    
      }
      //      new_max_count = std::max( new_max_count,
      //			room_num[room_state[edge1[i]]] + room_num[room_state[edge2[i]]] );
#if 0
      std::cout << room_num[room_state[edge1[i]]] << ":" << room_num[room_state[edge2[i]]] << " " << new_max_count << std::endl;
      std::cout << a << " " << b << " " << c << std::endl;
#endif
    }
    
  }

  fout << new_max_count << std::endl;
  fout << a  << " "<< b << " "<< (c == 2? 'N' : 'E') << std::endl;
  return 0;
}
