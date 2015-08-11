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
#endif
  std::cout << M << " " << N << " "
	    <<  M * N << std::endl;
  for( int i = 0; i < M * N; ++i ){
    std::cout << "i" << i << std::endl;
    if( room_state[i] == 0 ){
      int temp_max_count = 0;
      q.push( i );
      while( !q.empty() ){
	int index = q.front();
	if( room_state[index] == 0)
	  temp_max_count++;
	room_state[index] = count;
	q.pop();
#if 0
	std::cout << count << ":" << index/M + 1 << " " << index % M + 1 << std::endl;
	#endif
	std::cout << "q.size() " << q.size() << std::endl;
	switch( room[index] ){
	case 0:
	    if( index - M >= 0 && room_state[index - M] == 0)
	      q.push( index - M );
	    if( index + 1 < M * N && room_state[index + 1] == 0 )
	      q.push( index + 1 );
	    if( index + M < M * N && room_state[index+M] == 0 )
	      q.push( index + M );
	    if( index - 1 >= 0 && room_state[index -1 ] == 0 )
	      q.push( index - 1 );
	    break;
	case 1:
	  {
	    if( index - M >= 0 && room_state[index - M] == 0)
	      q.push( index - M );
	    if( index + 1 < M * N && room_state[index + 1] == 0 )
	      q.push( index + 1 );
	    if( index + M < M * N && room_state[index+M] == 0 )
	      q.push( index + M );
	    if( index - 1 >= 0 && index / M == (index-1) / M ){
	      edge1[edge_count] = index - 1;
	      edge2[edge_count] = index;
	      edge_count++;
	    }
	      
	  }
	  break;
	case 2:
	  {
	    if( index - 1 >= 0 && room_state[index -1 ] == 0 )
	      q.push( index - 1 );
	    if( index + 1 < M * N && room_state[index + 1] == 0 )
	      q.push( index + 1 );
	    if( index + M < M * N && room_state[index+M] == 0 )
	      q.push( index + M );
	    if( index - M >= 0 ){
	      edge1[edge_count] = index - M;
	      edge2[edge_count] = index;
	      edge_count++;
	    }
	  }
	  break;
	case 3:
	  {
	    if( index + 1 < M * N && room_state[index + 1] == 0 )
	      q.push( index + 1 );
	    if( index + M < M * N && room_state[index+M] == 0 )
	      q.push( index + M );
	    if( index - 1 >= 0 && index / M == (index-1) / M ){
	      edge1[edge_count] = index - 1;
	      edge2[edge_count] = index;
	      edge_count++;
	    }
	    if( index - M >= 0 ){
	      edge1[edge_count] = index - M;
	      edge2[edge_count] = index;
	      edge_count++;
	    }
	  }
	  break;
	case 4:
	  {
	    if( index - 1 >= 0 && room_state[index -1 ] == 0 )
	      q.push( index - 1 );
	    if( index - M >= 0 && room_state[index - M] == 0)
	      q.push( index - M );
	    if( index + M < M * N && room_state[index+M] == 0 )
	      q.push( index + M );
	    if( index + 1 < M * N && index / M == (index +1 ) / M){
	      edge1[edge_count] = index + 1;
	      edge2[edge_count] = index;
	      edge_count++;
	    }

	  }
	  break;
	case 5:
	  {
	    if( index - M >= 0 && room_state[index - M] == 0)
	      q.push( index - M );
	    if( index + M < M * N && room_state[index+M] == 0 )
	      q.push( index + M );
	    if( index - 1 >= 0 && index / M == (index-1) / M ){
	      edge1[edge_count] = index - 1;
	      edge2[edge_count] = index;
	      edge_count++;
	    }
	    if( index + 1 < M * N && index / M == ( index + 1) / M ){
	      edge1[edge_count] = index + 1;
	      edge2[edge_count] = index;
	      edge_count++;
	    }

	  }
	  break;
	case 6:
	  {
	    if( index - 1 >= 0 && room_state[index -1 ] == 0 )
	      q.push( index - 1 );
	    if( index + M < M * N && room_state[index+M] == 0 )
	      q.push( index + M );
	    if( index + 1 < M * N  && index / M == (index+1) / M ){
	      edge1[edge_count] = index + 1;
	      edge2[edge_count] = index;
	      edge_count++;
	    }
	    if( index - M >= 0 ){
	      edge1[edge_count] = index - M;
	      edge2[edge_count] = index;
	      edge_count++;
	    }

	  } 
	  break;
	case 7:
  	  {
	    if( index + M < M * N && room_state[index+M] == 0 )
	      q.push( index + M );
	    if( index + 1 < M * N  && index / M == (index+1) / M ){
	      edge1[edge_count] = index + 1;
	      edge2[edge_count] = index;
	      edge_count++;
	    }
	    if( index - M >= 0 ){
	      edge1[edge_count] = index - M;
	      edge2[edge_count] = index;
	      edge_count++;
	    }
	    if( index - 1 >= 0 && index / M == (index-1) / M ){
	      edge1[edge_count] = index - 1;
	      edge2[edge_count] = index;
	      edge_count++;
	    }


	  } 
	  break;
	case 8:
  	  {
	    if( index - 1 >= 0 && room_state[index -1 ] == 0 )
	      q.push( index - 1 );
	    if( index - M >= 0 && room_state[index - M] == 0)
	      q.push( index - M );
	    if( index + 1 < M * N && room_state[index + 1] == 0 )
	      q.push( index + 1 );
	    if( index + M >= 0 ){
	      edge1[edge_count] = index + M;
	      edge2[edge_count] = index;
	      edge_count++;
	    }
	  } 
	  break;
	case 9:
	  {
	    if( index - M >= 0 && room_state[index - M] == 0)
	      q.push( index - M );
	    if( index + 1 < M * N && room_state[index + 1] == 0 )
	      q.push( index + 1 );
	    if( index - 1 >= 0 && index / M == (index-1) / M ){
	      edge1[edge_count] = index - 1;
	      edge2[edge_count] = index;
	      edge_count++;
	    }
	    if( index + M >= 0 ){
	      edge1[edge_count] = index + M;
	      edge2[edge_count] = index;
	      edge_count++;
	    }


	  } 
	  break;
	case 10:
	  {
	    if( index - 1 >= 0 && room_state[index -1 ] == 0 )
	      q.push( index - 1 );
	    if( index + 1 < M * N && room_state[index + 1] == 0 )
	      q.push( index + 1 );
	    if( index - M >= 0 ){
	      edge1[edge_count] = index - M;
	      edge2[edge_count] = index;
	      edge_count++;
	    }
	    if( index + M >= 0 ){
	      edge1[edge_count] = index + M;
	      edge2[edge_count] = index;
	      edge_count++;
	    }

	  } 
	  break;
	case 11:
	  {
	    if( index + 1 < M * N && room_state[index + 1] == 0 )
	      q.push( index + 1 );
	    if( index - 1 >= 0 && index / M != (index-1) / M ){
	      edge1[edge_count] = index - 1;
	      edge2[edge_count] = index;
	      edge_count++;
	    }
	    if( index - M >= 0 ){
	      edge1[edge_count] = index - M;
	      edge2[edge_count] = index;
	      edge_count++;
	    }
	    if( index + M < M * N ){
	      edge1[edge_count] = index + M;
	      edge2[edge_count] = index;
	      edge_count++;
	    }


	  } 
	  break;
	case 12:
	  {
	    if( index - 1 < M * N && room_state[index - 1] == 0 )
	      q.push( index - 1 );
	    if( index - M < M * N && room_state[index - M] == 0 )
	      q.push( index - M );
	    if( index + 1 >= 0  && index / M == (index+1) / M ){
	      edge1[edge_count] = index + 1;
	      edge2[edge_count] = index;
	      edge_count++;
	    }
	    if( index + M < M * N ){
	      edge1[edge_count] = index + M;
	      edge2[edge_count] = index;
	      edge_count++;
	    }

	  } 
	  break;
	case 13:
	  {
	    if( index - M >= 0 && room_state[index - M] == 0)
	      q.push( index - M );
	    if( index + 1 < M * N  && index / M == (index+1) / M ){
	      edge1[edge_count] = index + 1;
	      edge2[edge_count] = index;
	      edge_count++;
	    }
	    if( index - 1 >= 0 && index / M == (index-1) / M  ){
	      edge1[edge_count] = index - 1;
	      edge2[edge_count] = index;
	      edge_count++;
	    }
	    if( index + M < M * N ){
	      edge1[edge_count] = index + M;
	      edge2[edge_count] = index;
	      edge_count++;
	    }


	  } 
	  break;
	case 14:
	  {
	    if( index - 1 >= 0 && room_state[index -1 ] == 0 )
	      q.push( index - 1 );
	    if( index + 1 >= 0  && index / M == (index+1) / M ){
	      edge1[edge_count] = index + 1;
	      edge2[edge_count] = index;
	      edge_count++;
	    }
	    if( index - M >= 0 ){
	      edge1[edge_count] = index - M;
	      edge2[edge_count] = index;
	      edge_count++;
	    }
	    if( index + M < M * N ){
	      edge1[edge_count] = index + M;
	      edge2[edge_count] = index;
	      edge_count++;
	    }

	  } 
	  break;
	case 15:
	  {
	    if( index + 1 < M * N && index / M == (index+1) / M ){
	      edge1[edge_count] = index + 1;
	      edge2[edge_count] = index;
	      edge_count++;
	    }
	    if( index - 1 >= 0 && index / M == (index-1) / M ){
	      edge1[edge_count] = index - 1;
	      edge2[edge_count] = index;
	      edge_count++;
	    }
	    if( index - M >= 0 ){
	      edge1[edge_count] = index - M;
	      edge2[edge_count] = index;
	      edge_count++;
	    }
	    if( index + M < M * N ){
	      edge1[edge_count] = index + M;
	      edge2[edge_count] = index;
	      edge_count++;
	    }

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
  #if 1
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
