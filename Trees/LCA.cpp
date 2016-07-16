/*
Least Common Ancestor

Find the lowest common ancestor in an unordered binary tree given two values in the tree.

    Lowest common ancestor : the lowest common ancestor (LCA) of two nodes v and w in a tree or directed acyclic graph (DAG) is the lowest (i.e. deepest) node that has both v and w as descendants. 

Example :


        _______3______
       /              \
    ___5__          ___1__
   /      \        /      \
   6      _2_     0        8
         /   \
         7    4

For the above tree, the LCA of nodes 5 and 1 is 3.

    LCA = Lowest common ancestor 

Please note that LCA for nodes 5 and 4 is 5.
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
 void inorder(TreeNode *root,int val1,int val2,int &flag1,int &flag2)
 {
    if(root)
    {
    inorder(root->left,val1,val2,flag1,flag2);
    if(root->val==val1)
        flag1=1;
    if(root->val==val2)
        flag2=1;
    inorder(root->right,val1,val2,flag1,flag2);
    return ;
    }
 }
 
 int auxfunc(TreeNode *A,int val1,int val2)
 {
     if(A==NULL)
        return -1;
    if(A->val==val1 || A->val==val2)
        return (A->val);
    int left=auxfunc(A->left,val1,val2);
    int right=auxfunc(A->right,val1,val2);
    
    if(left!=-1 && right!=-1)
        return (A->val);
    else if(left==-1 && right==-1)
        return -1;
    
    else if(left!=-1)
        return (left);
    else if(right!=-1)
        return right;
    return A->val; 
 }
 
int Solution::lca(TreeNode* A, int val1, int val2) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==NULL)
            return -1;
    
    int flag1=0,flag2=0;
    inorder(A,val1,val2,flag1,flag2);
    if(flag1==1 && flag2==1)
    {
        return auxfunc(A,val1,val2);
    }
    else
        return -1;
}
