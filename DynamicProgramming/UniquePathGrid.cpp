/*
Unique Paths in a Grid

Given a grid of size m * n, lets assume you are starting at (1,1) and your goal is to reach (m,n). At any instance, if you are on (x,y), you can either go to (x, y + 1) or (x + 1, y).

Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Example :
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]

The total number of unique paths is 2.

    Note: m and n will be at most 100. 

*/

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
     int m=A.size();
        if(m==0)
            return 0;
        int n=A[0].size();
        vector<vector<int> > grid(m,vector<int>(n,0));
        if(A[0][0]==1)
            grid[0][0]=0;
        else
            grid[0][0]=1;
            
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                    continue;
                else if(A[i][j]==1)  
                    grid[i][j]=0;
                else if(i==0)
                {
                    
                    grid[i][j]=grid[i][j-1]; 
                }
                   
                else if(j==0)
                    grid[i][j]=grid[i-1][j];
                else
                    grid[i][j]=grid[i-1][j]+grid[i][j-1];
            }
        }
        return grid[m-1][n-1];
        
}
