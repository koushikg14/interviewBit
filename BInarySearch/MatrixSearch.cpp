/*
Matrix Search

Write an efficient algorithm that searches for a value in an m x n matrix.

This matrix has the following properties:

        Integers in each row are sorted from left to right.
        The first integer of each row is greater than or equal to the last integer of the previous row.

Example:

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]

Given target = 3, return 1 ( 1 corresponds to true )

Return 0 / 1 ( 0 if the element is not present, 1 if the element is present ) for this problem
*/


int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size()==0)
        return 0;
    int m=A.size();
    int n=A[0].size();
    int i=m-1,j=0;
    while(i>=0 && j<n)
    {
        if(A[i][j]==B)
            return true;
        else if(A[i][j]>B)
            i--;
        else
            j++;
    }
    return false;
}
