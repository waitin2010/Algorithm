#include <stdio.h>
#include <string.h>

/*#define Local 0*/
int k,e;
char world[20][100];
char lines[20][256];
int extent;
int extents[20];
/* part1: input */
void input(int k, int e) {
  int i,j;
    /* get worlds */
    for(i=0;i<k;i++){
      scanf("%s\n",world[i]);
    }
    /*getchar();*/ /* get the last '\n' or can be past by scanf("%s\n"...) as above
    /* get sentences */
    for(i=0;i<e;i++){
      gets(lines[i]);
    }

#ifdef Local
    for(i=0;i<e+k;i++){
      if(i<k)
	printf("%s\n",world[i]);
      else
	printf("%s\n",lines[i%k]);
    }
#endif 
}

/* count the number which one world can be found in one sentences */
int countWorld(char *l, char *world){
  char *p = NULL;
  int count = 0,len=strlen(world);
  
  while((p=strstr(l,world))!=NULL){
    char h,t;
    h = *(p-1);
    t = *(p+len);
    if(!isalpha(h)&&!isalpha(t))
      count++;
    l = p+ len;
  }
  return count;
}

/* count the extension of the excuse in one sentences */
int countExtent(char *l){
  int sum,i;
  char temp[256];
  sum = 0;

  for(i=0;i<strlen(l);i++){
    temp[i] = isupper(l[i])?tolower(l[i]):l[i];
  }
  temp[i] = '\0';
  for(i=0;i<k;i++){
    sum += countWorld(temp,world[i]);
  }
  return sum;
}

int main() {
  int i,count = 0;

#ifdef Local
  freopen("409.txt","r",stdin);
#endif

  
  while(scanf("%d %d\n",&k,&e)==2){
    input(k,e);
    extent = 0;
    for(i=0;i<e;i++){
      extents[i] = 0;
    }

    for(i=0;i<e;i++){
#ifdef Local
      printf("%s:%d\n",lines[i],countExtent(lines[i]));
#endif 
      extents[i] = countExtent(lines[i]);
      if(extents[i]>extent)
	extent = extents[i];
    }
    /* Output */
    printf("Excuse Set #%d\n",++count);
    for(i=0;i<e;i++){
      if(extent == extents[i])
	printf("%s\n",lines[i]);
    }
    printf("\n");
  }
  return 0;
}
