/*
Balanced Binary Tree

Given a binary tree, determine if it is height-balanced.

    Height-balanced binary tree : is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1. 

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Example :

Input : 
          1
         / \
        2   3

Return : True or 1 

Input 2 : 
         3
        /
       2
      /
     1

Return : False or 0 
         Because for the root node, left subtree has depth 2 and right subtree has depth 0. 
         Difference = 2 > 1. 


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
 
 int height(TreeNode *root)
 {
    if(root==NULL)
        return 0;
    if(root->left==NULL && root->right==NULL)
        return 1;
    else
    {
        return 1+ max(height(root->left),height(root->right));
    }
    
 }
 
 
 
int Solution::isBalanced(TreeNode* A) {
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
        int leftheight=height(A->left);
        int rightheight=height(A->right);
        int diff=leftheight-rightheight;
        if(diff==-1 || diff==0 || diff==1)
            return (isBalanced(A->left) && isBalanced(A->right));
        else
            return false;
    }
}
