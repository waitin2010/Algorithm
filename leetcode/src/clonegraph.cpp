#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;



struct UndirectedGraphNode {
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
 };
 UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
       if(node==NULL) return NULL;
       
       map<int,UndirectedGraphNode *> clonegraph;
       queue<UndirectedGraphNode*> queuegraph;
       
       // bfs, and construct all graph node
       queuegraph.push(node);
       while(!queuegraph.empty()){
           UndirectedGraphNode *top = queuegraph.front();
           queuegraph.pop();
           if(clonegraph.find(top->label)==clonegraph.end()){//no found
               UndirectedGraphNode *newnode = new UndirectedGraphNode(top->label);
               clonegraph.insert(make_pair(newnode->label,newnode));
               // push all the neighbor node into queue
              if(!top->neighbors.empty()){
                 for(int i=0;i<top->neighbors.size();i++)
                     queuegraph.push(top->neighbors[i]);
               }
           }
        }
           
    
       
       //bfs, and construct the neighbor relationship for all node in clonegraph
       queuegraph.push(node);
       while(!queuegraph.empty()){
           UndirectedGraphNode *top = queuegraph.front();
           queuegraph.pop();
           UndirectedGraphNode *newnode = clonegraph[top->label];
           
           if(newnode->neighbors.empty()&&!top->neighbors.empty()){// newnode has not processed
				for(int i=0;i<top->neighbors.size();i++){
                   newnode->neighbors.push_back(clonegraph[top->neighbors[i]->label]);
                   queuegraph.push(top->neighbors[i]);
               }
           }
       }
	   return clonegraph[node->label];
    }
int main(){

	cout<<"hello, my friend"<< endl;
	UndirectedGraphNode *node = new UndirectedGraphNode(0);
	node->neighbors.push_back(new UndirectedGraphNode(1));
	node->neighbors.push_back(new UndirectedGraphNode(2));
	cloneGraph(node);
	return 0;
}
