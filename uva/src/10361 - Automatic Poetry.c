#include <stdio.h>
#include <string.h>

/* input data */
int n;
char s1[256], s2[256], s3[256], s4[256],s5[256];

int main(){
	int i;
	scanf("%d",&n);
	

	for(i=0;i<n;i++){
		int c;
		char *str = s1;
		int first, second,count;
		int third = 0;

		first = second = count = 0;
		memset(s1,0,256);
		memset(s2,0,256);
		memset(s3,0,256);
		memset(s4,0,256);
		memset(s5,0,256);
		getchar();
		while((c=getchar())!='\n'){
			if(c=='<'){
				if(!first){
					str = s2;
				}else{
					str = s4;
				}
				first = 1;
				count = 0;
				continue;
			}
			if(c=='>'){
				if(!second){
					str = s3;
				}else{
					str = s5;
				}
				second = 1;
				count = 0;
				continue;
			}
			str[count++] = c;
		}
		printf("%s%s%s%s%s\n",s1, s2, s3, s4, s5);
	
		while(third!=2){
			if((c=getchar())!='.')putchar(c);
			else third++;
		}
		printf("%s%s%s%s\n",s4, s3, s2, s5);
		getchar();
	}
	return 0;
}