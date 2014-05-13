/* problem: 424 - Integer Inquiry */

#include <stdio.h>
#include <string.h>
#define NUM 256
struct BigNum{
  int num[NUM];
  int len;
};

struct BigNum n1,n2;

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
int main(){
  char str[256];
  int len;
  scanf("%s",str);
  if(strcmp(str,"0")==0){
    return 0;
  }
  init(&n1,str,strlen(str));
  while(1){
    scanf("%s",str);
    if(strcmp(str,"0")==0)break;
    init(&n2,str,strlen(str));
    add(&n1,&n2);
  }
  print(&n1);
  return 0;
}
