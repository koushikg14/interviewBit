
/*
Symmetric Binary Tree

Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

Example :

    1
   / \
  2   2
 / \ / \
3  4 4  3

The above binary tree is symmetric.
But the following is not:

    1
   / \
  2   2
   \   \
   3    3

Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 * 
 * typedef struct TreeNode treenode;
 * 
 * treenode* treenode_new(int val) {
 *     treenode* node = (treenode *) malloc(sizeof(treenode));
 *     node->val = val;
 *     node->left = NULL;
 *     node->right = NULL;
 *     return node;
 * }
 */
/**
 * @input A : Root pointer of the tree 
 * 
 * @Output Integer
 */
 
  int auxfunc( treenode* A,treenode* B)
 {
    if(A==NULL && B==NULL)
        return 1;
    if((A==NULL && B!=NULL) || (A!=NULL && B==NULL))
        return 0;
    else if(A->val==B->val)
    {
        return (auxfunc(A->left,B->right) && auxfunc(A->right,B->left));
    }
    else
        return 0;
 }
   
int isSymmetric(treenode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==NULL)
        return 1;
    if(A->left==NULL && A->right==NULL)
        return 1;
    else
    {
        return auxfunc(A->left,A->right);
    }
    return 0;
}

    

