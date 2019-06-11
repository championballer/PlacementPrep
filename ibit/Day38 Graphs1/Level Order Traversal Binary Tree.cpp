/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    
    vector<vector<int> > result; 
    queue<TreeNode*> pendingNodes;
    pendingNodes.push(A);
    
    while(!pendingNodes.empty())
    {
        TreeNode* top = pendingNodes.front();
        vector<TreeNode*> currentlevel;
        vector<int> aux;
        while(!pendingNodes.empty())
        {
            currentlevel.push_back(pendingNodes.front());
            aux.push_back(pendingNodes.front()->val);
            pendingNodes.pop();
        }
        result.push_back(aux);
        
        for(int i=0;i<currentlevel.size();i++)
        {
            if(currentlevel[i]->left)pendingNodes.push(currentlevel[i]->left);
            if(currentlevel[i]->right)pendingNodes.push(currentlevel[i]->right);
        }
    
    }
    
    return result;
}
