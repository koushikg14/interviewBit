/*


Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

Your algorithm should run in O(n) time and use constant space.

*/

void saggregate(vector<int>& vec,int n)
{
    int j=0;
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i]<=0)
            swap(vec[j++],vec[i]);
    }
    vec.erase(vec.begin(),vec.begin()+j);
    return;
}

int Solution::firstMissingPositive(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    saggregate(A,A.size());
    
    for(int i=0;i<A.size();i++)
    {
        if(abs(A[i])-1 < A.size() && A[abs(A[i])-1]>0 )
            A[abs(A[i])-1]=-A[abs(A[i])-1];
    }
    
    for(int i=0;i<A.size();i++)
    {
        if(A[i]>0)
            return i+1;
    }
    return A.size()+1;
}
