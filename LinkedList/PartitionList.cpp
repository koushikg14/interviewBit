/*
Partition List

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::partition(ListNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==NULL)
        return A;
    ListNode *list1start=NULL,*list2start=NULL;
    ListNode *list1curr=NULL,*list2curr=NULL;
    ListNode *curr=A;
    while(curr!=NULL)
    {
        if(curr->val < B)
        {
            if(list1curr==NULL)
            {
                list1curr=curr;
                list1start=list1curr;
            }
            else
            {
                list1curr->next=curr;
                list1curr=list1curr->next;
            }
        }
        else
        {
            if(list2curr==NULL)
            {
                list2curr=curr;
                list2start=list2curr;
            }
            else
            {
                list2curr->next=curr;
                list2curr=list2curr->next;
            }
        }
        curr=curr->next;
    }
    if(list1start && list2start)
    {
        list1curr->next=list2start;
        list2curr->next=NULL;
        return list1start;
    }
    else if(list1start==NULL)
    {
        list2curr->next=NULL;
        return list2start;
    }
    else
    {
        list1curr->next=NULL;
        return list1start;
    }
}
