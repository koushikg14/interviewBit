/*


Reverse digits of an integer.

Example1:

x = 123,

return 321
Example2:

x = -123,

return -321

Return 0 if the result overflows and does not fit in a 32 bit signed integer

*/
int Solution::reverse(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    long int ans=0;
    int n=A,rem;
    int count=0;
    if(A<0)
        n=-A;
    int num=n;
    while(num>0)
    {
        count++;
        num/=10;
    }
    count--;
    while(n>0)
    {
        rem=n%10;
        ans+=(pow(10,count)*rem);
        count--;
        n/=10;
    }
    if(ans>INT_MAX)
        return 0;
    if(A<0)
        ans=-ans;
    return ans;
}
