/*
Longest Palindromic Substring

Given a string S, find the longest palindromic substring in S.

Substring of string S:

S[i...j] where 0 <= i <= j < len(S)

Palindrome string:

A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.

Incase of conflict, return the substring which occurs first ( with the least starting index ).

Example :

Input : "aaaabaaa"
Output : "aaabaaa"

*/
string Solution::longestPalindrome(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.length();
    int maxlen=1;
    int start=0;
    int low,high;
    for(int i=1;i<n;i++)
    {
      
        //palindrome of even length
        low=i-1;
        high=i;
        while(low>=0 && high<n && A[low]==A[high])
        {
              //cout<<"***"<<endl;
            if(high-low+1 > maxlen)
            {
                start=low;
                maxlen=high-low+1;
            }
            low--;
            high++;
        }
        
        //Palindrom of odd length
        low=i-1;
        high=i+1;
        while(low>=0 && high<n && A[low]==A[high])
        {
            if(high-low+1 > maxlen)
            {
                start=low;
                maxlen=high-low+1;
            }
            low--;
            high++;
        }
        
   }
   string ans=A.substr(start,maxlen);
   return ans;
}
