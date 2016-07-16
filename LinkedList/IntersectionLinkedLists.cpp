/*
Intersection of Linked Lists

Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:


A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3

begin to intersect at node c1.
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::getIntersectionNode(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==NULL || B==NULL)
        return NULL;
    int n1=0,n2=0;
    ListNode *currA=A,*currB=B;
    while(currA)
    {
        n1++;
        currA=currA->next;
    }
    while(currB)
    {
        n2++;
        currB=currB->next;
    }
    int diff=0;
    if(n1>=n2)
        diff=n1-n2;
    else
        diff=n2-n1;
    if(n1>n2)
    {
        for(int i=0;i<diff;i++)
            A=A->next;
    }
    else
    {
        for(int i=0;i<diff;i++)
            B=B->next;
    }
    while(A && B)
    {
        if(A==B)
            return A;
        A=A->next;
        B=B->next;
    }
    return NULL;
}
