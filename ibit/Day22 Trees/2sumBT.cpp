/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int t2Sum(TreeNode* A, int B) {
    if(A==NULL)return 0;
    
    stack<TreeNode*> left;
    stack<TreeNode*> right;
    
    TreeNode* leftCurrent = A;
    TreeNode* rightCurrent = A;
    
    TreeNode* topLeft = NULL;
    TreeNode* topRight = NULL;
    
    int leftFlag = 1;
    int rightFlag = 1;
    do{
        while(leftFlag && leftCurrent)
        {
            left.push(leftCurrent);
            leftCurrent = leftCurrent->left;
        }
        
        if(leftFlag && !leftCurrent)
        {
            topLeft = left.top();
            left.pop();
            leftCurrent = topLeft->right;
            leftFlag = 0;
        }
        
        while(rightFlag && rightCurrent)
        {
            right.push(rightCurrent);
            rightCurrent = rightCurrent->right;
        }
        
        if(rightFlag && !rightCurrent)
        {
            topRight = right.top();
            right.pop();
            rightCurrent = topRight->left;
            rightFlag = 0;
        }
        
        if(topLeft->val==topRight->val)return 0;
        if(topLeft->val + topRight->val==B)return 1;
        else if(topLeft->val+topRight->val<B)leftFlag = 1;
        else rightFlag = 1;
        
    }while(topLeft!=topRight);
    
    return 0;
}
