/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


 
TreeNode* helper(vector<int>& in, vector<int>& post, int isi, int iei, int psi, int pei,unordered_map<int,int> & ourmap)
{
    if(isi>iei && psi>pei)return NULL;
    
    int rooti = ourmap[post[pei]];
    int n = iei-rooti;
    int rpsi = pei-n;
    int rpei = pei-1;
    int lpsi = psi;
    int lpei = rpsi-1;
    int lisi = isi;
    int liei = rooti-1;
    int risi = rooti+1;
    int riei = iei;
    
    TreeNode* root = new TreeNode(in[rooti]);
    root->left = helper(in,post,lisi, liei, lpsi, lpei,ourmap);
    root->right = helper(in,post,risi, riei, rpsi, rpei,ourmap);
    
    return root;
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    
    unordered_map<int,int> ourmap;
    for(int i=0;i<A.size();i++)
    {
        ourmap[A[i]] = i;
    }
    return helper(A,B,0,A.size()-1,0,B.size()-1,ourmap);
}
