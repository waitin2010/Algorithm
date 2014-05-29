/* Given n pairs of parentheses, write a function to generate all
 * combinations of well-formed parentheses.
 */

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

#define MAX 10000
int  g_select[MAX];
char g_charset[]="()";
int  g_num_choice;
int  g_depth;
int  g_left_num;
int  g_right_num;


// all combinations of well-formed parentheses
vector<string> solutions;



bool check(int idepth, int choice)
{  
  if(choice==0&&g_left_num >= g_depth/2)
    return false;
  if(choice==1&&g_left_num <g_right_num + 1)
    return false;
  choice == 0?g_left_num++:g_right_num++;
  
    return true;
  
}
void recover(int idepth, int choice)
{
  choice == 0? g_left_num--: g_right_num--;
}

void process()
{
  string temp;
  
  for(int i=0;i<g_depth;i++)
    temp += g_charset[g_select[i]];
  
  //cout<<temp.c_str()<<endl;
  
  solutions.push_back(temp.c_str());
  
  
}


void depth_tree_travel(int depth)
{
  if(depth == g_depth)
  {
    process();
  }else
  {
    for(int i=0;i<g_num_choice;i++)
    {
      if(check(depth,i)){
        g_select[depth] = i;
        depth_tree_travel(depth+1);
        recover(depth,i);
      }
    }
    
  }
  
  
}

vector<string> generateParenthesis(int n)
{
  // init
  g_num_choice = 2;
  g_depth = n*2;
  g_left_num = g_right_num = 0;
  
  for(int i=0;i<g_depth;i++)
    g_select[i] = -1;
  
  // process
  depth_tree_travel(0);
  
  return solutions;
  
}#define MAX 10000
int  g_select[MAX];
char g_charset[]="()";
int  g_num_choice;
int  g_depth;
int  g_left_num;
int  g_right_num;


// all combinations of well-formed parentheses
vector<string> solutions;



bool check(int idepth, int choice)
{  
  if(choice==0&&g_left_num >= g_depth/2)
    return false;
  if(choice==1&&g_left_num <g_right_num + 1)
    return false;
  choice == 0?g_left_num++:g_right_num++;
  
    return true;
  
}
void recover(int idepth, int choice)
{
  choice == 0? g_left_num--: g_right_num--;
}

void process()
{
  string temp;
  
  for(int i=0;i<g_depth;i++)
    temp += g_charset[g_select[i]];
  
  //cout<<temp.c_str()<<endl;
  
  solutions.push_back(temp.c_str());
  
  
}


void depth_tree_travel(int depth)
{
  if(depth == g_depth)
  {
    process();
  }else
  {
    for(int i=0;i<g_num_choice;i++)
    {
      if(check(depth,i)){
        g_select[depth] = i;
        depth_tree_travel(depth+1);
        recover(depth,i);
      }
    }
    
  }
  
  
}

vector<string> generateParenthesis(int n)
{
  // init
  g_num_choice = 2;
  g_depth = n*2;
  g_left_num = g_right_num = 0;
  
  for(int i=0;i<g_depth;i++)
    g_select[i] = -1;
  
  // process
  depth_tree_travel(0);
  
  return solutions;
  
}
void print()
{
  for(int i=0;i<solutions.size();i++)
    cout<<solutions[i].c_str()<<endl;
  
}

int main()
{
  int n;
  do
  {
    
  cin>>n;
  if(n<0) break;
  generateParenthesis(n);
  print();
  }while(1);
  
  
	return 0;
}
