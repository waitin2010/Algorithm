/* problem: 10142 - Austalian Voting */

/* 50% elected 
 * all candidates are tied
 */

#include <stdio.h>
#include <string.h>
#define NUM 20 + 10/* max numbers of candidates */
#define NAME_LEN 81 + 10 /* the max length of the candidates' name */
#define VOTE_NUM 1000 + 10 /* the max votes */


int nCase;
int n; /* the number of candidates */
char names[NUM][NAME_LEN]; /* candidates names */
int votes[VOTE_NUM][NUM]; /* votes */
int nVote; /* the total votes*/
int dis[NUM];

/* find the max and min votes in candidateVotes */
void findMaxMin(int candidateVotes[],int nCandidate,int *maxVotes,int *maxVotesCandidate, int *minVotes, int *minVotesCandidate){
  int i;
  int min,max;
  min = VOTE_NUM + 3;
  max = -1;
  for(i=0;i<nCandidate;i++){
    if(!dis[i]&&min>candidateVotes[i]){
      min = candidateVotes[i];
      *minVotesCandidate = i;
    }
    if(max<candidateVotes[i]){
      max = candidateVotes[i];
      *maxVotesCandidate = i;
    }
  }
  *maxVotes = max;
  *minVotes = min;
}
/* 1,win candidate if more than 50%
 * 0,low candidate if no more than 50%
 *-1,-1 if all candidate are tied
 */
int compute(int select[],int nVote, int nCandidate, int *candidate){
  int candidateVotes[NUM];/* counter for each candidate */
  int total;
  int i,j;/* counter */
  int maxVotes,maxVotesCandidate;
  int minVotes,minVotesCandidate;
  for(i=0;i<nCandidate;i++){
    candidateVotes[i] = 0;
  }
  /* count the votes for each candidate */
  for(i=0;i<nVote;i++){
    candidateVotes[select[i]-1]++;
  }

  /* if each candidate's vote is same */
  for(i=0;i<nCandidate;i++) if(candidateVotes[i]!=0){
      total = candidateVotes[i];
      break;
    }
  for(i=0;i<nCandidate;i++)
    if(!dis[i]&&total != candidateVotes[i])
      break;
  if(i>=nCandidate) return -1;
  /* find max votes and min votes */
  findMaxMin(candidateVotes,nCandidate,&maxVotes,&maxVotesCandidate, &minVotes,&minVotesCandidate);
  /* if votes more than 50% */
  if(maxVotes>nVote/2){
    *candidate = maxVotesCandidate;
    return 1;
  }else {
    *candidate = minVotesCandidate;
    for(i=0;i<nCandidate;i++){
      if(candidateVotes[i] == minVotes){
	/*	for(j=0;j<nVote;j++)
		removeCandidate(votes[j],nCandidate,i+1);*/
	dis[i]=1;
      }
    }
    return 0;
  }
}
void printVotes(int);
void process(int nVote,int nCandidate){
  int select[VOTE_NUM];/* the first candidates */
  int situation; /* more than 50% or all candidate are tied or next-turn */
  int k,i,j;
  int candidate;
#ifdef Local 
  printf("Now is in Process...\n");
#endif 
  for(k=0;k<nVote;k++){

    for(i=0;i<nVote;i++){
      for(j=0;j<nCandidate;j++)
	if(!dis[votes[i][j]-1]){
	  select[i] = votes[i][j];
#if 0
	  printf("%d",select[i]);
#endif 
	  break;
	}
    }
#if  0
    printf("\n");
#endif
    situation=compute(select,nVote,nCandidate,&candidate);
    if(situation ==0) {
#ifdef Local
        printVotes(nCandidate);
#endif 
    }
    if(situation == 1){ /* more than 50% */
      printf("%s\n",names[candidate]);
      break;
    }else if (situation == -1) {/* all candidates are tied */
      for(i=0;i<nCandidate;i++)
	if(!dis[i])printf("%s\n",names[i]);
      break;
    }
  }
}
/* get a sequence of numbers from string str and 
 * return the total number converted
 */
int fetchNumFromStr(char str[],int num[]){
  int i;/* counter */
  char temp[3];/* numbers str */
  int count=0;/* for temp numbers str */
  int nCount=0;/* the counter for the numbers in str*/
  for(i=0;i<=strlen(str);i++){
    if(isdigit(str[i])){
      temp[count++] = str[i];
    }else if(count>0){/* convert str to num by using temp*/
      temp[count] = '\0';
      num[nCount++] = atoi(temp);
      count = 0;/* get ready for next number */
       }
  }
#ifdef Local
  /* test and output the numbers */
  for(i=0;i<nCount;i++)
    printf("%d ",num[i]);
  printf("\n");
#endif
  return 0;
}
int getData(){
  int nCandidate;
  int i;
  char temp[NAME_LEN];
    scanf("%d\n",&nCandidate);
    for(i=0;i<nCandidate;i++){
      gets(names[i]);
    }
#ifdef Local 
    for(i=0;i<nCandidate;i++){
      puts(names[i]);
    }
#endif
    while(gets(temp)!=NULL&&strlen(temp)!=0){
	fetchNumFromStr(temp,votes[nVote]);
	nVote++;
    }
    return nCandidate;
}
void printVotes(int nCandidate){
  int i,j;
  for(i=0;i<nVote;i++){
    for(j=0;j<nCandidate;j++)
      printf("%d", votes[i][j]);
    printf("\n");
  }
}

int main() {
  /*  freopen("10142.txt","r", stdin);*/
  int i;
  scanf("%d",&nCase);
  while(nCase--){
    nVote = 0;
    int nCandidate = getData();
    for(i=0;i<nCandidate;i++) dis[i] = 0;
    process(nVote,nCandidate); /* simulation */
    if(nCase!=0)printf("\n");
  }
  return 0;
}

