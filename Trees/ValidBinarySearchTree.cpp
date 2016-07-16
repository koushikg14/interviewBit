/*
Valid Binary Search Tree

Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node’s key.
    The right subtree of a node contains only nodes with keys greater than the node’s key.
    Both the left and right subtrees must also be binary search trees.

Example :

Input : 
   1
  /  \
 2    3

Output : 0 or False


Input : 
  2
 / \
1   3

Output : 1 or True 

Return 0 / 1 ( 0 for false, 1 for true ) for this problem
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
 bool auxfunc(TreeNode *root,int l,int h)
 {
    if(root==NULL)
        return true;
    if(root->left==NULL && root->right==NULL)
    {
        if(root->val >= l && root->val <=h)
            return true;
    }
    if((root->val==INT_MIN && root->left) ||(root->val==INT_MAX && root->right))
        return false;
    else
    {
        if(root->val >=l && root->val <=h)
            return (auxfunc(root->left,l,root->val-1)&& auxfunc(root->right,root->val+1,h));
    }
    return false;
 }
 
int Solution::isValidBST(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==NULL)
        return true;
    if(A->left==NULL && A->right==NULL)
        return true;
    else
    {
        return auxfunc(A,INT_MIN,INT_MAX);
    }
}
