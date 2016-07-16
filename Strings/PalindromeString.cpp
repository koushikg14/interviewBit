/*
Palindrome String

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example:

"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/


int Solution::isPalindrome(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    string s;
    for(int i=0;i<A.size();i++)
    {
        if(isalnum(A[i]))
            s+=tolower(A[i]);
    }
    string temp=s;
    reverse(temp.begin(),temp.end());
    if(temp==s)
        return true;
    else
        return false;
}
