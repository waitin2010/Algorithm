/* problem: 706 - LCD display */

#include <stdio.h>
#include <string.h>
#define NUM 12

int number[NUM+1];
int data[10][7] = { 1, 1, 1, 0, 1, 1, 1,/* 0 */
		    0, 0, 1, 0, 0, 1, 0,/* 1 */
		    1, 0, 1, 1, 1, 0, 1,/* 2 */
		    1, 0, 1, 1, 0, 1, 1,/* 3 */
		    0, 1, 1, 1, 0, 1, 0,/* 4 */
		    1, 1, 0, 1, 0, 1, 1,/* 5 */
		    1, 1, 0, 1, 1, 1, 1,/* 6 */
		    1, 0, 1, 0, 0, 1, 0,/* 7 */
		    1, 1, 1, 1, 1, 1, 1,/* 8 */
		    1, 1, 1, 1, 0, 1, 1 /* 9 */
};
int itoa(int n){
  int total = 0;
  if(n==0) {number[0]=0;return 1;}
  while(n!=0){
    number[total++] = n %10;
    n=n/10;
  }
  return total;
}
void print_horizon(int n,int pos, int s){
  int i;
  printf(" ");
  for(i=0;i<s;i++){
    if(data[n][pos])
      printf("-");
    else
      printf(" ");
  }
  printf(" ");
}
void printv(int n, int pos1, int pos2, int s){
  int i;
  if(data[n][pos1])printf("|");
  else printf(" ");
  for(i=0;i<s;i++)
    printf(" ");
  if(data[n][pos2]) printf("|");
  else printf(" ");
}
void print(int num[],int total,int s){
  int c,r;
  int i,j,k;
  c = 2*s; r = 2*s+3;
  for(i=0;i<r;i++){
    for(j=total-1;j>=0;j--){
      if(i==0||i==s+1||i==2*s+2){
	if(i==0)
	print_horizon(num[j],0,s);
	else if(i==s+1)
	  print_horizon(num[j],3,s);
	else 
	  print_horizon(num[j],6,s);
      } else {
	if(i-s<=0.0){
	      printv(num[j],1,2,s);
	}else {
	    printv(num[j],4,5,s);
	}
      }
      if(j!=0)printf(" ");
    }
    printf("\n");
  }
}
      
int main(){
  int total;
  int i;
  int s,n;
  char temp[NUM];
  /*
  while(scanf("%d %d",&s,&n)==2&&!(s==0&&n==0)){
  total = 0;
  total = itoa(n);
#ifdef Local
  for(i=0;i<total;i++)
    printf("%d\n",number[i]);
#endif
  print(number, total, s);
  }*/
  int second = 0;
  while(scanf("%d %s",&s,temp)==2){

    if(s==0&&strcmp(temp,"0")==0) break;
    total = strlen(temp);
    for(i=0;i<total;i++)
      number[i] = temp[total-i-1] - '0';
    print(number, total, s);
 printf("\n");/* forget this print specification to pass this problem */
  }


  return 0;
}
