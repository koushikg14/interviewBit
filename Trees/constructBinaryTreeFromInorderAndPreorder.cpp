/*
Construct Binary Tree From Inorder And Preorder

Given preorder and inorder traversal of a tree, construct the binary tree.

    Note: You may assume that duplicates do not exist in the tree. 

Example :

Input :
        Preorder : [1, 2, 3]
        Inorder  : [2, 1, 3]

Return :
            1
           / \
          2   3

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
     
     int Search(vector<int>& inorder,int data,int start,int end)
     {
         int index=0;
        for(int i=start;i<=end;i++)
        {
            if(inorder[i]==data)
             {
                 index=i;
                 break;
             }
        }
        return index;
     }
     
     struct TreeNode *auxfunc(vector<int>& preorder, vector<int>& inorder,int start,int end)
     {
        if(start>end)
            return NULL;
        struct TreeNode *root=new TreeNode(preorder.front());
        preorder.erase(preorder.begin());
        if(start==end)
            return root;
        else
        {
            int inIndex=Search(inorder,root->val,start,end);
            root->left=auxfunc(preorder,inorder,start,inIndex-1);
            root->right=auxfunc(preorder,inorder,inIndex+1,end);
        }
        return root;
     }
     
     
    TreeNode* Solution::buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Do not write main() function.
        // Do not read input, instead use the arguments to the function.
        // Do not print the output, instead return values as specified
        // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
        if(preorder.size()==0 || inorder.size()==0)
            return NULL;
        if(preorder.size()==1)
        {
            struct TreeNode *root=new TreeNode(preorder[0]);
            return root;
        }
        else
        {
            return auxfunc(preorder,inorder,0,inorder.size()-1);
        }
    }

