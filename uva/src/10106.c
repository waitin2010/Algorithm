/* problem: 10106 - Integer Inquiry */

/* special cases: 0 x or x 0 */
#include <stdio.h>
#include <string.h>
#define NUM 500
struct BigNum{
  int num[NUM];
  int len;
};



void init(struct BigNum *n,char *str,int len){
  int i;
  for(i=0;i<len;i++){
    n->num[i] = str[len-i-1]-'0';
  }
  n->len = len;
}

void print(struct BigNum *n) {
  int i;
  for(i=n->len-1;i>=0;i--){
    printf("%d",n->num[i]);
  }
  printf("\n");
}

void add(struct BigNum *n1, struct BigNum *n2) {
  int i,c=0;
  for(i=0;i<n1->len&&i<n2->len;i++){
    int temp = n1->num[i] + n2->num[i] + c;
    n1->num[i] = temp %10;
    c = temp/10;
  }
  for(;i<n1->len;i++){
    int temp = n1->num[i] + c;
    n1->num[i] = temp %10;
    c = temp/10;
  }
  for(;i<n2->len;i++){
    int temp = n2->num[i] + c;
    n1->num[i] = temp % 10;
    c = temp /10;
  }
  n1->len  = n1->len>n2->len? n1->len: n2->len;
  if(c>0){
    n1->num[i] = c;
    n1->len++;
  }
}
void mul1(struct BigNum *ans,struct BigNum *n, int a,int delat) {
  int i, c=0;
  for(i=0;i<n->len;i++){
    int temp = n->num[i] * a + c + ans->num[i+delat];
    ans->num[i+delat] = temp % 10;
    c = temp/10;
  }
  while(c>0){
   int temp = ans->num[i+delat] + c%10;
   ans->num[i+++delat] = temp %10;
   c= temp /10;
  }
  ans->len = i + delat;

}
void mul2(struct BigNum *ans, struct BigNum *a, struct BigNum *b){
  int i;
  for(i=0;i<b->len;i++){
    mul1(ans,a,b->num[i],i);
  }
}  
void empty(struct BigNum *n){
  int i;
  for(i=0;i<n->len;i++){
    n->num[i] = 0;
  }
  n->len = 0;
}
struct BigNum n1,n2,ans;
int main(){
  char str[256],str2[256];
  int len;

  while(scanf("%s %s",str,str2)==2){
  init(&n1,str,strlen(str));
  empty(&ans);
  init(&n2,str2,strlen(str2));
  if(strcmp(str,"0")==0||strcmp(str2,"0")==0)
    printf("0\n");
  else{
  mul2(&ans, &n1, &n2);
  print(&ans);}
  }
  return 0;
}
