/*
ID: come_1b1
LANG: C
TASK: milk3
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#if 1
int funcMax(int a, int b) {
	return a>b?a:b;
}

int funcMin(int a, int b) {
	return a>b?b:a;
}
#endif 
int main(int argc, char **argv)
{
	FILE *fpin, *fpout;
	int a, b, c;
	int d[21];
	int Max, Min, Middle;
	int i;
	fpin = fopen("../../data/milk3.in","r");
	fpout = fopen("../../data/milk3.out","w");
	
	fscanf(fpin,"%d %d %d",&a, &b, &c);
	a = 10, b = 5, c = 2;
	memset(d,0,sizeof(int)*21);
	d[0] =1;
	
	Max = funcMax(a,funcMax(b,c));
	Min = funcMin(a,funcMin(b,c));
	if(a!=Max&&a!=Min)
		Middle = a;
	if(b!=Max&&b!=Min)
		Middle = b;
	if(c!=Max&&c!=Min)
		Middle = c;
	for(i=0;i<=Middle/Min;i++)
		d[Middle-i*Min] = 1;
	d[Min] = 1;
	d[a] = 1;
	for(i=0;i<21;i++)
		if(d[i])
			printf("%d ",c - i);
	printf("%d %d %d\n", Max, Middle, Min);
	return 0;
}