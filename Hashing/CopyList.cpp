/*
Copy List

A linked list is given such that each node contains an additional random pointer which could point to any node in the list or NULL.

Return a deep copy of the list.

Example

Given list

   1 -> 2 -> 3

with random pointers going from

  1 -> 3
  2 -> 1
  3 -> 1

You should return a deep copy of the list. The returned answer should not contain the same node as the original list, but a copy of them. The pointers in the returned list should not link to any node in the original input list.
*/

/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    RandomListNode *clonestart=NULL;
    if(A==NULL)
        return clonestart;
    map<RandomListNode*,RandomListNode*> m;
    map<RandomListNode*,RandomListNode*>:: iterator it;
  
    RandomListNode *curr=A;
    while(curr!=NULL)
    {
        RandomListNode *clonenode=new RandomListNode(curr->label);
        m.insert(pair<RandomListNode*,RandomListNode*>(curr,clonenode));
        curr=curr->next;
    }
    
    curr=A;
    clonestart=m[curr];
    RandomListNode *ans=clonestart;
    while(curr!=NULL)
    {
        clonestart->next=m[curr->next];
        clonestart->random=m[curr->random];
        curr=curr->next;
        if(curr==NULL)
            clonestart->next=NULL;
        clonestart=clonestart->next;
    }
    return ans;
}
