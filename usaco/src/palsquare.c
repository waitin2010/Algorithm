/*
ID: come_1b1
LANG: C
TASK: palsquare
*/
#include <stdio.h>
#include <string.h>

char digits[21] = "0123456789ABCDEFGHIJ";
int Base;
char temp[18];
char *toBaseString(int n);
int isPalindromic(char *str);
char *revert(char *str);
int main(int argc, char** argv)
{
	FILE *fpin = fopen("palsquare.in","r");
	FILE *fpout = fopen("palsquare.out","w");
	char *str;
	int i;
	fscanf(fpin,"%d",&Base);
	for(i = 1; i <= 300; i++)
	{
	  str = toBaseString(i*i);
	  if(isPalindromic(str))
		{
			fprintf(fpout,"%s ",revert(toBaseString(i)));
			fprintf(fpout,"%s\n",toBaseString(i*i));
	    }
	}
	return 0;
}
char *toBaseString(int n)
{
	int i =0;
	while(n>0)
	{
	
		temp[i++] = digits[n%Base];
		n /=Base;
	}
	temp[i] = '\0';
	return temp;
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
char *revert(char *str)
{
	int len;
	int i;
	char c;
	len = strlen(str);
	for(i = 0; i<len/2;i++)
	{
		c = str[i];
		str[i] = str[len-i-1];
		str[len-i-1] = c;
	}
	return temp;
}