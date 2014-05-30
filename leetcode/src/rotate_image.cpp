/* Problem: Rotate Image
 * You are given an nxn 2D matrix representing an image.
 * Rotate the image by 90 degrees(clockwise).
 */

/*
 * D(i',j') = O(j,n-i)
 */
#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

void exchange(int i, int j,int n, vector<vector<int> > &matrix)
{
  int loop_count = 4;
  int temp = matrix[i][j];
    while(--loop_count)
    {
      matrix[i][j] = matrix[n-j-1][i];
      int temp = i;
      i = n - j - 1;
      j = temp;
    }
    matrix[i][j] = temp;
}
void print_test(vector<vector<int> > &test);

void rotate(vector<vector<int> > &matrix)
{
  int n = matrix.size();
  // spcical case
  if(n==0) return ;

  for(int i=0;i< n/2;i++)
  {
    for(int j=i;j<n-i-1;j++)
    {
      exchange(i,j,n,matrix);
      //cout<<matrix[i][j];
      
    }
    //    cout<<endl;
    
  }
  //  print_test(matrix);
  
  
  
}
// test case
vector<vector<int> > test1;
vector<vector<int> > test2;
vector<vector<int> > test3;
vector<vector<int> > test4;

void construct_test(vector<vector<int> > &test,int n)
{
 

  for(int i=0;i<n;i++)
  {
 vector<int> temp;  
    for(int j=0;j<n;j++)
      temp.push_back(i*n+j);
    test.push_back(temp);
  }
  
}
void print_test(vector<vector<int> > &test)
{
  int n = test.size();

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
      cout<<test[i][j]<<" ";
    cout<<endl;
  }
  cout<<endl;
  
}

  
void test_case()
{
  construct_test(test1,2);
  construct_test(test2,1);
  construct_test(test3,3);
  construct_test(test4,10);

  print_test(test1);
  print_test(test2);
  print_test(test3);
  print_test(test4);

  rotate(test1);
  rotate(test2);
  rotate(test3);
  rotate(test4);

  print_test(test1);
  print_test(test2);
  print_test(test3);
  print_test(test4);
  
  
}

int main(){
  test_case();
  
	return 0;
}
