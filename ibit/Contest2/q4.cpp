/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
bool checkPrime(int i)
{
    for(int j=2;j*j<=i;j++)
    {
        if(i%j==0)return false;
    }
    
    return true;
}

int sum(int val)
{
    int ans = 0;
    while(val>0)
    {
        ans+=(val%10);
        val/=10;
    }
    
    return ans;
}
ListNode* Solution::solve(ListNode* A) {
    
    bool sieve[180];
    memset(sieve,true,sizeof(bool)*180);
    sieve[0]=false;
    sieve[1]=false;
    for(int i=2;i<180;i++)
    {
        bool ans = sieve[i];
        if(sieve[i])
        {
            bool ans1 = checkPrime(i); 
            if(!ans1)sieve[i] = false;
            
            for(int j=2*i;j<180;j+=i)
            {
                sieve[j] = false;
            }
        }
    }
    
    ListNode* specialHead = NULL;
    ListNode* specialTail = NULL;
    ListNode* nonspecialHead = NULL;
    ListNode* nonspecialTail = NULL;
    ListNode* current = A;
    
    while(current!=NULL)
    {
        int s = sum(current->val);
        
        if(sieve[s])
        {
            if(!specialHead)
            {
                specialHead = current;
                specialTail = current;
            }
            
            else
            {
                specialTail->next = current;
                specialTail = specialTail->next;
            }
        }
        
        else
        {
            if(!nonspecialHead)
            {
                nonspecialHead = current;
                nonspecialTail = current;
            }
            
            else
            {
                nonspecialTail->next = current;
                nonspecialTail = nonspecialTail->next;
            }
        }
        ListNode* temp = current;
        current = current->next;
        temp->next = NULL;
    }
    if(specialHead==NULL)return nonspecialHead;
    else specialTail->next = nonspecialHead;
    return specialHead;
    
    
}
