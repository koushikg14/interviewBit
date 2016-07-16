/*
Single Number II

Given an array of integers, every element appears thrice except for one which occurs once.

Find that element which does not appear thrice.

Note: Your algorithm should have a linear runtime complexity.

Could you implement it without using extra memory?

Example :

Input : [1, 2, 4, 3, 3, 2, 2, 3, 1, 1]
Output : 4

*/
int Solution::singleNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int ones,zeros;
    int ans=0;
    for(int i=0;i<32;i++)
    {
        ones=0;
        zeros=0;
        for(int j=0;j<A.size();j++)
        {
            if(A[j] & (1<<i))
                ones++;
            else
                zeros++;
        }
        if(ones%3==1)
            ans=ans|(1<<i);
    }
    return ans;
}
