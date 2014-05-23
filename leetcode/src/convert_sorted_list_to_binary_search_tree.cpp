/* problem: convert sorted list to binary search tree
 * descp  : Given a singly linked list where elements
 *         are sorted in ascending order, convert it
 *         to  a height balanced BST.
 */

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;
/**
* Definition for singly-linked list.
*/
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

/**
 * Definition for binary tree
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode *sortedListToBST(ListNode *head)
{
  
}

int main(){
	return 0;
}
