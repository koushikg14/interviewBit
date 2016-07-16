/*
Remove Nth Node from List End

Given a linked list, remove the nth node from the end of list and return its head.

For example,
Given linked list: 1->2->3->4->5, and n = 2.
After removing the second node from the end, the linked list becomes 1->2->3->5.

    Note:
    * If n is greater than the size of the list, remove the first node of the list. 

Try doing it using constant additional space.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    struct ListNode *curr=A;
    int totalnodes=0;
    while(curr)
    {
        totalnodes++;
        curr=curr->next;
    }
    if(B>=totalnodes)
    {
        A=A->next;
        return A;
    }
    curr=A;
    for(int i=0;i<totalnodes-B-1;i++)
        curr=curr->next;
    curr->next=curr->next->next;
    return A;
}
