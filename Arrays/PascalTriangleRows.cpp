/*


Given numRows, generate the first numRows of Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Given numRows = 5,

Return

[
     [1],
     [1,1],
     [1,2,1],
     [1,3,3,1],
     [1,4,6,4,1]
]


*/
vector<vector<int> > Solution::generate(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<int>> ans;
    if(A==0)
        return ans;
    vector<int> subvec;
    subvec.push_back(1);
    ans.push_back(subvec);
    if(A==1)
        return ans;
    for(int i=2;i<=A;i++)
    {
        vector<int> temp;
        temp.push_back(1);
        for(int k=0;k<subvec.size()-1;k++)
        {
            temp.push_back(subvec[k]+subvec[k+1]);
        }
        temp.push_back(1);
        ans.push_back(temp);
        subvec.clear();
        subvec=temp;
    }
    return ans;
}
