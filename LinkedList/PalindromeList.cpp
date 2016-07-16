/*
Palindrome List

Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes:
- Expected solution is linear in time and constant in space.

For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
int Solution::lPalin(ListNode* A) {
    if(A==NULL)
        return 1;
    if(A->next==NULL)
        return 1;
    ListNode *l1=A,*l2=NULL,*currhead=A;
    int totalnodes=0;
    while(currhead)
    {
        totalnodes++;
        currhead=currhead->next;
    }
    currhead=A;
    for(int i=0;i<totalnodes/2-1;i++)
    {
        currhead=currhead->next;
    }
    l2=currhead->next;
    currhead->next=NULL;
    ListNode *prev=NULL,*curr=l2,*nxt;
    while(curr)
    {
        nxt=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nxt;
    }
    l2=prev;
    int flag=0;
        while(l2!=NULL && l1!=NULL)
        {
            if(l1->val!=l2->val)
             {
                 flag=1;
                 break;
             }
             l1=l1->next;
             l2=l2->next;
        }
        if(flag==1)
            return 0;
        else
            return 1;
}
