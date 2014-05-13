#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
const int max_step = 100000;
int step[max_step] = {0, 1};
int climbStairs(int n) {
	
	if(n<=1) return step[n];
	for(int i=2;i<=n;i++){
		step[i] = step[i-1] + step[i-2];
	}
	return step[n];
}
int main(){
	
	for(int i=0;i<10;i++)
		printf("%d\n", climbStairs(i));

	return 0;
}
