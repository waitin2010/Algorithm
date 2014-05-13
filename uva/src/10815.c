/* problem : 10815 - Andy's First Dictionary */

/*
 * 1. get worlds from these sentences
 * 2. discard the same worlds and just keep one
 * 3. sort these worlds according alphabetical order.
 */

#include <stdio.h>
#include <string.h>

#define NUM 50
#define Local 0
char world[50];
char worlds[5000][NUM];
int main(){

  int c,count;
  int num;
  int i;
#if Local
  freopen("../10815.txt","r",stdin);
#endif 
  num = 0;
  count = 0;
  while((c=getchar())!=EOF){
    if(isalpha(c)) world[count++] = isupper(c)?tolower(c):c;
      else {
	if(count>0){
	  world[count] = '\0';
	  for(i=0;i<num;i++){
	    if(strcmp(worlds[i],world)==0) break;
	  }
	  if(i>=num)
	    strcpy(worlds[num++],world);
	  count = 0;
	  memset(world,0,NUM);
	}
      }
  }

  qsort(worlds,num,NUM,strcmp);
  for(i=0;i<num;i++)
    printf("%s\n",worlds[i]);
  return 0;
}
