/* problem: 10315 - Poker Hands */

/* find the type of each poker hand,
 * and compare them according the rule
 */

/* Hight Card - Straigt flush : 0 - 8 
 * flush and straight flush as one group
 * others as second group
 * T = 10, J = 11, Q = 12, K = 13, A = 14
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define NUM 5
typedef struct {
  int values[NUM];/*values in a poker hand*/
  char suits[NUM+1];/*suits in a poker hand*/
  int type;/* the type such as Hight Card .. */
}PokerHand;

PokerHand white, black;
int getValue(char c){
  if(isdigit(c))
    return c - '0';
  else {
    switch(c){
    case 'T':
      return 10;
    case 'J':
      return 11;
    case 'Q':
      return 12;
    case 'K':
      return 13;
    case 'A':
      return 14;
    }
  }
}
  
void initPokerHand(char *str){
  int i;
  char temp[3];
  char *  p = str;
  for(i=0;i<2*NUM;i++){
    sscanf(p,"%s",temp);
    /*    printf("%s\n",temp);*/
    if(i<NUM){
      black.values[i] = getValue(temp[0]);
      black.suits[i] = temp[1];
    }else {
      white.values[i-NUM] = getValue(temp[0]);
      white.suits[i-NUM] = temp[1];
    }
    p = strchr(p,' ')+1;
  }
}
/* 1, if it is flush 
 * 0, if it is not flush 
 */
int IsFlush(PokerHand *ph){
  int i;
  for(i=0;i<NUM-1;i++)
    if(ph->suits[i] != ph->suits[i+1])
      return 0;
  return 1;
}
int cmpInt(int* a, int* b){
  return *b - *a;
}
void getType(PokerHand *ph){
  int i;/* counter */
  int num[15]; /* count the values' number */
  int count[6]; /* count the count of the values' number */
  int isFlush;
  int index;
  index = 0;
  /* init num */
  for(i=2;i<=14;i++) /* 2 to 14 */
    num[i] = 0;
  for(i=1;i<=5;i++) count[i] = 0;
    
  for(i=0;i<NUM;i++)
    num[ph->values[i]]++;
  
  for(i=2;i<=14;i++)
    count[num[i]]++;

  isFlush = IsFlush(ph);
  if(count[1]==5){/* Hight Card, Straight, Flush, Straight Flush */
    qsort(ph->values,NUM,sizeof(int),cmpInt);
    for(i=0;i<NUM-1;i++)
      if(ph->values[i] != ph->values[i+1]+1) break;
    if(i>=NUM-1) {/*Straight, Straight flush*/
      if(isFlush)/* Straight Flush*/
	ph->type = 8;
      else 
	ph->type = 4;
    }else{/* hight card, flush */
      if(isFlush)
	ph->type = 5;
      else
	ph->type = 0;
    }
  }else if(count[4]==1){/* four of a kind */
    ph->type= 7;
  }else if(count[3]==1&&count[2]==1){/* Full house */
    ph->type = 6;
  }else if(count[3]==1&&count[2]!=1){/* Three of a kind */
    ph->type = 3;
  }else if(count[2] == 2){
    ph->type = 2;
  }else if(count[2] == 1){
    ph->type = 1;
  }
  for(i=2;i<=14;i++)
    if(num[i]!=0) ph->values[index++] = i + (num[i]-1)*14;
  qsort(ph->values,NUM, sizeof(int),cmpInt);

}
 
  
void print(PokerHand ph){
  int i;
  printf("type:%d\nvalues:",ph.type);
  for(i=0;i<NUM;i++){
    printf("%d ",ph.values[i]);
  }
  printf("\n");
  printf("suits:%s\n",ph.suits);
}

#include <stdio.h>

int main(){
  int i;/*counter */
  char ph[256];/* one turn */
  int isWhite;/* tell if white win*/
  while(gets(ph)!=NULL){
    /*    puts(ph);*/
    isWhite = 0;
    initPokerHand(ph);
    getType(&white);getType(&black);
    if(white.type != black.type){
      isWhite = white.type - black.type;
    }else {
      for(i=0;i<NUM;i++)
	if(white.values[i]!=black.values[i]){
	  isWhite = white.values[i] - black.values[i];
	  break;
	}
    }
    printf("%s\n",isWhite>=0?(isWhite==0?"Tie.":"White wins."):"Black wins.");
    /*    print(white);
	  print(black);*/
  }

  return 0;
}
