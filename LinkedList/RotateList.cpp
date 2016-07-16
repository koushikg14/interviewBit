
/*
Rotate List

Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::rotateRight(ListNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    struct ListNode *curr=A,*newlistcurr,*newlisthead;
    int totalnodes=0;
    while(curr)
    {
        totalnodes++;
        curr=curr->next;
    }
    // cout<<totalnodes<<endl;
    // cout<<totalnodes%B<<endl;
    if(totalnodes==B || (B%totalnodes==0))
        return A;
    B=B%totalnodes;
    curr=A;
    for(int i=0;i<totalnodes-B-1;i++)
    {
        curr=curr->next;
    }
    newlisthead=curr->next;
    newlistcurr=curr->next;
    curr->next=NULL;
    while(newlistcurr->next!=NULL)
    {
        newlistcurr=newlistcurr->next;    
    }
    newlistcurr->next=A;
    return newlisthead;
    
    
}
