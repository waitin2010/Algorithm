#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int n;
float u,v,p;
int type;

void getDigit(char *str,int start,float *v,char c){
	char temp[20];
	int count;

	count = 0;
	while(str[++start]!=c){
		temp[count++] = str[start];
	}
	temp[count]='\0';
	c = temp[count-1];
	if(isdigit(c)){
		*v = atof(temp);
	}else{
		temp[count-1]='\0';
		*v = atof(temp);
		switch(c){
		case 'M':
			*v *= 1000;
		case 'k':
			*v *= 1000;
			break;
		case 'm':
			*v /= 1000;
			break;
	
		}
	}
}


int main(){
	int c,unit,i,len,count;
	char str[256];

	scanf("%d",&n);
	count = 0;
	getchar();
	while(n--){
		gets(str);
		unit = 0;
		len = strlen(str);
		for(i=0;i<len-1;i++){
			if(str[i+1]!='=') continue;
			switch(str[i]){
			case 'P':
				getDigit(str,i+1,&p,'W');
				unit += 1;
				break;
			case 'U':
				getDigit(str,i+1,&u,'V');
				unit += 4;
				break;
			case 'I':
				getDigit(str,i+1,&v,'A');
				unit += 2;
				break;
			default:
				break;
			}
		}
		printf("Problem #%d\n",++count);
		switch(unit){
		case 3:
			printf("U=%.2lfV\n", p/v);
			break;
		case 5:
			printf("I=%.2lfA\n",p/u);
			break;
		case 6:
			printf("P=%.2lfW\n",u*v);
			break;
		}
		printf("\n");
			
	}
	return 0;
}