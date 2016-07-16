/*
Count And Say

The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...

1 is read off as one 1 or 11.
11 is read off as two 1s or 21.

21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Example:

if n = 2,
the sequence is 11.
*/

string Solution::countAndSay(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A==1)
        return "1";
    if(A==2)
        return "11";
    string ans="";
    string last="11";
    int j;
    for(int i=3;i<=A;i++)
    {
        string temp="";
        int count=1;
        for(j=1;j<last.size();j++)
        {
            if(last[j]==last[j-1])
            {
                count++;
            }
            else
            {
                temp+=to_string(count)+last[j-1];
                count=1;
            }
        }
        temp+=to_string(count)+last[j-1];
        last=temp;
    }
    ans=last;
    return ans;
}
