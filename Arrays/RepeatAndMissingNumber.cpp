/*
You are given a read only array of n integers from 1 to n.

Each integer appears exactly once except A which appears twice and B which is missing.

Return A and B.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Note that in your output A should precede B.

Example:

Input:[3 1 2 5 3] 

Output:[3, 4] 

A = 3, B = 4

*/
vector<int> Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> ans;
    long long int actual_sum=0,currsum=0;
    long long int n=A.size();
    long long int a,b;
    
    for(int i=0;i<n;i++)
        currsum+=(long long int)A[i];
    actual_sum=(long long int)(((long long int)n*(long long int)(n+1))/2);
  
    long long int diff1=actual_sum-currsum;
    
    actual_sum=0,currsum=0;
    for(int i=0;i<n;i++)
        currsum+=((long long int)A[i]*(long long int) A[i]); 
    actual_sum=(long long int)(((long long int)n*(long long int)(n+1)*(long long int)(2*n+1))/6);
    
    long long int diff2=actual_sum-currsum;
    long long int diff=(long long int)diff2/diff1;
    a=(long long int)(diff+diff1)/2;
    b=diff-a;
    if(diff1>0)
    {
        if(a<b)
        {
            ans.push_back((int)a);
            ans.push_back((int)b);
        }
        else
        {
            ans.push_back((int)b);
            ans.push_back((int)a);
        }
        
    }
    else
    {
        if(a<b)
        {
            ans.push_back((int)b);
            ans.push_back((int)a);
        }
        else
        {
            ans.push_back((int)a);
            ans.push_back((int)b);
        }
    }
    return ans;

}
