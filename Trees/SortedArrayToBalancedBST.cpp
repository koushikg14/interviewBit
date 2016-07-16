/*
Sorted Array To Balanced BST

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

    Balanced tree : a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 

Example :


Given A : [1, 2, 3]
A height balanced BST  : 

      2
    /   \
   1     3

*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 struct TreeNode* auxfunc(const vector<int>& vec,int start,int end)
 {
    if(start>end)
        return NULL;
    struct TreeNode *root=new TreeNode(vec[(start+end)/2]);
    if(start==end)
    {
        return root;
    }
    else
    {
       int mid=(start+end)/2;
        root->left=auxfunc(vec,start,mid-1);
        root->right=auxfunc(vec,mid+1,end);
    }
    return root;
 }
 
 
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size()==0)
        return NULL;
    if(A.size()==1)
    {
        struct TreeNode *root=new TreeNode(A[0]);
        return root;
    }
    else
    {
        int start=0;
        int end=A.size()-1;
        return auxfunc(A,start,end);
    }
  
        
}
