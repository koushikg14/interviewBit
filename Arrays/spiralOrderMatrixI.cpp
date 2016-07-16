/*
Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example:

Given the following matrix:

[
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
]

You should return

[1, 2, 3, 6, 9, 8, 7, 4, 5]

*/

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
	vector<int> ans;
	int m=A.size(),n=A[0].size();
	int left=0,right=n-1,top=0,bottom=m-1;
	int direction=0;
	int i,j;
	while(left<=right && top<=bottom)
	{
	    if(direction==0)
	    {
	        i=left;
	        j=right;
	        while(i<=j)
	        {
	            ans.push_back(A[top][i]);
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
	            ans.push_back(A[i][right]);
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
	            ans.push_back(A[bottom][i]);
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
	            ans.push_back(A[i][left]);
	            i--;
	        }
	        left++;
	        direction=0;
	    }
	}
	return ans;
   
}
