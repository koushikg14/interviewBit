/*
Given an integer, convert it to a roman numeral, and return a string corresponding to its roman numeral version

Input is guaranteed to be within the range from 1 to 3999.

Example :

Input : 5
Return : "V"

Input : 14
Return : "XIV"

*/
string Solution::intToRoman(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    map<int,string> m;
    map<int,string> :: reverse_iterator rit;
    string ans;
    m[1]="I";
    m[4]="IV";
    m[5]="V";
    m[9]="IX";
    m[10]="X";
    m[40]="XL";
    m[50]="L";
    m[90]="XC";
    m[100]="C";
    m[400]="CD";
    m[500]="D";
    m[900]="CM";
    m[1000]="M";
    
    for(rit=m.rbegin();A!=0;rit++)
    {
        while(A>=rit->first)
        {
            A-=rit->first;
            ans+=rit->second;
        }
    }
    return ans;
}
