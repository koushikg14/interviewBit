
/*
Recover Binary Search Tree

Two elements of a binary search tree (BST) are swapped by mistake.
Tell us the 2 values swapping which the tree will be restored.

    Note:
    A solution using O(n) space is pretty straight forward. Could you devise a constant space solution? 

Example :


Input : 
         1
        / \
       2   3

Output : 
       [1, 2]

Explanation : Swapping 1 and 2 will change the BST to be 
         2
        / \
       1   3
which is a valid BST          


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
 struct TreeNode *auxRecoverTree(TreeNode *root,TreeNode* &first,TreeNode* &second,TreeNode* &prev)
 {
    if(root)
    {
        auxRecoverTree(root->left,first,second,prev);
        if(prev!=NULL && (root->val < prev->val))
        {
            if(first)
            {
                second=root;
            }
            else
            {
                first=prev;
                second=root;
            }
        }
        prev=root;
        auxRecoverTree(root->right,first,second,prev);;
    }
    return root;
 }
 
 
vector<int> Solution::recoverTree(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> vec;
    if(A==NULL)
        return vec;
    if(A->left==NULL && A->right==NULL)
        return vec;
    TreeNode *first=NULL,*second=NULL,*prev=NULL;
    auxRecoverTree(A,first,second,prev);
    if(first && right)
    {
        if(first->val < second->val)
        {
            vec.push_back(first->val);
            vec.push_back(second->val);
        }
        else
        {
            vec.push_back(second->val);
            vec.push_back(first->val);
        }
    }
    return vec;
}
