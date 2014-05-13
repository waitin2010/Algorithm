#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
/**
 * Definition for binary tree with next pointer.
  *
 */
struct TreeLinkNode {
	int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 };
void pre_process(TreeLinkNode *root){
	TreeLinkNode * pointer_tree_node = root;
	while(pointer_tree_node!=NULL){
		pointer_tree_node->next = NULL;
		pointer_tree_node = pointer_tree_node->right;
	}
}
void connect_helper(TreeLinkNode *root){
	 /// special case 
		if(root==NULL) return ;

		/// traversal the right node of left subtree and the correspond the left node
		/// of right subtree, connect each pair

		TreeLinkNode *pointer_left_node = root->left;
		TreeLinkNode *pointer_right_node = root->right;

		while(pointer_left_node != NULL) {
			pointer_left_node->next = pointer_right_node;
			pointer_left_node = pointer_left_node->right;
			pointer_right_node = pointer_right_node->left;
		}

		/// do the same operation for left and right subtree
		connect_helper(root->left);
		connect_helper(root->right);
}
void connect(TreeLinkNode *root) {
	   pre_process(root);
       connect_helper(root);
}
int base = 1;
int depth = 4;
TreeLinkNode* construct_tree(int values){
	TreeLinkNode *root = NULL;
	if(values<depth){
		root = new TreeLinkNode(base++);
		root->left = construct_tree(values + 1);
		root->right = construct_tree(values+ 1);
		root->next = NULL;
	}
	return root;
}
void print(TreeLinkNode *root){
	while(root!=NULL){
		TreeLinkNode *pointer_tree_node = root;
		while(pointer_tree_node!=NULL){
			printf("%d ",pointer_tree_node->val);
			pointer_tree_node = pointer_tree_node->next;
		}
		printf("#");
		root = root->left;
	}
}
int main(){
	TreeLinkNode *root = construct_tree(1);
	connect(root);
	print(root);
	return 0;
}
