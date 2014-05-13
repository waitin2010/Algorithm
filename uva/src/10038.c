/* problem: 10038 - Jolly Jumper */

#include <stdio.h>

#define NUM 3000
int absvalue[NUM];
int n;

int main(){
  int a, b, i;
  while(1) {
    if(scanf("%d %d",&n,&a)!=2) break;
    for(i=0;i<=n-1;i++) absvalue[i] = 0;
    for(i=0;i<n-1;i++){
      scanf("%d",&b);
      /* the b-a<NUM condition */
      absvalue[b-a>0&&b-a<NUM?b-a:a-b] = 1;
      a = b;
    }

    for(i=1;i<=n-1;i++){
      if(!absvalue[i]) break;
    }
    if(i>n-1) printf("Jolly\n");
    else printf("Not jolly\n");
  }
  return 0;
}
      
    
