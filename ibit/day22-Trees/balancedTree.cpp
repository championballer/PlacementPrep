/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
struct st
{
    bool ans;
    int height;
};

struct st helper(TreeNode* root)
{
    if(root==NULL)
    {
        struct st result;
        result.ans = true;
        result.height = 0;
        
        return result;
    }
    
    struct st leftresult = helper(root->left);
    struct st rightresult = helper(root->right);
    
    struct st result;
    result.ans = (leftresult.ans)&&(rightresult.ans)&&(abs(leftresult.height-rightresult.height)<=1);
    result.height = max(leftresult.height,rightresult.height)+1;
    
    return result;
}


int Solution::isBalanced(TreeNode* A) {
    
    return helper(A).ans;
}
