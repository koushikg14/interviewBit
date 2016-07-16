/*
Longest Substring Without Repeat

Given a string,
find the length of the longest substring without repeating characters.

Example:

The longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.

For "bbbbb" the longest substring is "b", with the length of 1.
*/

int Solution::lengthOfLongestSubstring(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    map<char,int> m;
    map<char,int> :: iterator it;
    int start=-1,n=A.size();
    int maxlen=0;
    int currlen=0;
    for(int i=0;i<n;i++)
    {
        it=m.find(A[i]);
        if(it==m.end())
        {
            m.insert(pair<char,int>(A[i],i));
            currlen=i-start;
        }
        else
        {
            start=max(start,it->second);
            currlen=i-start;
            it->second=i;
        }
        maxlen=max(maxlen,currlen);
            
    }
    return maxlen;
}
