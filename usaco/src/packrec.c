
/*
ID: come_1b1
LANG: C
TASK: packrec
*/
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int rec[8];
int first[4];
int second[4];
int Min = 40000;
int display;
struct Result
{
	int a;
	int b;
}result[100];
int count;
int min(int a, int b)
{
	return a>b?b:a;
}
int max(int a,int b)
{
	return a>b?a:b;
}
int compareInt(const void *a, const void *b)
{
	struct Result *aa = (struct Result *)a;
	struct Result *bb = (struct Result*)b;
	return aa->a - bb->a;
}
void trace(int depth,int index)
{
	if(depth > 3)
	{
		/// basic 1
		int a = first[0] + first[1] + first[2]+first[3];

		int b = max(second[0],second[1]);
		b = max(b,second[2]);
		b = max(b,second[3]);
		if(display)
		{
			if(a*b == Min)
			{
				result[count].a = min(a,b);
				result[count++].b = max(a,b);
			}
		}else
		{
			if(a*b < Min)
				Min = a*b;
		}


		/// basic 2
		a = first[0] + first[1] + first[2];
		b = max(second[0],second[1]);
		b = max(second[2],b);

		a = max(a,first[3]);
		b = b + second[3];
		if(display)
		{
			if(a*b == Min)
			{
				result[count].a = min(a,b);
				result[count++].b = max(a,b);
			}
		}else
		{
			if(a*b < Min)
				Min = a*b;
		}
		/// basic 3
		a = first[0] + first[1];
		b = max(second[0],second[1]);

		a = max(a,first[2]);
		b = b + second[2];

		a = a + first[3];
		b = max(b,second[3]);
		if(display)
		{
			if(a*b == Min)
			{
				result[count].a = min(a,b);
				result[count++].b = max(a,b);
			}
		}else
		{
			if(a*b < Min)
				Min = a*b;
		}

		/// basic 4
		a = first[0] + max(first[1],first[2])+first[3];
		b = max(second[0],second[1]+second[2]);
		b = max(b,second[3]);
		if(display)
		{
			if(a*b == Min)
			{
				result[count].a = min(a,b);
				result[count++].b = max(a,b);
			}
		}else
		{
			if(a*b < Min)
				Min = a*b;
		}
		/// basic 5
		a = max(first[0],first[1]) + first[2]+first[3];
		b = max(second[0]+second[1],second[2]);
		b = max(b,second[3]);
		if(display)
		{
			if(a*b == Min)
			{
				result[count].a = min(a,b);
				result[count++].b = max(a,b);
			}
		}else
		{
			if(a*b < Min)
				Min = a*b;
		}
		/// basic 6
		if((first[0]+first[1]) <= (first[2] + first[3]))
		{
			a = first[2] + first[3];
			b = max(second[0]+second[2],second[1]+second[3]);
			if(display)
			{
				if(a*b == Min)
				{
					result[count].a = min(a,b);
					result[count++].b = max(a,b);
				}
			}else
			{
				if(a*b < Min)
					Min = a*b;
			}
		}

	}else
	{
		first[depth] = rec[index];
		second[depth] = rec[index+1];
		trace(depth+1,index+2);

		first[depth] = rec[index+1];
		second[depth] = rec[index];
		trace(depth+1,index+2);
	}

}
int main(int argc, char**argv)
{
	FILE *fpin,*fpout;
	int i,old_a;
	fpin = fopen("packrec.in","r");
	fpout = fopen("packrec.out","w");
	assert(fpin!=NULL&&fpout!=NULL);
	for(i = 0; i < 8; i++)
		fscanf(fpin,"%d",&rec[i]);
	display = 0;
	trace(0,0);
	display = 1;
	fprintf(fpout,"%d\n",Min);
	trace(0,0);

	qsort(result,count,sizeof(struct Result),compareInt);
	old_a = -1;
	for(i = 0; i<count; i++)
	{
		if(result[i].a != old_a)
		{
			fprintf(fpout,"%d %d\n",result[i].a,result[i].b);
			old_a = result[i].a;
		}                                                  
	}
	/// just for test
#if 0
	for(i=0; i<8; i++)
		fprintf(stdout,"%d ",rec[i]);
#endif
	return 0;
}