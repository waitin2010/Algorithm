/* problem: 10189 - Minesweeper */

/* no special cases 
 * case 1
 * * or .
 */
#include <stdio.h>
#include <string.h>
#define NUM 101
int n,m;
char data[NUM][NUM];
char result[NUM][NUM];

/* return the number of the mines surround the i, j space.
 * search 8 directions, if it is mine, add 1 to count,
 * if it is not mine, search the next direction 
 */
int dirj[8] = { +1, +1,  0, -1, -1, -1,  0, +1};
int diri[8] = {  0, +1, +1, +1,  0, -1, -1, -1};
int search(int i, int j) {
  int k,count;

  count = 0; /* the number of the surround mines */
  for(k=0;k<8;k++) {
    int di = i + diri[k];
    int dj = j + dirj[k];
    if(di>=0&&di<n&&dj>=0&&dj<m&&data[di][dj] == '*')
      count++;
  }
  return count;
}

int main(){
  /* input */
  int i,j;
  int second = 0;/* the cases' index, if it was bigger than 2, should print next-line*/
  while(scanf("%d %d",&n,&m)==2&&!(n==0&&m==0)){
    if(second) printf("\n");
    second++;
    printf("Field #%d:\n",second);
    memset(data,0,sizeof(data));
    memset(data,0,sizeof(result));
    for(i=0;i<n;i++)
      scanf("%s",data[i]);
    
#ifdef Local 
    for(i=0;i<n;i++)
      printf("%s\n",data[i]);
#endif 
    for(i=0;i<n;i++){
      for(j=0;j<m;j++){
	result[i][j] = data[i][j]=='*'?'*':search(i,j)+'0';
      }
    }
    for(i=0;i<n;i++){
      for(j=0;j<m;j++){
	printf("%c",result[i][j]);
      }
      printf("\n");
    }
    
  }
  return 0;
}

