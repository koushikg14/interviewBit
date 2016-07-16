/*
Path Sum

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

Example :

Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1

return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

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
 
 bool auxfunc(TreeNode *root,int currsum,int sum)
 {
    if(root)
    {
    if(root->left==NULL && root->right==NULL)
    {
        currsum+=root->val;
        if(sum==currsum)
            return true;
        else
            return false;
    }
    else
    {
        currsum+=root->val;
        bool flag=false;
        flag=auxfunc(root->left,currsum,sum);
        if(flag==true)
            return true;
        else
            return auxfunc(root->right,currsum,sum);
    }
    }
    return false;
}
 
 
int Solution::hasPathSum(TreeNode* A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==NULL)
        return false;
    if(A->left==NULL && A->right==NULL)
    {
        if(A->val==B)
            return true;
        else
            return false;
    }
    else
    {
        int currsum=0;
        return auxfunc(A,currsum,B);
    }
    
}
