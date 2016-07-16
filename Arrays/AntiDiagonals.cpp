/*



Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

Example:

		
Input: 	

1 2 3
4 5 6
7 8 9

Return the following :

[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]


Input : 
1 2
3 4

Return the following  : 

[
  [1],
  [2, 3],
  [4]
]


*/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    int n=A.size();
    vector<vector<int>> ans;
    for(int i=0;i<n;i++)
    {
        int row=0,col=i;
        vector<int> subvec;
        while(row>=0 && row<n && col>=0 && col<n )
        {
            subvec.push_back(A[row][col]);
            row++;
            col--;
        }
        ans.push_back(subvec);
    }
    
    for(int i=1;i<n;i++)
    {
        int row=i,col=n-1;
        vector<int> subvec;
        while(row>=0 && row<n && col>=0 && col<n )
        {
            subvec.push_back(A[row][col]);
            row++;
            col--;
        }
        ans.push_back(subvec);
    }
    return ans;
}
