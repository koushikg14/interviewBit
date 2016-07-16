/*
Excel Column Number

Given a column title as appears in an Excel sheet, return its corresponding column number.

Example:

    A -> 1
    
    B -> 2
    
    C -> 3
    
    ...
    
    Z -> 26
    
    AA -> 27
    
    AB -> 28 

*/

int Solution::titleToNumber(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int ans=0;
    int ind=0;
    for(int i=A.length()-1;i>=0;i--)
    {
        ans+=pow(26,ind)*(A[i]-'A'+1);
        ind++;
    }
    return ans;
}
