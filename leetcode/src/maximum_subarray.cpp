#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
map<int, int> sum; /// (key, value) = (first ith element , first ith big sum)

int maxSubArray(int A[], int n) {
	if(A==NULL||n<=0) return 0;
	for(int i=0;i<n;i++){
		if(sum.size()<=0){
			sum.insert(make_pair(0,A[i]));
		}else if(sum[i-1]>=0)
			sum.insert(make_pair(i,sum[i-1]+A[i]));
		else
			sum.insert(make_pair(i,A[i]));
	}
	int max = A[0];
	for(int i=0;i<sum.size();i++)
		max = max>sum[i]?max: sum[i];

	return max;
}
int main(){
	int A[] = { -2 ,1 ,-3,4,-1,2,1,-5,4};
	cout<<maxSubArray(A,sizeof(A)/sizeof(A[0]));
	return 0;
}
