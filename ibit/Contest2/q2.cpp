/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
string Solution::solve(TreeNode* A, int B) {
    
    queue<TreeNode*> pendingNodes;
    queue<TreeNode*> children;
    pendingNodes.push(A);
    int count = 0;
    string ans = "";
    
    while(!pendingNodes.empty())
    {
        if(count==B)
        {
            while(!pendingNodes.empty())
            {
                TreeNode* top = pendingNodes.front();
                //cout<<top->val<<endl;
                pendingNodes.pop();
                
                ans+=(top->val+'0');
            }
        }
        
        else
        {
            while(!pendingNodes.empty())
            {
                TreeNode* top = pendingNodes.front();
                //cout<<top->val<<endl;
                pendingNodes.pop();
                if(top->left)
                {
                    children.push(top->left);
                }
                
                if(top->right)
                {
                    children.push(top->right);
                }
            }
            
            while(!children.empty())
            {
                pendingNodes.push(children.front());
                children.pop();
            }
            
            count++;
        }
        
    }
    
    return ans;
}
