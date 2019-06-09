#include<bits/stdc++.h>

using namespace std;

class ListNode{
public:
	int val;
	ListNode* next;

	ListNode(int val)
	{
		this->val = val;
		next = NULL;
	}
};

ListNode* takeInput()
{
	ListNode * head = NULL;
	ListNode * tail = NULL;

	int data;
	cin>>data;
	while(data!=-1)
	{
		ListNode* current = new ListNode(data);
		if(head==NULL)
		{
			head = current;
			tail = current;
		}

		else
		{
			tail->next = current;
			tail = tail->next;
		}

		cin>>data;

	}

	return head;
}
void printList(ListNode* A)
{
	ListNode * current = A;
	while(current!=NULL)
	{
		cout<<current->val<<" ";
		current = current->next;
	}

	cout<<endl;
}ow

ListNode* rev(ListNode* head)
{
	ListNode* prev = NULL;
	while(head!=NULL)
	{
		ListNode * next = head->next;
		head->next = prev;
		prev = head;
		if(head->next!=NULL)
		{
			head = next;	
		}
		else break;
	}

	printList(head);
	return head;
	 
}



int main()
{
	ListNode* l = takeInput();
	printList(l);
	ListNode* m = rev(l);
	printList(m);
}