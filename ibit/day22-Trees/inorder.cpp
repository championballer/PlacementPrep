/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
vector<int> Solution::inorderTraversal(TreeNode* A) {
    
    vector<int> result;
    if(A==NULL)return result;
    
    stack<TreeNode*> st;
    TreeNode * current = A;
    do{
        if(current==NULL)
        {
            current = st.top();
            st.pop();
            result.push_back(current->val);
            current = current->right;
        }
        
        else
        {
            st.push(current);
            current = current->left;
        }
    }while(!st.empty() || current!=NULL);
    
    return result;
}
