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
 
vector<vector<int> > levelOrderBottom(TreeNode *root) {
	  
	  vector<vector<int>> result,ans;
      queue<TreeNode*> queue_bfs;
	  vector<int> curLevel;
	  int level_count;
	  int next_level_count;
	  int pop_count;
	  /// initialize the queue
	  if(root == NULL) return result;
	  queue_bfs.push(root);
	  level_count = 1;
	  next_level_count = 0;
	  pop_count = 0;
	  /// process
	  while(!queue_bfs.empty()){

		  TreeNode* pTreeNode = NULL;
		  pTreeNode = queue_bfs.front();
		  queue_bfs.pop();
		  pop_count++;
		  if(pop_count<=level_count){
			  curLevel.push_back(pTreeNode->val);
			  if(pTreeNode->left!=NULL){
				  queue_bfs.push(pTreeNode->left);
				  next_level_count++;
			  }
			  if(pTreeNode->right!=NULL){
				  queue_bfs.push(pTreeNode->right);
				  next_level_count++;
			  }
		  }
		  if(pop_count==level_count){
			  result.push_back(curLevel);
			  curLevel.clear();
			  pop_count = 0;
			  level_count = next_level_count;
			  next_level_count = 0;
		  }
	  }
	  for(int i=result.size()-1;i>=0;i--){
		  ans.push_back(result[i]);
	  }
	  return ans;
}

int main(){

	// build a tree
	vector<vector<int>> result;
	TreeNode* root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);

	root->left->left = new TreeNode(6);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(5);
	result = levelOrderBottom(root);
	return 0;
}
