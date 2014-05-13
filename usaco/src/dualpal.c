
/*
ID: come_1b1
LANG: C
TASK: dualpal
*/
#include <stdio.h>
#include <string.h>
void toBaseString(char *temp,int n,int Base)
{
	int i =0;
	while(n>0)
	{

		temp[i++] = "0123456789"[n%Base];
		n /=Base;
	}
	temp[i] = '\0';
}
int isPalindromic(char *str)
{
	int len;
	int i;
	len = strlen(str);
	for(i = 0; i<len/2;i++)
		if(str[i] != str[len-i-1])
			return 0;
	return 1;
}
int main(int argc, char** argv)
{
	FILE *fpin,*fpout;
	int N,S,i;
	char temp[32];
	int count =0;
	fpin = fopen("dualpal.in","r");
	fpout = fopen("dualpal.out","w");
	fscanf(fpin,"%d %d",&N,&S);
	while(N>0&&S++)
	{
		count =0;
		for(i = 2; i <=10;i++)
		{
			toBaseString(temp,S,i);
			if(isPalindromic(temp))
			{
				count++;
				if(count>=2)
				{
					fprintf(fpout,"%d\n",S);
					N--;
					break;
				}
			}
		}
	}
	return 0; 
}