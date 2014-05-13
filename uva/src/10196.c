/* problem: 10196 - check the check */

/* white pieces: uppercase letters, bottom
 * black pieces: lowercase letters, top
 * there won't be a configuration where both kings are in check.
 * p or P: (i+1,j+1) or (i+1, j-1)
 * n or N: (i+1,j-2) (i+2, j-1)
 */

#include <stdio.h>
#include <string.h>
#define NUM 8

char check[NUM][NUM+1];
int white_ok = 0;/* if white king is checked */
int black_ok = 0;/* if black king is checked */

/* get check configuration */
int getCheck() {
  int i,j;
  for(i=0;i<NUM;i++)
    scanf("%s",check[i]);
  return 1;
}
/* 1 if empty */
int checkEmpty(){
  int i,j;
  for(i=0;i<NUM; i++) 
    for(j=0;j<NUM; j++) 
      if(check[i][j] != '.')
	return 0;
  return 1;
}
/* output the check */
void printCheck(){
  int i;
  for(i=0;i<NUM;i++) 
    printf("%s\n",check[i]);
}
void printCheck2() {
  int i,j;
  for(i=0;i<NUM;i++){
    for(j=0;j<NUM;j++)
      printf("%c",check[i][j]==1?'*':'.');
    printf("\n");
  }
}
/* find the piece at the check */
int findPiece(char piece, int *x, int *y){
  int i, j;
  for(i=0;i<NUM;i++){
    for(j=0;j<NUM;j++){
      if(piece == check[i][j]){
	*x = i;
	*y = j;
	return 1;
      }
    }
  }
  return 0;
}

/* p possible next position */
void pPiece(int x, int y,char k) {
  if(x+1<NUM&& y-1>=0){
    if(check[x+1][y-1] == k) 
      white_ok = 1;
  }
  if(x+1<NUM&&y+1<NUM){
    if(check[x+1][y+1] ==k)
      white_ok = 1;
  }
}

/* P */
void PPiece(int x, int y, char k) {
  if(x-1>=0&& y-1>=0&& check[x-1][y-1] == k) black_ok = 1;
  if(x-1>=0&& y+1<NUM&& check[x-1][y+1] ==k) black_ok = 1;
}
/* n  and N */
void nNPiece(int x, int y, char k) {
  int i;
  int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2};
  int dy[] = {  1,  2, 2, 1, -1,-2, -2, -1};

  for(i=0;i<8;i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(nx>=0&&nx<NUM&&ny>=0&&ny<NUM){
      if(check[nx][ny] == k) {
	if(k=='k') black_ok = 1;
	else white_ok = 1;
	return ;
      }
    }
  }
}
/* r */
void rRPiece(int x, int y, char k){
  int i;
  for(i=x-1;i>=0;i--){/* up direction */
    if(check[i][y] == k) {
      if(k=='k') black_ok = 1;
      else white_ok = 1;
      return ;
    }
    if(check[i][y]!='.') break;
  }
  for(i=x+1;i<NUM;i++) { /* down direction */
    if(check[i][y] == k) {
      if(k=='k') black_ok = 1;
      else white_ok = 1;
      return ;
    }
    if(check[i][y] != '.') break;
  }
  for(i=y-1;i>=0;i--) {/* left direction */
    if(check[x][i] == k) {
      if(k=='k') black_ok = 1;
      else white_ok = 1;
      return ;
    }
    if(check[x][i] !='.') break;
  }
  for(i=y+1;i<NUM;i++) {/* right direction */
    if(check[x][i] == k) {
      if(k=='k') black_ok = 1;
      else white_ok = 1;
      return ;
    }
    if(check[x][i] !='.') break;
  }
}
/* b */
void bBPiece(int x, int y, int k) {
  int nx, ny;

  nx = x-1;ny=y+1;
  while(nx>=0&&ny<NUM) {/* top-right direction */
    if(check[nx][ny] == k) {
      if(k=='k') black_ok = 1;
      else white_ok = 1;
      return ;
    }
    if(check[nx][ny] !='.') break;
    nx--;ny++;
  }

  nx = x+1; ny= y+1;
  while(nx<NUM&& ny<NUM) { /* bottom-right direction*/
    if(check[nx][ny] == k) {
      if(k=='k') black_ok = 1;
      else white_ok = 1;
      return ;
    }
    if(check[nx][ny] !='.') break;
    nx++;ny++;
  }
  
  nx = x+1; ny= y-1;
  while(nx<NUM&& ny>=0) { /* bottom-left direction*/
    if(check[nx][ny] == k) {
      if(k=='k') black_ok = 1;
      else white_ok = 1;
      return ;
    }
    if(check[nx][ny] !='.') break;
    nx++;ny--;
  }
  
  nx = x-1; ny = y-1;
  while(nx>=0&&ny>=0) {/* top-left direction */
    if(check[nx][ny] == k) {
      if(k=='k') black_ok = 1;
      else white_ok = 1;
      return ;
    }
    if(check[nx][ny]!='.') break;
    nx--;ny--;
  }
}
/* q and Q */
void qQPiece(int x, int y, char k) {
  rRPiece(x,y,k);
  bBPiece(x,y,k);
}

/* k and K */
void kKPiece(int x, int y,char k) {
  int i;
  int dx[] = { 0, 1, 1, 1, 0, -1, -1, -1};
  int dy[] = { 1, 1, 0, -1, -1, -1, 0, 1};

  for(i=0;i<8;i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(nx>=0&&nx<NUM&&ny>=0&&ny<NUM)
      if(check[nx][ny] == k) {
	if(k=='k') black_ok = 1;
	else white_ok = 1;
	return ;
      }
  }
}  
int main() {
  int x, y;/* position index */
  char pieces[] = "pPnNbBrRqQkK";/* test for the position of these pieces */
  char piece;
  int len = strlen(pieces);
  int i; /* counter */
  int nCase;

  nCase = 1;
#ifdef Local 
  freopen("10196.txt", "r", stdin);
#endif 
  while(getCheck()&&checkEmpty()!=1){
    int i,j;
    char k;
    white_ok = 0;
    black_ok = 0;
    for(i=0;i<NUM;i++){
      for(j=0;j<NUM;j++) {
	piece = check[i][j];
	switch(piece){
	case 'p':
	  k = 'K';
	  pPiece(i,j,k);
	  break;
	case 'P':
	  k = 'k';
	  PPiece(i,j,k);
	  break;
	case 'r':
	  k = 'K';
	  rRPiece(i,j,k);
	  break;
	case 'R':
	  k = 'k';
	  rRPiece(i,j,k);
	  break;
	case 'b':
	  k= 'K';
	  bBPiece(i,j,k);
	  break;
	case 'B':
	  k= 'k';
	  bBPiece(i,j,k);
	  break;
	case 'q':
	  k = 'K';
	  qQPiece(i,j,k);
	  break;
	case 'Q':
	  k = 'k';
	  qQPiece(i,j,k);
	  break;
	case 'k':
	  k = 'K';
	  kKPiece(i,j,k);
	  break;
	case 'K':
	  kKPiece(i,j,'k');
	  break;
	case 'n':
	  nNPiece(i,j,'K');
	  break;
	case 'N':
	  nNPiece(i,j,'k');
	  break;
	}
	if(white_ok == 1) {
	  printf("Game #%d: white king is in check.\n",nCase++);
	  break;
	}
	if(black_ok == 1) {
	  printf("Game #%d: black king is in check.\n",nCase++);
	  break;
	}
      }
      if(white_ok||black_ok) 
	break;
    }
    if(white_ok == 0 && black_ok == 0) printf("Game #%d: no king is in check.\n",nCase++);
  }
  return 0;
}  
