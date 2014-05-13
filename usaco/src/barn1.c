/*
ID: come_1b1
LANG: C
TASK: barn1
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

struct Object
{	
	int index;
	int distance;
};
int compare(const void *aa, const void *bb)
{
	struct Object *a =(struct Object *)aa;
	struct Object *b =(struct Object *)bb;
	return b->distance - a->distance;
}

int cmpInt(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
int main(int argc, char **argv)
{
	int M,S,C;
	int stalls[200];
	struct Object objects[200];
	int indexs[50];
	int i, length,bound;
	FILE *fpin,*fpout;

	fpin = fopen("barn1.in","r");
	fpout = fopen("barn1.out","w");
	assert(fpin != NULL && fpout != NULL);
	fscanf(fpin,"%d %d %d",&M,&S,&C);
	for(i = 0; i < C; i++)
		fscanf(fpin,"%d",&stalls[i]);
	qsort(stalls,C,sizeof(int),cmpInt);
	for(i=0; i <C - 1; i++)
	{
		objects[i].index = i;
		objects[i].distance = stalls[i+1] - stalls[i];
	}
	qsort(objects,C-1,sizeof(struct Object),compare);
	bound = M>C? C:M;
	for(i=0; i<bound -1; i++)
		indexs[i] = objects[i].index;
	indexs[i++] = -1;
	indexs[i++] = C-1;
	qsort(indexs,bound,sizeof(int),cmpInt);
	length = 0;
	for(i=0;i<bound;i++)
		length += stalls[indexs[i+1]] - stalls[indexs[i]+1] + 1;
	fprintf(fpout,"%d\n",length);
	return 0;

}