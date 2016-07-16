/*
Divide Integers

Divide two integers without using multiplication, division and mod operator.

Return the floor of the result of the division.

Example:

5 / 2 = 2

Also, consider if there can be overflow cases. For overflow case, return INT_MAX.
*/
int Solution::divide(int dividend, int divisor) {
    if(divisor==0 || (dividend==INT_MIN && divisor==-1))
        return INT_MAX;
    
    int negFlag=0;
    int ans=0;
    long long int dividend1=dividend;
    long long int divisor1=divisor;
    if(divisor1<0)
    {
        dividend1=-dividend1;
        divisor1=-divisor1;
    }
    if(dividend1<0)
    {
        negFlag=1;
        dividend1=-dividend1;
    }
    
    while(dividend1>=divisor1)
    {
        long long int temp=divisor1,count=1;
        while(dividend1>=temp<<1)
        {
            temp<<=1;
            count<<=1;
        }
        ans+=count;
        dividend1-=temp;
    }
    if(negFlag==1)
        ans=-ans;
    return ans;
}
