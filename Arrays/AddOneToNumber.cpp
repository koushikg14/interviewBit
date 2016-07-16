/*
Given a non-negative number represented as an array of digits,

add 1 to the number ( increment the number represented by the digits ).

The digits are stored such that the most significant digit is at the head of the list.

Example:

If the vector has [1, 2, 3]

the returned vector should be [1, 2, 4]

as 123 + 1 = 124.
*/


vector<int> Solution::plusOne(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.size();
    vector<int> ans(n+1);
    int rem,num,carry=1;
    int index=n;
    for(int i=n-1;i>=0;i--)
    {
        num=A[i]+carry;
        rem=num%10;
        ans[index--]=rem;
        carry=num/10;
    }
    
    if(carry)
        ans[0]=carry;
    else
        ans.erase(ans.begin());
        
    while(1)
    {
        if(ans[0]==0)
        {
            ans.erase(ans.begin());
        }
        else
            break;
    }
    return ans;
}
