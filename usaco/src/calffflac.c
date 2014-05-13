/*
ID: come_1b1
LANG: C
TASK: calfflac
*/
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

char contents[20000];
int len;
int isSame(char a, char b)
{
	if(a == b )
		return 1;
	else if(isalpha(a)&&isalpha(b)&&abs(a-b) == abs('a' - 'A'))
		return 1;
	else
		return 0;
}
int prevChar(int index)
{
	while(index--&&!isalpha(contents[index]))
		;
	return index;
}

int nextChar(int index)
{
	while(index++ < len &&!isalpha(contents[index]))
		;
	return index;
}
int main(int argc, char** argv)
{
	FILE *fpin, *fpout;
     int start, end, length;
	 int start_t,end_t, length_t;
	 int i;
	char temp[80];
	char *cont;
	fpin = fopen("calfflac.in","r");
	fpout = fopen("calfflac.out","w");
	
	cont = contents;
	cont[0] = '\0';
	start = 0;
	end = 0;
	length = 0;
	while(fgets(temp,80,fpin)!=NULL)
	{
		len = strlen(temp);
		strncat(cont,temp,len);
		cont += len ;
	}
	len = strlen(contents);
	for(i = 0; i < len; i++)
	{
		if(isalpha(contents[i]))
		{
			start_t = i;
			end_t = i;
			length_t = 1;
			while((start_t = prevChar(start_t))>=0&&
				(end_t = nextChar(end_t))<len&&
				isSame(contents[start_t],contents[end_t]))
			{
				//fprintf(stdout,"%d:%d %d %c %c\n",i,start_t,end_t,contents[start_t],contents[end_t]);
				//fflush(stdout);
				length_t+=2;
			}
			if(length_t > length)
			{
				start = nextChar(start_t);
				end = prevChar(end_t);
				if(start_t < 0)
					end = end_t;
				length = length_t;
			}
		}else
			continue;
	}
	for(i = 0; i < len; i++)
	{
		if(!(ispunct(contents[i])||isspace(contents[i])))
		{
			
			start_t = i;
			end_t = nextChar(i);
			if(!isSame(contents[start_t],contents[end_t]))
				continue;
			length_t = 2;
			while((start_t = prevChar(start_t))>=0&&
				(end_t = nextChar(end_t))<len&&
				isSame(contents[start_t],contents[end_t]))
			{
				//fprintf(stdout,"%d:%d %d %c %c\n",i,start_t,end_t,contents[start_t],contents[end_t]);
				//fflush(stdout);
				length_t+=2;
			}
			if(length_t > length)
			{
				start = nextChar(start_t);
				end = prevChar(end_t);
				if(start_t < 0)
					end = end_t;
				length = length_t;
			}
		}else
			continue;
	}
	fprintf(fpout,"%d\n",length);
	for(i = start; i <= end; i++)
		fprintf(fpout,"%c",contents[i]);
	fprintf(fpout,"\n");
	//fflush(stdout);
	return 0;
}