/* Follow up for N-Queens problem.
 * Now, instead outputting board configurations,
 * return the total number of distinct solutions.
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

// the number of the solutions
int ncount;

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
void process()
{
  ncount++;
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

int totalNQueens(int n)
{
  // init
  N = n;
  nrow = 0;
  for(int i=0;i<N;i++)
    row[i] = -1;
  // process
  basicFunc(0);
  return ncount;
  
}
int main()
{
  int n;
  do
  {
    
  cin>>n;
  if(n<0) break;
  
  ncount = 0;
  cout<<totalNQueens(n)<<endl;
  
  
  
  }while(1);
  
  
	return 0;
}
