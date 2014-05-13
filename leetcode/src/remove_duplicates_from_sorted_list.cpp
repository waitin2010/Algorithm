#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;


struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
/*
 * let pointer_list_node pointer to the head,
 * if the next list node value is the same of this previous node, remove the next node
 * else assign pointer_list_node to the next list node
 */
 ListNode *deleteDuplicates(ListNode *head) {
        /// special case
	 if(head == NULL|| head->next == NULL) return head;
	 ListNode *pointer_list_node = head;
	 ListNode *pointer_list_next_node;

	 while(pointer_list_node!=NULL&&pointer_list_node->next!=NULL){
		 pointer_list_next_node = pointer_list_node->next;
		 while(pointer_list_next_node!=NULL&&pointer_list_node->val == pointer_list_next_node->val)
			 pointer_list_next_node = pointer_list_next_node->next;
		 pointer_list_node->next = pointer_list_next_node;
		 pointer_list_node = pointer_list_next_node;
	 }
	 return head;
 }
 ListNode* construct_list(int len){
	 ListNode *head = NULL;
	 ListNode *pointer_rail_node = head;
	 for(int i=0;i<len;i++){
		 ListNode *new_node = new ListNode(1);
		 new_node->next = NULL;
		 if(head == NULL){
			 head = new_node;
			 pointer_rail_node = head;
		 }
		 else {
			 pointer_rail_node->next = new_node;
			 pointer_rail_node = new_node;
		 }
	 }
	 return head;
 }

int main(){
	ListNode *head, *temp;
	
	head = construct_list(10);
	deleteDuplicates(head);
	return 0;
}
