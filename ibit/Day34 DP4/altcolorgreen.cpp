#define MAX 100000

struct Tree{
    int val ;
    Tree* left ;
    Tree* right ;
    Tree(){
        val=0 ;
        left=NULL ;
        right=NULL ;
    }
    Tree(int _val){
        val=_val ;
        left=NULL ;
        right=NULL ;
    }
} ;
int k=0 ;
void createTree(Tree *root,string s,int i)
{
        if(i==s.length())
            return ;
        int num=s[i]-'0' ;
        if(num==0)
            return ;    
        else if(num==1)
        {
           root->left=new Tree(k++) ;
           createTree(root->left,s,k-1) ;
        }
        else if(num==2)
        {
            root->left=new Tree(k++) ;
            createTree(root->left,s,k-1) ;
            root->right=new Tree(k++) ;
            createTree(root->right,s,k-1) ;
        }
}

void inorder(Tree *root)
{
    if(root==NULL)
    return ;
    inorder(root->left) ;
    cout<<root->val<<" ";
    inorder(root->right) ;
}

void preorder(Tree *root)
{
    if(root==NULL)
    return ;
    cout<<root->val<<" " ;
    preorder(root->left) ;
    preorder(root->right) ;
}



int dp[MAX][3] ;
int solveMax(Tree *root,int color)
{
    if(!root)
    return 0 ;
 
    if(dp[root->val][color]!=-1)
    return dp[root->val][color] ;
    
    if(color==1)
    {
        return dp[root->val][color]=(max(solveMax(root->left,2)+solveMax(root->right,3),solveMax(root->left,3)+solveMax(root->right,2))+1) ;
    }
    else if(color==2)
    {
        return dp[root->val][color]=max(solveMax(root->left,1)+solveMax(root->right,3),solveMax(root->left,3)+solveMax(root->right,1)) ;
    }
    else if(color==3)
    {
        return dp[root->val][color]=max(solveMax(root->left,2)+solveMax(root->right,1),solveMax(root->left,1)+solveMax(root->right,2)) ; 
    }
}

int solveMin(Tree *root,int color)
{
    if(!root)
    return 0 ;
 
    if(dp[root->val][color]!=-1)
    return dp[root->val][color] ;
    
    if(color==1)
    {
        return dp[root->val][color]=(min(solveMin(root->left,2)+solveMin(root->right,3),solveMin(root->left,3)+solveMin(root->right,2))+1) ;
    }
    else if(color==2)
    {
        return dp[root->val][color]=min(solveMin(root->left,1)+solveMin(root->right,3),solveMin(root->left,3)+solveMin(root->right,1)) ;
    }
    else if(color==3)
    {
        return dp[root->val][color]=min(solveMin(root->left,2)+solveMin(root->right,1),solveMin(root->left,1)+solveMin(root->right,2)) ; 
    }
}

vector<int> Solution::solve(string A) {
    memset(dp,-1,sizeof(dp)) ;
    k=0 ;
    int n=A.length() ;
    Tree* root=new Tree(k++) ;
    createTree(root,A,0) ;
    // inorder(root) ;
    // preorder(root) ;
    vector<int> ans;
    int mmax=INT_MIN ;
    mmax=solveMax(root,1) ;
    memset(dp,-1,sizeof(dp)) ;
    mmax=max(mmax,solveMax(root,2)) ;
    memset(dp,-1,sizeof(dp)) ;
    mmax=max(mmax,solveMax(root,3)) ;
    memset(dp,-1,sizeof(dp)) ;
    
    ans.push_back(mmax) ;
    
    int mmin=INT_MAX ;
    mmin=solveMin(root,1) ;
    memset(dp,-1,sizeof(dp)) ;
    mmin=min(mmin,solveMin(root,2)) ;
    memset(dp,-1,sizeof(dp)) ;
    mmin=min(mmin,solveMin(root,3)) ;
    
    ans.push_back(mmin) ;
    return ans ;
}