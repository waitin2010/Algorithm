#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <ctype.h>

#define Test 0

int caseNum;
int n,m;
int nTest;
char data[51][51];

int  test(int ii, int jj, char *world) {
	
	int i,j,len;

	len = strlen(world);

	/* case 1 */
	for(i=0;jj+i<m&&i<len;i++){
		if(world[i] != data[ii][jj+i])
			break;
	}
   if(i>=len)
	  return 1;
    /* case 2 */
   	for(i=0;ii+i<n&&jj+i<m&&i<len;i++){
		if(world[i] != data[ii+i][jj+i])
			break;
	}
   if(i>=len)
	  return 1;

   /*case 3 */
   for(i=0; ii+i<n&&i<len;i++) {
	   if(world[i] != data[ii+i][jj])
		   break;
   }
	if(i>=len)
		return 1;

	/* case 4 */
	for(i=0;ii+i<n&&jj-i>=0&&i<len;i++) {
		if(world[i] != data[ii+i][jj-i])
			break;
	}
	if(i>=len)
		return 1;

	/* case 5 */
	for(i=0;jj-i>=0&&i<len;i++) {
		if(world[i] != data[ii][jj-i])
			break;
	}
	if(i>=len)
		return 1;

	/* case 6 */
	for(i=0;jj-i>=0&&ii-i>=0&&i<len;i++) {
		if(world[i] != data[ii-i][jj-i])
			break;
	}
	if(i>=len)
		return 1;

	/* case 7 */
	for(i=0;ii-i>=0&&i<len;i++) {
		if(world[i] != data[ii-i][jj])
			break;
	}
	if(i>=len)
		return 1;

	/* case 8 */
	for(i=0;ii-i>=0&&jj+i<m&&i<len;i++) {
		if(world[i] != data[ii-i][jj+i])
			break;
	}
	if(i>=len)
		return 1;

	return 0;
}

void toLow(){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<m;j++) {
			if(isupper(data[i][j]))
				data[i][j] = tolower(data[i][j]);
		}
	}
}
void toLow2(char *world){
	int i, len;

	len = strlen(world);
	for(i=0;i<len;i++)
		if(isupper(world[i]))
			world[i] = tolower(world[i]);
}

void process(char *world){
	int i,j;

	for(j=0;j<m;j++){
		int found = 0;
		 {
			for(i=0;i<n;i++)
			if(test(i,j,world)){
				printf("%d %d\n",i+1,j+1);
				found = 1;
				break;
			}
		}
		if(found) break;
	}

}

int main(){
	int i,j;

	scanf("%d",&caseNum);

	for(i=0; i<caseNum; i++) {
		scanf("%d %d",&n,&m);
		for(j=0;j<n;j++) {
			scanf("%s",data[j]);
		}
		toLow();

		scanf("%d",&nTest);
		for(j=0;j<nTest;j++){
			char world[256];
			scanf("%s",world);
			toLow2(world);
#if Test 
			printf("%s",world);
#endif 
			process(world);
			
		}
		if(i!=caseNum-1)
			printf("\n");
	}
#if Test
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("%c",data[i][j]);
		}
		putchar('\n');
	}
#endif 
	return 0;
}