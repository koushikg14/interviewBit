/*
Find Permutation

Given a positive integer n and a string s consisting only letters D or I, you have to find any permutation of first n positive integer that satisfy the given input string.

D means the next number is smaller, while I means the next number is greater.

Notes
- Length of given string s will always equal to n - 1
- Your solution should run in linear time and space.

Example :

Input 1:

n = 3

s = ID

Return: [2, 3, 1]

*/
vector<int> Solution::findPerm(const string A, int B) {
    vector<int> ans;
    if(B==0)
        return ans;
    int left=1,right=B;
    for(int i=0;i<A.length();i++)
    {
        if(A[i]=='I')
            ans.push_back(left++);
        else
            ans.push_back(right--);
    }
    ans.push_back(left);
    
    
    return ans;
}
