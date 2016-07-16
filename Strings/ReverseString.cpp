/*
Reverse the String

Given an input string, reverse the string word by word.

Example:

Given s = "the sky is blue",

return "blue is sky the".

        A sequence of non-space characters constitutes a word.
        Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
        If there are multiple spaces between words, reduce them to a single space in the reversed string.

*/

void reversefunc(string &s,int start,int end)
{
    while(start<=end)
    {
        swap(s[start++],s[end--]);
    }
    return;
}

void Solution::reverseWords(string &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    string word;
    vector<string> vec;
    stringstream ss(A);
    while(ss >> word)
        vec.push_back(word);
    
    for(int i=vec.size()-2;i>=0;i--)
    {
        word+=' ';
        word+=vec[i];
    }
    A=word;
     return;
    
}
