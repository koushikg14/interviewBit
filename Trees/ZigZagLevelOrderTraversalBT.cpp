/*
ZigZag Level Order Traversal BT

Given a binary tree, return the zigzag level order traversal of its nodes’ values. (ie, from left to right, then right to left for the next level and alternate between).

Example :
Given binary tree

    3
   / \
  9  20
    /  \
   15   7

return

[
         [3],
         [20, 9],
         [15, 7]
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
vector<vector<int> > Solution::zigzagLevelOrder(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<int>> vec;
    vector<int> subvec;
    if(A==NULL)
        return vec;
    stack<TreeNode*> currlevel;
    stack<TreeNode*> nextlevel;
    int lefttoright=1;
    currlevel.push(A);
    struct TreeNode * temp;
    while(!currlevel.empty())
    {
        temp=currlevel.top();
        subvec.push_back(temp->val);
        currlevel.pop();
        if(temp)
        {
            if(lefttoright==1)
            {
                if(temp->left)
                    nextlevel.push(temp->left);
                if(temp->right)
                    nextlevel.push(temp->right);
            }
            else
            {
                if(temp->right)
                    nextlevel.push(temp->right);
                if(temp->left)
                    nextlevel.push(temp->left);
            }
        }
        if(currlevel.empty())
        {
            vec.push_back(subvec);
            subvec.clear();
            lefttoright=1-lefttoright;
            swap(currlevel,nextlevel);
        }
    }
    return vec;
}

