/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
struct compare{ 
    bool operator()(ListNode* A, ListNode* B) 
    { 
        return A->val>B->val;
    } 
}; 
ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
    priority_queue<ListNode*, vector<ListNode*>, compare> pq;
    for(int i=0;i<A.size();i++)
    {
        ListNode* currentHead = A[i];
        while(currentHead!=NULL)
        {
            pq.push(currentHead);
            ListNode* temp = currentHead;
            currentHead = currentHead->next;
            temp->next = NULL;
        }
    }
    
    ListNode* head = NULL;
    ListNode* tail = NULL;
    while(!pq.empty())
    {
        ListNode* top = pq.top();
        pq.pop();
        
        if(head==NULL)
        {
            head = top;
            tail = top;
        }
        
        else
        {
            tail->next = top;
            tail = tail->next;
        }
    }
    return head;
}

