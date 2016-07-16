/*


Given a read only array of n + 1 integers between 1 and n, find one number that repeats in linear time using less than O(n) space and traversing the stream sequentially O(1) times.

Sample Input:

[3 4 1 4 1]

Sample Output:

1

If there are multiple possible answers ( like in the sample case above ), output any one.

*/
int Solution::repeatedNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size()==0)
        return -1;
    int slow=0,fast=0;
    while(1)
    {
        slow=A[slow];
        fast=A[A[fast]];
        if(slow==fast)
            break;
    }
    fast=0;
    while(A[slow]!=A[fast])
    {
        slow=A[slow];
        fast=A[fast];
    }
    return A[slow];
}
