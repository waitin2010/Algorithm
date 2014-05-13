#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <stack>
using namespace std;
/*
 *˼·���ݹ飬�����Ƕ������������ѡ����һ������㣬����Ϊ���i��
 *��[1��i-1]��Χ�Ľ��Ϊ���i����������㣬[i+1��n]��Χ�Ľ��Ϊ���i�����������
 *�����Խ��iΪ������BST����Ϊ���������ɹ���BST�����ĳ˻���
 *�������˼·������д�����µݹ����
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
