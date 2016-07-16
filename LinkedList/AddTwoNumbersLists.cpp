/*
Add Two Numbers as Lists

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

    342 + 465 = 807

Make sure there are no trailing zeros in the output list
So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==NULL)
        return B;
    if(B==NULL)
        return A;
    int rem=0;
    ListNode *currA=A,*currB=B;
    while(currA && currB)
    {
        int value=currA->val + currB->val + rem;
        currA->val=value%10;
        rem=value/10;
        currA=currA->next;
        currB=currB->next;
    }
    while(currA)
    {
        
        int value=currA->val + rem;
        currA->val=value%10;
        rem=value/10;
        currA=currA->next;
    }
    ListNode *curr=A;
    while(curr->next!=NULL)
        curr=curr->next;
    currA=curr;
    while(currB)
    {
        int value=currB->val +rem;
        currB->val=value%10;
        rem=value/10;
        currA->next=currB;
        currB=currB->next;
        currA=currA->next;
    }
    if(rem==1)
    {
        ListNode *newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
        newnode->val=1;
        newnode->next=NULL;
        currA->next=newnode;
        //currB
    }
    return A;
}
