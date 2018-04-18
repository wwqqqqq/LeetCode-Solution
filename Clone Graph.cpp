/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    map<UndirectedGraphNode *,UndirectedGraphNode *> s;
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL) return NULL;
        if(s.find(node)!=s.end()) return s[node];
        UndirectedGraphNode *newNode = new struct UndirectedGraphNode(node->label);
        s.insert(pair<UndirectedGraphNode *,UndirectedGraphNode *>(node,newNode));
        for(auto iter=node->neighbors.begin();iter!=node->neighbors.end();iter++)
        {
            newNode->neighbors.push_back(cloneGraph(*iter));
        }
        return newNode;
    }
};