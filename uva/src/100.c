#include <stdio.h>

unsigned int i,j,cycle_length;
int getCycleLength(int k){
  int count;

  count = 1;
  while(k!=1){
    k = k%2==0?k/2:3*k+1;
    count++;
  }
  return count;
}
int main(){

  int k;
  while(scanf("%d %d",&i,&j)==2){
    cycle_length = 0;

    for(k = i; k<=j; k++){
      int temp = getCycleLength(k);
      if(temp>cycle_length)
	cycle_length = temp;
    }

    printf("%d %d %d\n",i,j,cycle_length);
  }
  return 0;
}
