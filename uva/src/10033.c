/* problem: 10033 - Interpreter */

/* inits register[10] and memory[1000],
 * 100 - halt
 * 2dn - register[d] = n
 * 3dn - register[d] = (register[d] + n)%1000;
 * 4dn - register[d] = (register[d] * n)%1000;
 * 5ds - register[d] = register[s]
 * 6ds - register[d] = (register[d] + register[s])%1000;
 * 7ds - register[d] = (register[d] * register[s])%1000;
 * 8da - register[d] = memory[register[a]];
 * 9sa - memory[register[a]] = register[s];
 * 0ds - cmdLine = register[d] if s == 0, cmdLine for the command address
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void halt(int count){
  static int ok = 0;/* if first case */
  if(ok){
    printf("\n");
  }else
    ok = 1;
    printf("%d\n",count);
}
int registers[10];
char memory[1000][4];
int main() {
  int cmdLine;/* memory address */
  int nCase; /* total test cases */
  int i,j;
  char temp[4];/* get input*/
  int count; /* get commands and store in memory*/
  int result; /* the commands that excuse */
#ifdef Local
  freopen("10033.txt","r",stdin);
#endif
  scanf("%d\n",&nCase);
#ifdef Local 
  printf("nCase:\n");
  printf("%d\n",nCase);
#endif
  for(i=0;i<nCase;i++){
#ifdef Local
    printf("case:%d\n",i);
#endif
    /* clear register */
    for(j=0;j<10;j++) registers[j] = 0;

    /* init cmdLine */
    cmdLine = 0;
    result = 1;
    count = 0;
    memset(memory,'\0',sizeof(memory));
    while(gets(memory[count])&&strlen(memory[count])!=0){
      count++;
    }
#ifdef Local 
    printf("memory:\n");
    for(j=0;j<count;j++){
      printf("%s\n",memory[j]);
    }
#endif 
    /* interpreter */
    while(memory[cmdLine][0]!='1'){/* halt case */
      int a,b,c;/* command xxx */
      char temp[4];
      a = memory[cmdLine][0] - '0';
      b = memory[cmdLine][1] - '0';
      c = memory[cmdLine][2] - '0';
      switch(a){
      case 2:
	registers[b] = c;
	break;
      case 3:
	registers[b] += c;
      registers[b] %=1000;
	break;
      case 4:
	registers[b] *= c;
      registers[b] %=1000;
	break;
      case 5:
	registers[b] = registers[c];
	registers[b] %=1000;
	break;
      case 6:
	registers[b] += registers[c];
      registers[b] %=1000;
	break;
      case 7:
	registers[b] *= registers[c];
	registers[b] %=1000;
	break;
      case 8:
	registers[b] = atoi(memory[registers[c]]);
	registers[b] %=1000;
	break;
      case 9:
	sprintf(temp,"%d",registers[b]);
	strcpy(memory[registers[c]],temp);
	break;
      }

      if(a==0&&registers[c]!=0){
	cmdLine = registers[b];
#ifdef Local 
	printf("newLine:%d\n",cmdLine);
#endif
      }
      else
	cmdLine++;
      result++;
    }
    #ifdef Local
    printf("Registers:\n");
    for(j=0;j<10;j++) printf("%d\n",registers[j]);
    #endif
    halt(result);
    
  }
  return 0;
}
      
