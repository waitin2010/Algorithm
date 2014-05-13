/* problem: 10267 - Graphical Editor */

#include <stdio.h>
#include <string.h>
#define NUM 250 + 10
int m,n;
char data[NUM][NUM];
int end = 0;
void swap(int *a, int *b){
  if ( *a > * b){
    int temp = *a;
    *a = *b;
    *b = temp;
  }
}
void print(char *name){
  int i, j;
  printf("%s\n",name);
  for(i=1;i<=n;i++){
    for(j=1; j<=m; j++)
      printf("%c",data[i][j]);
    printf("\n");
  }
}
void Fill(int x, int y, char o, char c) {
  if(o==c) return;
  if(x>m||x<1||y>n||y<1) return ;
  if(data[y][x]!=o) return;
  data[y][x] = c;
  Fill(x+1,y,o,c);
  Fill(x, y+1,o,c);
  Fill(x-1,y,o,c);
  Fill(x, y-1,o,c);
}
/* x - column m while y - row n */
void trace(int x, int y,char o, char c){
  int dx, dy;
  int i;
  /* get confused with the column and row
   *
  int deltaX[8] = { +1, 0, -1, 0, +1, -1, -1, +1};
  int deltaYs[8] = {  0, +1, 0, -1, +1, +1, -1, -1};
  */
  /* 
  int deltaY[8] = { +1, 0, -1, 0, +1, -1, -1, +1};
  int deltaX[8] = {  0, +1, 0, -1, +1, +1, -1, -1};
  */
  int  deltaY[] = { 0, 1,-1, 0,  1, -1, -1, 1};
  int  deltaX[] = { 1, 0, 0, -1, -1, -1, 1, 1};
  for(i=0;i<4;i++){
    dx = x + deltaX[i];
    dy = y + deltaY[i];
    if(dy>0&&dy<=n&&dx>0&&dx<=m&&data[dy][dx]!=c&&data[dy][dx]==o){
      data[dy][dx] = c;
      trace(dx, dy, o, c);
    }
  }
}
void process(char cmd){
  int x1, x2, y1, y2, i,j;
  char c;
  int up, down;/* Y1 > Y2 or X1 > X2 */
  char name[NUM], temp[NUM];/* temp: retrieve no cmd line */
  char cc;
  switch(cmd){
  case 'I':
    scanf("%d %d",&m, &n);
  case 'C':
    memset(data,'O',sizeof(data));
    break;
  case 'L':
    scanf("%d %d %c",&x1, &y1, &c);
    data[y1][x1] = c;
    break;
  case 'V':
    scanf("%d %d %d %c", &x1, &y1, &y2, &c);
    up = y1 > y2? y1 : y2;
    down = y1 > y2? y2 : y1;
    for(i=down; i<=up;i++)
      data[i][x1] = c;
    break;
  case 'H':
    scanf("%d %d %d %c", &x1, &x2, &y1, &c);
    up = x1 > x2? x1 : x2;
    down = x1 > x2? x2: x1;
    for(i=down;i<=up;i++)
      data[y1][i] = c;
    break;
  case 'K':
    scanf("%d %d %d %d %c", &x1, &y1, &x2, &y2, &c);
    swap(&x1,&x2);swap(&y1,&y2);
    for(i=x1; i<=x2;i++)
      for(j=y1; j<=y2; j++) {
	data[j][i] = c;
      }
    break;
  case 'F':
    scanf("%d %d %c",&x1, &y1, &c);
    /*    trace(x1, y1, data[y1][x1],c);*/
    Fill(x1,y1,data[y1][x1],c);
    break;
  case 'S':
     scanf("%s",name);
    print(name);
    break;
  default:
    /*    scanf("%s",temp);*/
    while((cc=getchar())!='\n');
    break;
  }
  if(cc!='\n')
    getchar();
  else
    cc = ' ';
}

int main() {
  char cmd;
  int c;
  while( scanf("%c",&cmd)==1){
    if(cmd == 'X') break;
#ifdef Local
    printf("cmd: %c\n",cmd);
#endif 
    process(cmd);

  }
  return 0;
}
