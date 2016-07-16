/*
Root to Leaf Paths With Sum

Given a binary tree and a sum, find all root-to-leaf paths where each path’s sum equals the given sum.

For example:
Given the below binary tree and sum = 22,

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

return

[
   [5,4,11,2],
   [5,8,4,5]
]

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
 void auxfunc(TreeNode *root,vector<vector<int>>& vec,vector<int> subvec,int currsum,int sum)
 {
    if(root==NULL)
        return ;
    if(root->right==NULL && root->left==NULL)
    {
        currsum+=root->val;
        subvec.push_back(root->val);
        if(currsum==sum)
        {
            vec.push_back(subvec);
        }
        return;
    }
    else
    {
        currsum+=root->val;
        subvec.push_back(root->val);
        auxfunc(root->left,vec,subvec,currsum,sum);
        auxfunc(root->right,vec,subvec,currsum,sum);
        return ;
    }
 }
 
 
vector<vector<int> > Solution::pathSum(TreeNode* root, int sum) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<int>> vec;
    vector<int> subvec;
    if(root==NULL)
        return vec;
    if(root->left==NULL && root->right==NULL)
    {
        if(root->val==sum)
        {
            subvec.push_back(root->val);
            vec.push_back(subvec);
        }
        return vec;
    }
    else
    {
        int currsum=0;
         auxfunc(root,vec,subvec,currsum,sum);
    }
    return vec;
}
