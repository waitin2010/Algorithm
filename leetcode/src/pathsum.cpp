#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;



/**
 * Definition for binary tree
 * 
 */
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

/// recurse
bool hasPathSum(TreeNode *root, int sum) {
	// if it is an empty tree, return false
     if(root==NULL) return false;

	 if(root->left == NULL && root->right == NULL && sum == root->val) return true;

	 bool leftsubtree = false, rightsubtree = false;
	 if(root->left&&hasPathSum(root->left, sum - root->val))
		 return true;

	 if(root->right&&hasPathSum(root->right,sum - root->val))
		 return true;

	 return false;


}
int main(){
	TreeNode *root = new TreeNode(1);
	hasPathSum(root,1);
	return 0;
}
