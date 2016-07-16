/*
Compare Version Numbers

Compare two version numbers version1 and version2.

        If version1 > version2 return 1,
        If version1 < version2 return -1,
        otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.
The . character does not represent a decimal point and is used to separate number sequences.
For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

Here is an example of version numbers ordering:

0.1 < 1.1 < 1.2 < 1.13 < 1.13.4

*/

int Solution::compareVersion(string A, string B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    long long int n1=A.length();
    long long int n2=B.length();
    long long int i=0,j=0;
    long double val1=0,val2=0;
    while(i<n1 || j<n2)
    {
        val1=0;
        val2=0;
        while(i<n1 && A[i]!='.')
        {
            val1=val1*10+A[i]-'0';
            i++;
        }
        while(j<n2 && B[j]!='.')
        {
            val2=val2*10+B[j]-'0';
            j++;
        }
        if(val1>val2)
            return 1;
        else if(val1<val2)
            return -1;
        else
        {
            i++;
            j++;
        }
    }
    return 0;
}
