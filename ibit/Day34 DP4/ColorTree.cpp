int current = 1;
class TreeNodeAux{
public:
	int val;
	TreeNodeAux* left;
	TreeNodeAux* right;
	vector<int> vect;
	TreeNodeAux(int x):val(x),left(NULL),right(NULL),vect(3,-1){}	
};


int mxgreen(TreeNodeAux* root, int color)
{
	if(root==NULL)return 0;
	if(root->vect[color]!=-1)return root->vect[color];

	if(color==0)
	{
		root->vect[color] = mxgreen(root->left,1)+mxgreen(root->right,2)+1;
		return root->vect[color];
	}

	else if(color==1)
	{
		root->vect[color] = max((mxgreen(root->left,0)+mxgreen(root->right,2)),(mxgreen(root->left,2)+mxgreen(root->right,0)));
		return root->vect[color];
	}

	else
	{
		root->vect[color] = max((mxgreen(root->left,0)+mxgreen(root->right,1)),(mxgreen(root->left,1)+mxgreen(root->right,0)));
		return root->vect[color];	
	}
}
void clear(TreeNodeAux* root)
{
    if(root==NULL)return;
    
    else
    {
        root->vect.assign(3, -1);
        clear(root->left);
        clear(root->right);
    }
}
int mngreen(TreeNodeAux* root, int color)
{
	if(root==NULL)return 0;
	if(root->vect[color]!=-1)return root->vect[color];

	if(color==0)
	{
		root->vect[color] = mngreen(root->left,1)+mngreen(root->right,2)+1;
		return root->vect[color];
	}

	else if(color==1)
	{
		root->vect[color] = min((mngreen(root->left,0)+mngreen(root->right,2)),(mngreen(root->left,2)+mngreen(root->right,0)));
		return root->vect[color];
	}

	else
	{
		root->vect[color] = min((mngreen(root->left,0)+mngreen(root->right,1)),(mngreen(root->left,1)+mngreen(root->right,0)));
		return root->vect[color];	
	}	
}

void makeTree(string s, int index,TreeNodeAux* root,stack<TreeNodeAux*> & st)
{
	if(index==s.length())return;
	if(s[index]=='0')
	{	
		if(!st.empty())
		{
			TreeNodeAux* top = st.top();
			st.pop();	
			makeTree(s,index+1,top,st);
		}
		else return;
		
			
	}
	if(s[index]=='1')
	{
		root->left = new TreeNodeAux(current);
		current++;
		makeTree(s,index+1,root->left,st);
	}

	if(s[index]=='2')
	{
		root->left = new TreeNodeAux(current);
		current++;
		root->right = new TreeNodeAux(current);
		current++;

		st.push(root->right);
		makeTree(s,index+1,root->left,st);
	}	
}


vector<int> Solution::solve(string A) {
    
    TreeNodeAux* root = new TreeNodeAux(current);
    current++;
    stack<TreeNodeAux*> st;
    makeTree(A,0,root,st);
    vector<int> result;
    result.push_back(mxgreen(root,0));
    clear(root);
    result.push_back(mngreen(root,1));
    
    return result;
}
