/* problem: cost cutting */
#include <stdio.h>
int T;/* the number of test cases */
int a, b, c;/* 3 integers */
int main(){
  int i;
  scanf("%d",&T);
  for(i=1;i<=T;i++){
    scanf("%d %d %d",&a, &b, &c);
    printf("case %d: ",i);
    if(a>b){
      if(a>c){
	if(b>c) printf("%d\n",b);
	else printf("%d\n",c);
      }else if(a<c) printf("%d\n",a);
    }else {
      if(a>c) printf("%d\n",a);
      else if(a<c){
	if(c<b) printf("%d\n",c);
	else printf("%d\n",b);
      }
    }
  }
  return 0;
}
