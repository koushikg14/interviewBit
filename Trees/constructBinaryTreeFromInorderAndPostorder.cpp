/*
Construct Binary Tree From Inorder And Postorder

Given inorder and postorder traversal of a tree, construct the binary tree.

    Note: You may assume that duplicates do not exist in the tree. 

Example :

Input : 
        Inorder : [2, 1, 3]
        Postorder : [2, 3, 1]

Return : 
            1
           / \
          2   3

*/

struct TreeNode *f(vector<int>& preorder,vector<int>& inorder,int *pos,int start,int end,unordered_map<int,int > &m)
{   
    if(start > end) {
        return NULL;
    }
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    int val = preorder[(*pos)];
    (*pos)--;
    root->val = val;
    root->left = NULL;
    root->right = NULL;
    if(start == end) {
        return root;
    }
    int idx = m[val];
    //cout<<idx<<endl;
    root->right = f(preorder,inorder,pos,idx+1,end,m);
    root->left = f(preorder,inorder,pos,start,idx-1,m);
    return root;
}

TreeNode* Solution::buildTree(vector<int> &inorder, vector<int> &postorder) {
    int pos = postorder.size()-1;
    unordered_map<int,int> m;
    for(int i = 0; i < inorder.size(); i++) {
        m[inorder[i]] = i;
    }
    return f(postorder,inorder,&pos,0,postorder.size()-1,m);
}
