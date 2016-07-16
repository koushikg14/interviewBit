/*


Given an m x n matrix of 0s and 1s, if an element is 0, set its entire row and column to 0.

Do it in place.

Example

Given array A as

1 0 1
1 1 1 
1 1 1

On returning, the array A should be :

0 0 0
1 0 1
1 0 1

Note that this will be evaluated on the extra memory used. Try to minimize the space and time complexity.


*/

void Solution::setZeroes(vector<vector<int> > &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size()==0)
        return;
    int state_firstrow=A[0][0];
    int state_firstcol=A[0][0];
    
    int m=A.size(),n=A[0].size();
    for(int i=0;i<n;i++)
    {
        if(A[0][i]==0)
        {
            state_firstrow=0;
            break;
        }
    }
    
    for(int i=0;i<m;i++)
    {
        if(A[i][0]==0)
        {
            state_firstcol=0;
            break;
        }
    }
    
    for(int i=1;i<m;i++)
    {
        int flag=0;
        for(int j=0;j<n;j++)
        {
            if(A[i][j]==0)
            {
                flag=1;
                break; 
            }
        }
        if(flag)
            A[i][0]=0;
    }
    
    for(int j=1;j<n;j++)
    {
        int flag=0;
        for(int i=0;i<m;i++)
        {
            if(A[i][j]==0)
            {
                flag=1;
                break; 
            }
        }
        if(flag)
            A[0][j]=0;
    }
    
    
    for(int i=1;i<m;i++)
    {
       if(A[i][0]==0)
       {
           for(int j=0;j<n;j++)
                A[i][j]=0;
       }
    }
    
    for(int j=1;j<n;j++)
    {
       if(A[0][j]==0)
       {
           for(int i=0;i<m;i++)
                A[i][j]=0;
       }
    }
    
    if(state_firstrow==0)
    {
        for(int i=0;i<n;i++)
            A[0][i]=0;
    }
    
    if(state_firstcol==0)
    {
        for(int i=0;i<m;i++)
            A[i][0]=0;
    }
    return;
}
