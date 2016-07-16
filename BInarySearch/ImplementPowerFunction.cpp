/*
Implement Power Function

Implement pow(x, n) % d.

In other words, given x, n and d,

find (xn % d)

Note that remainders on division cannot be negative.
In other words, make sure the answer you return is non negative.

Input : x = 2, n = 3, d = 3
Output : 2

2^3 % 3 = 8 % 3 = 2.

*/

int auxfunc(int x,int n,int d)
{
    if(x==0)
        return 0;
    if(n==0)
        return 1;
    long long int c=(auxfunc(x,n/2,d));
    long long int val;
    if(n%2==0)
        val=(c*c)%d;
    else
        val=(x*((c*c)%d))%d;
    return val;
}


int Solution::pow(int x, int n, int d) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    long long int val=auxfunc(x,n,d);
    if(val<0)
        val=val+d;
    return val;
  
}
