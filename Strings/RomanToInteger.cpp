/*
Roman To Integer

Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.

Read more details about roman numerals at Roman Numeric System

Example :

Input : "XIV"
Return : 14

Input : "XX"
Output : 20

*/

int Solution::romanToInt(string A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.length()==0)
        return 0;
    map<char,int> m;
    m['I']=1;
    m['V']=5;
    m['X']=10;
    m['L']=50;
    m['C']=100;
    m['D']=500;
    m['M']=1000;
    
    int sum=m[A[A.length()-1]];
    for(int i=A.length()-2;i>=0;i--)
    {
        if(m[A[i]]<m[A[i+1]])
            sum-=m[A[i]];
        else
            sum+=m[A[i]];
    }
    return sum;
}
