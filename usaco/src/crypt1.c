/*
ID: come_1b1
LANG: C
TASK:crypt1
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
int N;
int set[9];
int digits[10];
int temp[5];
int a,b,c;
FILE *fpin;
FILE *fpout;
int count;
int NotInSet(int num)
{
	if(num == 0)
		return 1;
	else if(digits[num%10])
		  return NotInSet(num/10);
	else
		return 0;
}
void trace(int depth)
{
	int i;
	if (depth >= 5)
	{
		a = 0, b = 0, c = 0;
		for(i = 2; i >=0; i--)
			a = a * 10 + temp[i];
		c = temp[3];
		b = temp[4];
		if (a*b/1000 > 0)
			return ;
		if (a*c/1000 > 0)
			return ;
		if ((a*b + a*c*10)/10000 > 0)
			return ;
        if (!NotInSet(a*b))
			return ;
		if (!NotInSet(a*c))
			return ;
		if (!NotInSet(a*b+a*c*10))
			return ;
#if 0
		for(i = 0; i < 5; i++)
			fprintf(fpout, "%d ", temp[i]);
		fprintf(fpout,"\n");
#endif 
		count++;
		return ;
	}
	for(i = 0; i<N; i++)
	{
		temp[depth] = set[i];
		trace(depth+1);
	}
}
int main(int argc, char** argv)
{
	
	
	int i;
	fpin = fopen("crypt1.in","r");
	fpout = fopen("crypt1.out","w");

	assert(fpin != NULL && fpout != NULL);
	fscanf(fpin,"%d",&N);
	for(i = 0; i < N; i++)
		fscanf(fpin,"%d",&set[i]);

	/// inital digits state
	for(i=0; i <= 9; i++)
		digits[i] = 0;

	for(i = 0; i < N; i++)
		digits[set[i]] = 1;
#if 0
	/// just for test
	for(i=0; i< N;i++)
		fprintf(stdout,"%d ", set[i]);
	fprintf(stdout,"\n");
	for(i=0; i<= 9; i++)
		fprintf(stdout,"%d %d\n",i, digits[i]);
#endif 
	trace(0);
#if 0
	fprintf(stdout,"%d\n",NotInSet(9324));
#endif 
	fprintf(fpout,"%d\n",count);
	return 0;
	
}