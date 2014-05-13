/* problem: 10115 - Automatic Editing */

#include <stdio.h>
#include <string.h>

#define Local 0
#define Len1 100
#define Len2 300

int testCases;
char a[10][Len1];
char b[10][Len1];

char c1[Len2],c2[Len2];
void process(char *a, char *b){
  char *p = c1;
  char *q = NULL;
#if Local 
  printf("a:%s - b:%s\n",a,b);
#endif 
  while((q=strstr(p,a))!=NULL){
    int len = q - p;
    memset(c2,0,sizeof(c2));
    strncpy(c2,c1,len);
    strncpy(c2+len,b,strlen(b));
    strcpy(c2+len+strlen(b),q+strlen(a));
    strcpy(c1,c2);
    c1[strlen(c2)]='\0';
    p = c1;
#if Local
    printf("c1:%s\n",c1);
    #endif
  }
}
int main(){
  FILE *fpin, *fpout;
  int i;
#if Local
  fpin = fopen("autoedit.in","r");
  fpout = fopen("autoedit.out","w");
#endif 
  while(scanf("%d\n",&testCases)!=EOF&&testCases!=0){
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c1,0,sizeof(c1));
    memset(c2,0,sizeof(c2));
    for(i=0;i<testCases;i++){
      gets(a[i]);
      gets(b[i]);
      a[i][strlen(a[i])]='\0';
      b[i][strlen(b[i])]='\0';
    }
#if 0
    for(i=0;i<testCases;i++){
      fprintf(stdout,"%s\n",a[i]);
      fprintf(stdout,"%s\n",b[i]);
    }
#endif

    gets(c1);
    c1[strlen(c1)] = '\0';
    for(i=0;i<testCases;i++){
        process(a[i],b[i]);
    }
    printf("%s\n",c1);


  }
  return 0;
}
