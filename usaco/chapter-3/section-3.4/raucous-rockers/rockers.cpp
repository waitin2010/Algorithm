/*
  ID: come_1b1
  LANG: C++11
  TASK: rockers
 */

#include<fstream>
using namespace std;
ifstream cin("rockers.in");
ofstream cout("rockers.out");

int f[21][21][21]={0},N,T,M,t[21];

int main()
{
  cin>>N>>T>>M;
  for(int i=1;i<=N;++i)
    cin>>t[i];

  for(int i=1;i<=M;++i)
    for(int j=1;j<=N;++j)
      for(int k=1;k<=T;++k)
	{
	  f[i][j][k]=f[i][j-1][k];
	  if(k>=t[j]) f[i][j][k]=max(f[i][j-1][k-t[j]]+1,f[i][j][k]);
	  if(k>=t[j]) f[i][j][k]=max(f[i-1][j-1][T]+1,f[i][j][k]);
	  f[i][j][k]=max(f[i][j][k],f[i][j][k-1]);
	}
  cout<<f[M][N][T]<<endl;
  return 0;

}
