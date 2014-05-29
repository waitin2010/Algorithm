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
int getNodeNum(ListNode *head)
{
  if(head == NULL) return 0;
  ListNode *p = head;
  int length = 0;
  
  while(p)
  {
    length++;
    p = p->next;
  }

  return length;
}

ListNode* findListNode(ListNode* head, int index)
{
  ListNode *p = head;
  
  for(int i=1;i<index;i++)
    p = p->next;
  return p;
}


TreeNode *recurrence_travel(ListNode* head, int node_num)
{
  // special case
  TreeNode *root = NULL;
  
  if (head==NULL||node_num==0) return root;

  if(node_num == 1) 
  {
    root = new TreeNode(head->val);
    return root;
  }
  
  int left_list_node_num = node_num%2==0? node_num / 2 - 1 : node_num/2;
  int right_list_node_num = node_num - left_list_node_num - 1;
  
  int index = left_list_node_num + 1;
  
  ListNode* mid_node;
  mid_node = findListNode(head, index);
  root = new TreeNode(mid_node->val);
  root->left = recurrence_travel(head, left_list_node_num);
  root->right = recurrence_travel(mid_node->next, right_list_node_num);
  
}

TreeNode *sortedListToBST(ListNode *head)
{
  int node_num = getNodeNum(head);
  return recurrence_travel(head, node_num);
  
}
void print(TreeNode *tree)
{
  if(tree==NULL) return;
  
  cout<<tree->val<<endl;

  print(tree->left);
  print(tree->right);
}

int main(){
  ListNode *head = new ListNode(1);
  ListNode *second = new ListNode(2);
  head->next = second;
  
  second->next = new ListNode(3);
  second->next->next = new ListNode(4);
  
  
  TreeNode *tree = sortedListToBST(head);
  print(tree);
  
  tree = sortedListToBST(NULL);
  
  print(tree);
  
	return 0;
}
