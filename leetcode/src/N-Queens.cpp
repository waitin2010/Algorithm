/* Given an integer n, return all distinct solutions
 * to the n-queens puzzle.
 */

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

#define MAX 10000
// row[i] : the column of the ith row 
int row[MAX];
int nrow;
int N;

// all distinct solutions to the n-queens puzzle
vector<vector<string> > solutions;



bool check(int nrow, int column)
{
  // if in the same column
  for(int i=0;i<nrow;i++)
  {
    // the same column
    if(row[i] == column)
      return false;
    // diagonal 
    if( i-nrow == row[i]-column||i-nrow==column-row[i])
      return false;
  }

  return true;
  
}
void recover(int row, int col)
{

}
string construct_one_row(int col)
{
  string result;
  for(int i=0;i<N;i++)
  {
    result[i] = col==i?'Q':'.';
  }
  //cout<<result.c_str()<<endl;
  
  return result;
}

void process()
{
  vector<string> solution(N,"!");

  
  for(int i=0;i<N;i++)
  {
    //    temp.clear();
    
    string temp = string(construct_one_row(row[i]).c_str());
    
    
    //  cout<<temp.c_str()<<endl;
  
  solution[i] = temp;
  
      //  solution.push_back(construct_one_row(row[i]));
  }
  //  cout<<solution.size()<<endl;
  
  //  for(int i=0;i<solution.size();i++)
  //    cout<<solution[i].c_str()<<endl;
  
  solutions.push_back(solution);
  
  
}

void process1()
{
  for(int i=0;i<N;i++)
  {
    cout<<row[i]<<" ";
  }
  cout<<endl;
}

void basicFunc(int depth)
{
  if(depth == N)
  {
    process();
  }else
  {
    for(int i=0;i<N;i++)
    {
      if(check(depth,i)){
        row[depth] = i;
        basicFunc(depth+1);
      }

    }
    
  }
  
  
}

vector<vector<string> > totalNQueens(int n)
{
  // init
  N = n;
  nrow = 0;
  for(int i=0;i<N;i++)
    row[i] = -1;
  // process
  basicFunc(0);
  return solutions;
  
}
void print()
{
  for(int i=0;i<solutions.size();i++)
  {
    for(int j=0;j<solutions[i].size();j++)
      cout<<solutions[i][j].c_str()<<endl;
  }
}

int main()
{
  int n;
  do
  {
    
  cin>>n;
  if(n<0) break;
  totalNQueens(n);
  print();
  }while(1);
  
  
	return 0;
}
