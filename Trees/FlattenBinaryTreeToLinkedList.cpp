
/*


Given a binary tree, flatten it to a linked list in-place.

Example :
Given


         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

Note that the left child of all nodes should be NULL.
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

struct TreeNode *auxfunc(struct TreeNode *root,struct TreeNode * &next)
 {
    if(root)
    {
        auxfunc(root->right,next);
        auxfunc(root->left,next);
        root->right=next;
        root->left=NULL;
        next=root;
    }
    return root;
 }
TreeNode* Solution::flatten(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==NULL) 
        return NULL;
    struct TreeNode *next=NULL;
    return auxfunc(A,next);
}

