/*
Min Sum Path in Triangle

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

    Note:
    Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle. 

*/

int Solution::minimumTotal(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size()==0)
        return 0;
    int m=A.size();
    int n=m;
    vector<vector<int> > vec(m,vector<int>(n,0));
    vec[0][0]=A[0][0];
    for(int i=1;i<m;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(j==0 && i==0)
                continue;
            if(j==0)
                vec[i][j]=vec[i-1][j]+A[i][j];
            else if(j==i)
                vec[i][j]=vec[i-1][j-1]+A[i][j];
            else
                vec[i][j]=min(vec[i-1][j-1],vec[i-1][j])+A[i][j];
        }
    }

    int mincost=INT_MAX;
    for(int i=0;i<n;i++)
        mincost=min(mincost,vec[m-1][i]);
    return mincost;
}