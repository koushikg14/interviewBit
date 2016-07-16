/*


Given an index k, return the kth row of the Pascal’s triangle.

Pascal’s triangle : To generate A[C] in row R, sum up A’[C] and A’[C-1] from previous row R - 1.

Example:

Input : k = 3

Return : [1,3,3,1]

    NOTE : k is 0 based. k = 0, corresponds to the row [1]. 

Note:Could you optimize your algorithm to use only O(k) extra space?

*/
vector<int> Solution::getRow(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> ans;
    ans.push_back(1);
    if(A==0)
        return ans;
    for(int i=1;i<=A;i++)
    {
        vector<int> temp;
        temp.push_back(1);
        for(int k=0;k<ans.size()-1;k++)
        {
            temp.push_back(ans[k]+ans[k+1]);
        }
        temp.push_back(1);
        ans=temp;
    }
    return ans;
}
