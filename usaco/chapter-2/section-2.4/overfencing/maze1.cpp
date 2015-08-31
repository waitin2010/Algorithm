/*
  ID: come_1b1
  LANG: C++11
  TASK: maze1
*/

#include <iostream>
#include <fstream>
#include <limits>
#include <queue>


const int max_w = 2 * 38 + 1;
const int max_h = 2 * 100 + 1;

int w,h;
char maze[max_h][max_w];

std::pair<int, int> ex[2];

std::queue<std::pair<int,int> > q;
bool visited[max_h][max_w];
int dep[max_h][max_w];
int dep2[max_h][max_w];

int solve2( std::pair<int, int> e, int dep[max_h][max_w] )
{

  int depth = 1;
  for( int i = 0; i < 2 * h + 1; ++i )
    for( int j = 0; j < 2 * w + 1; ++j )
      visited[i][j] = false;
  
  q.push( e );
  dep[e.first][e.second] = depth;
  visited[e.first][e.second] = true;
  
  while( !q.empty() ){
    int size = q.size();
        depth++;

    while( size-->0 ){
      std::pair<int, int> t = q.front();
      q.pop();
      int i = t.first;
      int j = t.second;
      //      std::cout << depth << ": " << i << " " << j << std::endl;
      if( i - 2 > 0 && maze[i-1][j] != '*' && !visited[i-2][j]
	  && dep[i-2][j] >= depth){
	q.push( std::make_pair( i - 2, j ) );
	dep[i-2][j] = depth;
	visited[i-2][j] = true;
      }
      if( j + 2 < 2 * w && maze[i][j+1] != '*' && !visited[i][j+2]
	  && dep[i][j+2] >= depth){
	q.push( std::make_pair( i, j + 2 ) );
	dep[i][j+2] = depth;
	visited[i][j+2] = true;
      }
      if( i + 2 < 2 * h && maze[i+1][j] != '*' && !visited[i+2][j]
	  && dep[i+2][j] >= depth){
	q.push( std::make_pair( i+2, j ) );
	dep[i+2][j] = depth;
	visited[i+2][j] = true;
      }
      if( j - 2 > 0 && maze[i][j-1] != '*'&& !visited[i][j-2]
	  && dep[i][j-2] >= depth ){
	q.push( std::make_pair( i, j - 2 ) );
	dep[i][j-2] = depth;
	visited[i][j-2] = true;
      }
    }
  }
  return depth - 1;
}

int solve()
{
  for( int i = 0; i < 2 * h + 1; ++i )
    for( int j = 0; j < 2 * w + 1; ++j ){
      dep[i][j] = std::numeric_limits<int>::max();
      dep2[i][j] = std::numeric_limits<int>::max();
    }

  solve2( ex[0], dep );
  solve2( ex[1], dep2 );


  int ret = 0;
  for( int i = 0; i < 2 * h + 1; ++i ){
    for( int j = 0; j < 2 * w + 1; ++j ){
      //      std::cout << i << ":" << j << " " << dep[i][j] << " " << dep2[i][j] << std::endl;
      if( dep[i][j] > dep2[i][j] ){
	dep[i][j] = dep2[i][j];
      }
      if( dep[i][j] != std::numeric_limits<int>::max() && ret < dep[i][j] )
	ret = dep[i][j];
    }
  }

  return ret;

}

int main()
{
  std::fstream fin("maze1.in", std::ios::in);
  fin >> w >> h;
  fin.get();
  int k = 0;
  for( int i = 0; i < 2 * h + 1; ++i ){
    char buf[max_w+1];
    fin.getline( buf, max_w + 1 );
    for( int j = 0; j < 2 * w + 1; ++j ){
      if( buf[j] == ' ' ){
	maze[i][j] = ' ';
	if( i == 0 || i == 2*h ||
	    j == 0 || j == 2 * w ){
	  ex[k].first = i;
	  ex[k].second = j;
	  if( i == 0 )
	    ex[k].first = i + 1;
	  else if( i == 2 * h )
	    ex[k].first = i - 1;
	  if( j == 0 )
	    ex[k].second = j + 1;
	  if( j == 2 * w )
	    ex[k].second = j - 1;
	  k++;
	}
	
      }
      else
	maze[i][j] = '*';
    }
  }
  fin.close();

#if 0
  for( int i = 0; i < 2 * h + 1; ++i ){
    for( int j = 0; j < 2 * w + 1; ++j ){
      std::cout << maze[i][j];
    }
    std::cout << std::endl;
  }
  for( int i = 0; i < k; ++i )
    std::cout <<  ex[i].first << " " << ex[i].second << std::endl;
#endif

  std::ofstream fout( "maze1.out", std::ios::out);
  fout << solve() << std::endl;
  fout.close();
  return 0;

}
      
