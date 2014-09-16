#include <iostream>

using namespace std;
class ListNode{
public:
	int val;
	ListNode* next;
	ListNode(int v,ListNode* n):val(v),next(n)
	{
	}

};
ListNode* merge(ListNode* left,ListNode* right)
{
	if(left==NULL)
		return right;
	if(right==NULL)
		return left;
	if(left->val <right->val)
	{
		left->next=merge(left->next,right);
		return left;
	}
	right->next=merge(left,right->next);
	return right;	
}
ListNode* traverseToMid(ListNode* head)
{
	
	if(head==0||head->next==0)
		return head;
	ListNode* current=head;
	int count=0;
	while(current!=0)
	{
		current=current->next;
		count++;
	}
	current=head;
	for(int i=1;i<count/2;i++)
	{
		current=current->next;
	}
	return current;
}
ListNode* mergesort(ListNode* head)
{
	if(head==0||head->next==0)
		return head;
	ListNode* left=head;
	ListNode* mid= traverseToMid(head);
	ListNode* right=mid->next;
	mid->next=0;
	left=mergesort(head);
	right=mergesort(right);
	ListNode* merged= merge(left,right);
	return merged;
}
int main()
{
	ListNode* left=new ListNode(5,new ListNode(9,NULL));
	ListNode*right =new ListNode(4,new ListNode(10,new ListNode(11,0)));
	ListNode* merged=merge(left,right);
	ListNode* sorted=mergesort(new ListNode(9,new ListNode(4,new ListNode(5,new ListNode(1,new ListNode(2,0))))));
	return 0;
}