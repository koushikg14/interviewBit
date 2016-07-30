/*Next Permutation

Implement the next permutation, which rearranges numbers into the numerically next greater permutation of numbers.

If such arrangement is not possible, it must be rearranged as the lowest possible order ie, sorted in an ascending order.

The replacement must be in-place, do not allocate extra memory.

Examples:

1,2,3 → 1,3,2

3,2,1 → 1,2,3

1,1,5 → 1,5,1

20, 50, 113 → 20, 113, 50

Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.

    Warning : DO NOT USE LIBRARY FUNCTION FOR NEXT PERMUTATION.

    Use of Library functions will disqualify your submission retroactively and will give you penalty points. 

*/


void Solution::nextPermutation(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int n=A.size();
    int index=n-1;
    if(n==1)
        return ;
    if(n==2)
    {
        swap(A[0],A[1]);
        return;
    }
    
    for(int i=n-2;i>=0;i--)
    {
        if(A[i]<A[i+1])
        {
            index=i;
            break;
        }
    }
    int index2=index+1;
    int val=A[index2];
    for(int i=index+1;i<n;i++)
    {
        if(A[i]>A[index] && A[i]<val)
        {
            val=A[i];
            index2=i;
        }
    }
    
    swap(A[index],A[index2]);
    sort(A.begin()+index+1,A.end());
    return;
}

