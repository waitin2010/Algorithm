#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <stack>
using namespace std;
/*
 *思路：递归，由于是二叉查找树，先选择任一结点根结点，假设为结点i，
 *则[1，i-1]范围的结点为结点i的左子树结点，[i+1，n]范围的结点为结点i的右子树结点
 *，则以结点i为根结点的BST个数为左，右子树可构成BST个数的乘积，
 *基于这个思路，可以写出以下递归程序
*/
int numTree(int start, int end)
{
	if(start>=end)
		return 1;
	int totalTree = 0;
	for(int i=start; i<=end;i++)
		totalTree += numTree(start,i-1)*numTree(i+1,end);
	return totalTree;
}
int numTrees(int n)
{
	return numTree(1,n);       
 }
int main(){

	cout<<numTrees(3);
	return 0;
}
