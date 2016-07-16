/*
Remove Duplicates from Sorted List II

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::deleteDuplicates(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==NULL)
        return NULL;
    if(A->next==NULL)
        return A;
    map<int,int> m;
    map<int,int>::iterator it;
    ListNode *start=A;
    while(A)
    {
        it=m.find(A->val);
        if(it==m.end())
            m.insert(pair<int,int>(A->val,1));
        else
            it->second+=1;
        A=A->next;
    }
    ListNode *currhead=start;
    ListNode *newlist=NULL,*newlisthead=newlist;
    while(currhead)
    {
        it=m.find(currhead->val);
        if(it->second==1)
        {
            if(newlist==NULL)
            {
                newlist=currhead;
                newlisthead=newlist;
            }
            else
            {
                newlist->next=currhead;
                newlist=newlist->next;
            }
        }
        currhead=currhead->next;
    }
    if(newlist)
        newlist->next=NULL;
    return newlisthead;
}
