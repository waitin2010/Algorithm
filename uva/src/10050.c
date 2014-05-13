/* problem : 10050 - Hartals */

/* T: the number of test cases
 * N: [7, 3650], the number of days
 * P: (1,100) the number of political parties
 * hi: hartal parameter for party i, not a multiple of 7
 */

/* days[3650]: 1 for hartals, 0 for no hartal
 * for each hi, set days from hi to hi*(N/hi) to 1
 * count the 1 in days array 
 */

#include <stdio.h>

#define NUM_DAY 3650 + 1
#define NUM_PARTY 100

int T;/* the number of test cases */
int N;/*the simulation days */
int days[NUM_DAY];/* tell one day if on hartals */
int P;/* the number of political parties */
int h[NUM_PARTY];/* the hartal parameter for parties */

void initCase(){
  int i;
  scanf("%d%d",&N, &P);
  for(i=0;i<P;i++)
    scanf("%d",&h[i]);
  for(i=0;i<=N;i++)
    days[i] = 0;
}

int  process(){
  int i,j;
  int count;/* count the hartals */
  count = 0;
  for(i=0;i<P;i++){
    int hi = h[i];
    for(j=hi;j<=N;j+=hi){
      days[j] = 1;
    }
  }
  for(i=0;i<2;i++){
    int hi = 6+i;
  for(j=hi;j<=N;j+=7){
    days[j] =0;
  }
  }
  for(i=0;i<=N;i++){
    if(days[i]) count++;
  }
  return count;
}

void print(){
  int i;
  printf("days:%d\nparties:%d\n",N,P);
  printf("parties' hartal parameter:\n");
  for(i=0;i<P;i++)
    printf("%d",h[i]);
  printf("\n");
  printf("days in hartal:\n");
  for(i=0;i<=N;i++)
    if(days[i])
      printf("day %d in hartal\n", i);
}

int main(){
  /*  freopen("10050.txt","r", stdin);*/
  scanf("%d",&T);
  while(T-->0){
    initCase();
    printf("%d\n",process());
    /*    print();*/
  }
  return 0;
}
  
    
