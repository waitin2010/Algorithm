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

bool hasCycle1(ListNode *head) {
        map<ListNode*,int> list_node_count;

		if(head == NULL) return false;

		ListNode *p_list_node = head;
		while(p_list_node != NULL && list_node_count.find(p_list_node)==list_node_count.end()){
			list_node_count.insert(make_pair(p_list_node,1));
			p_list_node = p_list_node->next;
		}
		if(p_list_node == NULL) return false;
		else return true;
 }
bool hasCycle(ListNode *head) {
       if(head == NULL) return false;

	   ListNode *slow_pointer = head;
	   ListNode *fast_pointer = head;
	   int count = 10000;
	   do {
		   /// the max step for traversal
		   if(count--<0) break;

		   /// slow pointer go one step each time
		   if(slow_pointer == NULL) return false;
		   else slow_pointer = slow_pointer->next;

		   if(fast_pointer->next == NULL || fast_pointer->next->next == NULL)
			   return false;
		   else
				fast_pointer = fast_pointer->next->next;

		   if(slow_pointer == fast_pointer)
			   return true;
	   }while(true);
	   return true;
 }
int main(){
	ListNode *head, *temp;
	head = new ListNode(10);
	temp = new ListNode(20);

	head->next = temp;
	temp->next = NULL;
	cout<<hasCycle(head);
	return 0;
}
