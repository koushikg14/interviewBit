/*


Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Given n = 3,

You should return the following matrix:
[ [ 1, 2, 3 ], [ 8, 9, 4 ], [ 7, 6, 5 ] ]

*/

vector<vector<int> > Solution::generateMatrix(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	vector<vector<int> > ans(A,vector<int>(A));
	int left=0,right=A-1,top=0,bottom=A-1;
	int direction=0;
	int i,j;
	int values=1;
	while(left<=right && top<=bottom)
	{
	    if(direction==0)
	    {
	        i=left;
	        j=right;
	        while(i<=j)
	        {
	            ans[top][i]=values++;
	            i++;
	        }
	        top++;
	        direction=1;
	    }
	    else if(direction==1)
	    {
	        i=top;
	        j=bottom;
	        while(i<=j)
	        {
	            ans[i][right]=values++;
	            i++;
	        }
	        right--;
	        direction=2;
	    }
	    else if(direction==2)
	    {
	        i=right;
	        j=left;
	        while(i>=j)
	        {
	            ans[bottom][i]=values++;
	            i--;
	        }
	        bottom--;
	        direction=3;
	    }
	    else 
	    {
	        i=bottom;
	        j=top;
	        while(i>=j)
	        {
	            ans[i][left]=values++;
	            i--;
	        }
	        left++;
	        direction=0;
	    }
	}
	return ans;
   
}
