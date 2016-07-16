/*
Square Root of Integer

Implement int sqrt(int x).

Compute and return the square root of x.

If x is not a perfect square, return floor(sqrt(x))

Example :

Input : 11
Output : 3

*/
int binarySearch(long long int A,long long int start,long long int end)
{
    if(start>end)
        return end;
    long long int mid=start+((end-start)/2);
    if(mid*mid ==A)
        return mid;
    else if(mid*mid <A)
        return binarySearch(A,mid+1,end);
    else
        return binarySearch(A,start,mid-1);
}

int sqrtFloor(long long int n,long long int start,long long int end)
{
	if(start>end)
		return end;

	long long int mid=start+(end-start)/2;
	if(mid*mid==n)
		return mid;
	else if(mid*mid < n)
		return sqrtFloor(n,mid+1,end);
	else
		return sqrtFloor(n,start,mid-1);
}

int Solution::sqrt(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
  
    if(A==0)
        return 0;
    if(A<=3)
        return 1;
    return sqrtFloor(A,1,A);
    // long long int i=2;
    // long long int num=i*i;
    // long long int lower,upper;
    // while(num<=A)
    // {   
    //     lower=i;
    //     upper=num;
    //     i=upper;
    //     num=i*i;
        
    // }
    // return binarySearch(A,lower,upper);
}
