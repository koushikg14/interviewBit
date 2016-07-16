/*
Diffk

Given an array ‘A’ of sorted integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

    Example:

    Input : 

    A : [1 3 5] 
    k : 4

    Output : YES

    as 5 - 1 = 4 

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Try doing this in less than linear space complexity.
*/

int Solution::diffPossible(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size()==1)
        return 0;
    if(A.size()==2)
    {
        if(A[1]-A[0]==B)
            return 1;
        else
            return 0;
    }
    int i=0,j=1;
    while(i<j && j<A.size())
    {
        if(A[j]-A[i]==B)
            return true;
        else if((A[j]-A[i])<B)
            j++;
        else
        {
            i++;
            if(i==j)
                j++;
        }
    }
    return false;
}
