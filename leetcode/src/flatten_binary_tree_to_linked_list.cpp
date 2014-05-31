/* Problem: Flatten Binary Tree to Linked List
 * Given a binary tree, flatten it to a linked list in-place
 */

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
/**
 * Definition for binary tree
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* flatten_func(TreeNode* root)
{
  if(root == NULL||(root->left == NULL && root->right == NULL))
    return root;
      
  TreeNode *first = root-> left;
  TreeNode *last = flatten_func(root->left);
  if(root->left!=NULL)
  {
    
    last->right = root->right;
    root->right = root->left;
  }
  
  last = flatten_func(root->right);
  root->left = NULL;
  
  
  return last;
  
  
}

  
void flatten(TreeNode *root)
{
  flatten_func(root);
  
}

int main(){
	return 0;
}
