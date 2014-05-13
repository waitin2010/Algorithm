/* problem: Exponentiation */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <limits.h>
#define NUM 1000
struct BigNum{
  int num[NUM];/*digits in the number from right to left */
  int len;/* the length of the number*/
};



void init(struct BigNum *n,char *str,int len){
  int i,j;
  n->len = 0;
  for(i=0;i<len;i++){
    if(str[i]!='0'&&isdigit(str[i])) break;
  }
  n->len = len-i;
  for(j=0;j<len-i;j++){
    n->num[j] = str[len-1-j]-'0';
  }
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
void mul1(struct BigNum *ans,struct BigNum n1,struct BigNum n, int a,int delat) {
  int i, c=0;
  for(i=0;i<n.len;i++){
    int temp = n.num[i] * a + c + n1.num[i+delat];
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
void mul2(struct BigNum *ans, struct BigNum a, struct BigNum b){
  int i;
  for(i=0;i<b.len;i++){
    mul1(ans,*ans,a,b.num[i],i);
  }
}  
void empty(struct BigNum *n){
  int i;
  for(i=0;i<n->len;i++){
    n->num[i] = 0;
  }
  n->len = 0;
}
int isBig(struct BigNum *n1, struct BigNum *n2) {
  int i;
  if(n1->len != n2->len) return n1->len > n2->len? 1: 0;
  for(i=n1->len-1;i>=0;i--)
    if(n1->num[i]!=n2->num[i])
      return n1->num[i]> n2->num[i]?1:0;
  return 0;
}
int main(){
  char str[NUM],str1,str2[NUM];/* oprand1 operator operand2 */
  struct BigNum n1, n2,n3, big;
  int n,i;
  sprintf(str,"%d",INT_MAX);
  init(&big, str, strlen(str));
  while(scanf("%s %d",str,&n)==2) {
    printf("%s %d\n",str,n);
    empty(&n1);empty(&n2);
    init(&n1,str,strlen(str));
    init(&n2,str,strlen(str));
    for(i=0;i<n-1;i++){
      mul2(&n2,n2,n1);
    }
    print(&n2);
  }
  return 0;
}
