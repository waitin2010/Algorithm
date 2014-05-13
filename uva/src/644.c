/* problem: 644 - Immediate Decodability */

/* do a pairwise comparision between all strings in a set to see if any is the prefix*/
#include <stdio.h>
#include <string.h>

#define Local 0

char codes[9][11];
int set;
/* if a is prefix of b, return 0 else return 1 */
int compare(char *a, char *b){
  int lena, lenb;
  lena = strlen(a);
  lenb = strlen(b);
  if(lena>lenb) return 1;
  else{
    int i,ok;
    ok = 1;
    for(i=0;i<lena;i++)
      if(a[i]!=b[i]) break;
    if(i>=lena) return 0;
    else return 1;
  }
}
int main(){
  int i,j,num;
  char code[11];
  #if Local 
  freopen("../644.txt","r",stdin);
  #endif 

  num = 0;
  while(scanf("%s",code)!=EOF){
    if(strcmp(code,"9")==0){
      int ok = 1;
      for(i=0;i<num;i++){
	for(j=0;j<num;j++){
	  if(i!=j){
	    ok = compare(codes[i],codes[j]);
	    if(!ok)
	      break;
	  }
	}
	if(!ok) break;
      }
      printf("Set %d is %s decodable\n",++set,ok?"immediately":"not immediately");
      num = 0;
      memset(codes,0,sizeof(codes));
    }else {
      strcpy(codes[num++],code);
    }
      
  }

  return 0;
}
