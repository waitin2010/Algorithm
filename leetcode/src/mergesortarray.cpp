#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

 void merge(int A[], int m, int B[], int n) {
	int len = m + n;			// the merged array's length
	int ptoLastA = m - 1;		// point to the last element of array A
	int ptoLastB = n - 1;		// point to the last element of array B
					// the max element on the end of two array A and B
	while(--len>=0){
		int max = INT_MIN;
		bool computeA = false;
		if(ptoLastA>=0){
			max = A[ptoLastA--];
			computeA = true;
		}
		if(ptoLastB>=0&&max<B[ptoLastB]){
			max = B[ptoLastB--];
			if(computeA){
				ptoLastA++;
				computeA = false;
			}
		}
		A[len] = max;
	}
}
int main(){
	int A[6] = {4,5,6};
	int B[] = {1,2,3};
	merge(A,0,B,3);
	return 0;
}
