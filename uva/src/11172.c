/* problem: 11172 - Relational Operator */
#include <stdio.h>

int t;
int a, b;

int main(){
  int i;
  scanf("%d",&t);
  for(i=0;i<t;i++){
    scanf("%d %d",&a, &b);
    if(a>b) printf(">");
    else if (a < b) printf("<");
    else if (a == b) printf("=");
    printf("\n");
  }
  return 0;
}
