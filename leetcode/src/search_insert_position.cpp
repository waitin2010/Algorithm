#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
int searchInsert(int A[], int n, int target) {
        int low, hight, middle;
		low = 0;
		hight = n -1;
		while(low<=hight){
			middle = (low + hight)/2;
			if(A[middle] == target)
				return middle;
			else if(A[middle] > target)
				hight = middle -1;
			else 
				low = middle + 1;
		}
		return low;
    }
int main(){
	int A[] = {1,3,5,6};
	cout<<searchInsert(A,4,0);
	return 0;
}
