/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 
void solve(UndirectedGraphNode* root, UndirectedGraphNode* node, unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> & visited)
{
    
    for(int i=0;i<node->neighbors.size();i++)
    {
        UndirectedGraphNode* next = node->neighbors[i];
        if(visited.count(next)!=0)
        {
            root->neighbors.push_back(visited[next]);
            continue;
        }
        
        else
        {
            UndirectedGraphNode* cnext = new UndirectedGraphNode(next->label);
            visited[next] = cnext;
            root->neighbors.push_back(cnext);
            solve(cnext,next,visited);
        }
    }
}
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    if(node==NULL)return node;
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> visited;
    UndirectedGraphNode* root = new UndirectedGraphNode(node->label);
    visited[node] = root;
    solve(root,node,visited);
    
    return root;
}
