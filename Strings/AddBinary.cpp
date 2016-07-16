/*

Add Binary Strings

Given two binary strings, return their sum (also a binary string).

Example:

a = "100"

b = "11"

Return a + b = “111”.
*/

string Solution::addBinary(string A, string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n1=A.length(),n2=B.length();
    if(n1==0)
        return B;
    if(n2==0)
        return A;
    string ans;
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    int i=0,j=0;
    int carry=0;
    while(i<n1 && j<n2)
    {
        int val=carry+A[i]-'0'+B[j]-'0';
        ans+=to_string(val%2);
        if(val>=2)
            carry=1;
        else
            carry=0;
        i++;
        j++;
    }
    
    while(i<n1)
    {
         int val=carry+A[i]-'0';
        ans+=to_string(val%2);
        if(val>=2)
            carry=1;
        else
            carry=0;
        i++;
    }
    while(j<n2)
    {
         int val=carry+B[j]-'0';
        ans+=to_string(val%2);
        if(val>=2)
            carry=1;
        else
            carry=0;
        j++;
    }
    if(carry)
        ans+=to_string(carry);
    reverse(ans.begin(),ans.end());
    return ans;
    
}
