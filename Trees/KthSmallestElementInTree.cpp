/*
Kth Smallest Element In Tree

Given a binary search tree, write a function to find the kth smallest element in the tree.

Example :

Input : 
  2
 / \
1   3

and k = 2

Return : 2

As 2 is the second smallest element in the tree.

    NOTE : You may assume 1 <= k <= Total number of nodes in BST 

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
 void inorder(struct TreeNode *root,vector<int>& vec)
 {
     if(root)
     {
     inorder(root->left,vec);
     vec.push_back(root->val);
     inorder(root->right,vec);
     }
     return;
 }
int Solution::kthsmallest(TreeNode* root, int k) {
    vector<int> vec;
    if(root==NULL)
        return 0;
    inorder(root,vec);
    sort(vec.begin(),vec.end());
    return vec[k-1];
}
