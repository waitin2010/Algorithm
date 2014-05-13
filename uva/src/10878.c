#include <stdio.h>

int c;
char str[256];
int index[7]={      2, 3, 4, 5,    7, 8, 9};
/*             |    o  o  o  o  .  o  o  o  |*/
int value[11]={0,0,64,32,16, 8, 0, 4, 2, 1, 0};
int main(){
  int i;

  while(gets(str)!=NULL){
    if(str[0]!='|')continue;
    c = 0;
    for(i=0;i<7;i++){
      if(str[index[i]]=='o')
	c += value[index[i]];
    }
    printf("%c",c);
  }
  return 0;
}
