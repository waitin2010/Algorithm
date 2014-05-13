/* problem: 10137 - The Trip */

/* Test case 
 * 1
 * 10.01
 * 2
 * 10.00
 * 10.00
 * 3
 * 10,000.00
 *  9,000.00
 *  8,000.00
 * 0
 * no very special cases
 */

#include <stdio.h>
#define NUM 1000

long n;
double money[NUM];
char tmp[NUM+7];
int main(){
  long i;
  double sum,exchanged_money_up,exchanged_money_down;/* sum: the total spent money, exchanged_money: the minial money shuold be exchanged */
  double average; /* the average money of the student*/
  while(scanf("%d",&n)==1&&n!=0){
    sum = 0.0f;
    exchanged_money_up = exchanged_money_down = 0;
    for(i=0;i<n;i++){
      scanf("%lf",&money[i]);
      sum += money[i];
    }
#ifdef Local
    for(i=0;i<n;i++){
      printf("%.2lf\n",money[i]);
    }
#endif 
    average = sum/n;
    sprintf(tmp,"%.2lf",average);
    sscanf(tmp,"%lf",&average);

    for(i=0;i<n;i++){
      if(money[i]<average)
	exchanged_money_down += average - money[i];
      else
	exchanged_money_up += money[i] - average;
    }
#ifdef Local
    printf("sum: %f\t average: %.f\n",sum, average);
#endif
    printf("$%.2lf\n",exchanged_money_up>exchanged_money_down? exchanged_money_down:exchanged_money_up);
  }
  return 0;
}
   
    
