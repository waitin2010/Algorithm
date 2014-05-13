#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int removeElement(int A[], int n, int elem) 
{
	int low = 0, hight = n-1;
	while(low<=hight)
	{
		if(A[low]!=elem) low++;
		else if(A[hight]==elem) hight--;
		else
			A[low++] = A[hight--];
	}
	return hight+1;
}
int main(){
	int A[] = {1, 2, 2, 4, 3, 6, 7 ,8, 3};
	cout<<removeElement(A,sizeof(A)/sizeof(A[0]),3);
	return 0;
}
