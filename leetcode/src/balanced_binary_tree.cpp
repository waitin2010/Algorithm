#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
/* problem
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as
a binary tree in which the depth of the two subtrees of every 
node never differ by more than 1. 
*/
 /*Definition for binary tree*/
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
int depth_binary_tree(TreeNode *root)
{
	if(root==NULL) return 0;
	int depth = depth_binary_tree(root->left)>depth_binary_tree(root->right)?depth_binary_tree(root->left):depth_binary_tree(root->right);
	return depth+1;
}
 bool isBalanced(TreeNode *root) 
{
       if(root==NULL) return true;
	   int depth_left = depth_binary_tree(root->left);
	   int depth_right = depth_binary_tree(root->right);
	   if(abs(depth_left - depth_right)<=1.0)
		   return true;
	   else
		   return false;
}
int main()
{

	return 0;
}
