/*
Diffk II

Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

Example :

Input :

A : [1 5 3]
k : 2

Output :

1

as 3 - 1 = 2

    Return 0 / 1 for this problem.

*/

int Solution::diffPossible(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.size();
    unordered_map<int,int> m;
    unordered_map<int,int>::iterator it;
    for(int i=0;i<n;i++)
    {
        it=m.find(A[i]);
        if(it==m.end())
            m.insert(pair<int,int>(A[i],1));
        else
            it->second+=1;
    }
    
    for(int i=0;i<n;i++)
    {
        it=m.find(A[i]-B);
        if(it!=m.end())
        {
            if((A[i]-B==A[i]) && it->second>=2)
                return 1;
            else if(A[i]-B!=A[i])
                return 1;     
        }
    }
    return 0;
}
