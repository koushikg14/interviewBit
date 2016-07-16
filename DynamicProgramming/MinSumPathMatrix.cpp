/*
Min Sum Path in Matrix

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

    Note: You can only move either down or right at any point in time. 

Example :

Input : 

    [  1 3 2
       4 3 1
       5 6 1
    ]

Output : 8
     1 -> 3 -> 2 -> 1 -> 1

*/

int Solution::minPathSum(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size()==0)
        return 0;
    int m=A.size(),n=A[0].size();
    vector<vector<int> > grid(m,vector<int>(n,0));
    grid[0][0]=A[0][0];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0 && j==0)
                continue;
            if(i==0)
                grid[i][j]=grid[i][j-1]+A[i][j];
            if(j==0)
                grid[i][j]=grid[i-1][j]+A[i][j];
            if(i>0 && j>0)
                grid[i][j]=min(grid[i][j-1],grid[i-1][j])+A[i][j];
        }
    }
    return grid[m-1][n-1];
}
