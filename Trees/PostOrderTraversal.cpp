/*
Postorder Traversal

Given a binary tree, return the postorder traversal of its nodes’ values.

Example :

Given binary tree

   1
    \
     2
    /
   3

return [3,2,1].

Using recursion is not allowed.
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
vector<int> Solution::postorderTraversal(TreeNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> vec;
    if(A==NULL)
        return vec;
    if(A->left==NULL && A->right==NULL)
    {
        vec.push_back(A->val);
        return vec;
    }
    stack<TreeNode*> st;
  //  struct TreeNode * temp;
    while(1)
    {
        while(A)
        {
            if(A->right)
                st.push(A->right);
            st.push(A);
            A=A->left;
        }
        A=st.top();
      
        st.pop();  
        if(st.empty())
        {
             vec.push_back(A->val);
             break;
        }
        if(A->right && st.top()==A->right)
        {
            st.pop();
            st.push(A);
            A=A->right;
        }
        else
        {
            vec.push_back(A->val);
            A=NULL;
        }
        if(st.empty())
            break;
    }
    return vec;
}
