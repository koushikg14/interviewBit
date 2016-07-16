/*
Sum Root to Leaf Numbers

Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers % 1003.

Example :

    1
   / \
  2   3

The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = (12 + 13) % 1003 = 25 % 1003 = 25.
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
 
 void auxSumNumbers(TreeNode *root,vector<int>&vec,int currsum)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL)
        {
            currsum=(currsum*10+root->val)%1003;
            vec.push_back(currsum);
        }
        else
        {
            currsum=(currsum*10+root->val)%1003;
            auxSumNumbers(root->left,vec,currsum);
            auxSumNumbers(root->right,vec,currsum);
        }
        return;
    }
    
 
int Solution::sumNumbers(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
     vector<int> vec;
        if(A==NULL)
            return 0;
        if(A->left==NULL && A->right==NULL)
        {
            return (A->val);
        }
        else
        {
            int currsum=0;
            currsum=(currsum+A->val)%1003;
            auxSumNumbers(A->left,vec,currsum);
            auxSumNumbers(A->right,vec,currsum);
        }
        int sum=0;
        for(int i=0;i<vec.size();i++)
            sum=(sum+vec[i])%1003;
        return sum%1003;
}
