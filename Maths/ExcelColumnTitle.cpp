/*
Excel Column Title

Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 

*/

string Solution::convertToTitle(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    string ans;
    int rem;
    while(A>0)
    {
        rem=A%26;
        if(rem==0)
        {
            ans+='Z';
            A=(A-1)/26;
        }
        else 
        {
            ans+='A'+rem-1;
            A/=26;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
