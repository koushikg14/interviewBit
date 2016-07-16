/*
Merge Two Sorted Lists

Merge two sorted linked lists and return it as a new list.
The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15

The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::mergeTwoLists(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==NULL && B==NULL)
        return NULL;
    if(A==NULL && B!=NULL)
        return A;
    if(A!=NULL && B==NULL)
        return B;
    struct ListNode *newlistcurr=NULL;
    struct ListNode *newlisthead=newlistcurr;
    while(A!=NULL && B!=NULL)
    {
        if(A->val < B->val)
        {
            if(newlistcurr==NULL)
            {
                newlistcurr=A;
                newlisthead=newlistcurr;
            }
            else
            {
                newlistcurr->next=A;
                newlistcurr=newlistcurr->next;
            }
            A=A->next;
        }
        else if(A->val > B->val)
        {
            if(newlistcurr==NULL)
            {
                newlistcurr=B;
                newlisthead=newlistcurr;
            }
            else
            {
                newlistcurr->next=B;
                newlistcurr=newlistcurr->next;
            }
            B=B->next;
        }
        else if(A->val==B->val)
        {
            if(newlistcurr==NULL)
            {
                newlistcurr=A;
                newlisthead=newlistcurr;
            }
            else
            {
                newlistcurr->next=A;
                newlistcurr=newlistcurr->next;
            }
            A=A->next;
        }
    }
    if(A!=NULL)
    {
       newlistcurr->next=A;
       newlistcurr=newlistcurr->next;
       //A=A->next;
      // break;
    }
    if(B!=NULL)
    {
        newlistcurr->next=B;
        newlistcurr=newlistcurr->next;
       // B=B->next;
       
    }
    return newlisthead;
}
