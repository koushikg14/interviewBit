/*
Reorder List

Given a singly linked list

    L: L0 → L1 → … → Ln-1 → Ln,

reorder it to:

    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …

You must do this in-place without altering the nodes’ values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reorderList(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==NULL)
        return NULL;
    if(A->next==NULL)
        return A;
    ListNode *l1=A,*l2,*slow=A,*fast=A;
    while(slow && fast && fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    l2=slow->next;
    slow->next=NULL;
    
    ListNode *prev=NULL,*curr=l2,*nxt;
    while(curr)
    {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    l2=prev;
    ListNode *temp;
    ListNode *l1head=l1;
    while(l1 && l2)
    {
      temp=l2;
      l2=l2->next;
      temp->next=l1->next;
      l1->next=temp;
      l1=l1->next->next;
    }
    return l1head;
    return A;
}
