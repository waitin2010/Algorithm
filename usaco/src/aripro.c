
/*
ID: come_1b1
LANG: C
TASK: ariprog
*/

#include <stdio.h>
#include <stdlib.h>
/*
ID: come_1b1
LANG: C
TASK: ariprog
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int N, M;
FILE *fpin, *fpout;
int set[251 + 251 * 251];
int dist[2*250*250+1];
int count,dcount;
int cmpInt(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
void initSet()
{
	int temp[251];
	int i,j;
	for(i=0; i <= M; i++)
	{
		temp[i] = i * i;
		set[count++] = temp[i];
	}	
	for(i=0; i <= M; i++)
		for(j=i; j<= M; j++)
		{
			set[count++] = temp[i] + temp[j];
			dist[set[count-1]] = 1;
		}
	qsort(set,count,sizeof(int),cmpInt);
}
int bisearch(int *data,int s,int low, int hight)
{
	int mid;
	while(low <= hight){
		mid = (low + hight)/2;
		if(data[mid] == s)
			return 1;
		if(data[mid] > s)
			hight = mid -1;
		else
			low = mid +1;
	}
	return 0;
}
int inSet(int s)
{
	return bisearch(set,s,0,count-1);
}
int test(int a, int b, int n)
{
	return dist[a+n*b];
}
int main(int argc, char **argv)
{
	int i,j,k;
	int hasOne;
	int old_a = -1,old_b = -1;
	int upLimit; 
	int bLimit; 
	int Max;

	fpin = fopen("../../data/ariprog.in","r");
	fpout = fopen("../../data/ariprog.out","w");

	fscanf(fpin, "%d %d",&N, &M);
	//N = 20, M = 200;
	hasOne = 0;
	initSet();

	upLimit = count;
	bLimit = dcount;
	Max = set[upLimit-1];	

	for(j = 1; j < Max; j++)
	{
		int b = j;
		if( b > Max/(N-1))
			continue;
		for(i = 0; i < upLimit-N; i++ ){
			int a = set[i];
			if(old_a == a)
				continue;
			else
				old_a = a;
			if(a > Max - b * (N-1))
				continue;
			for(k =0; k < N; k++)
				if(test(a,b,k))
					continue;
				else
					break;
			if(k >= N)
			{
				fprintf(fpout,"%d %d\n",a,b);
				hasOne = 1;
			}
		}
	}

	if(!hasOne)
		fprintf(fpout,"NONE\n");
	return 0;
}