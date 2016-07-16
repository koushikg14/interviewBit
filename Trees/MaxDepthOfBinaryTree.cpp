/*
Max Depth of Binary Tree

Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the nearest leaf node.

    NOTE : The path has to end on a leaf node. 

Example :

         1
        /
       2

max depth = 2.
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
int Solution::maxDepth(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==NULL)
        return 0;
    if(A->left==NULL && A->right==NULL)
        return 1;
    else
    {
        return 1+max(maxDepth(A->left),maxDepth(A->right));
    }
    
}
