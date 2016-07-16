/*
Reverse Bits

Reverse bits of an 32 bit unsigned integer

Example 1:

x = 0,

          00000000000000000000000000000000  
=>        00000000000000000000000000000000

return 0

Example 2:

x = 3,

          00000000000000000000000000000011 
=>        11000000000000000000000000000000

return 3221225472
*/

unsigned int Solution::reverse(unsigned int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int index=31;
    int num=0;
    while(A>0)
    {
        if(A & 1)
            num+=pow(2,index);
        index--;
        A=A>>1;
    }
    return num;
}
