/*
4 Sum

Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

    Note:

        Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
        The solution set must not contain duplicate quadruplets.

Example :
Given array S = {1 0 -1 0 -2 2}, and target = 0
A solution set is:

    (-2, -1, 1, 2)
    (-2,  0, 0, 2)
    (-1,  0, 0, 1)

Also make sure that the solution set is lexicographically sorted.
Solution[i] < Solution[j] iff Solution[i][0] < Solution[j][0] OR (Solution[i][0] == Solution[j][0] AND ... Solution[i][k] < Solution[j][k])
*/


vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<int> > ans;
    vector<int> subvec;
    int n=A.size();
    int i,j,l,r;
    sort(A.begin(),A.end());
    for(i=0;i<n-3;i++)
    {
        for(j=i+1;j<n-2;j++)
        {
            r=n-1;
            l=j+1;
            while(l<r)
            {
                if(A[i]+A[j]+A[l]+A[r]==B)
                {
                    subvec.push_back(A[i]);
                    subvec.push_back(A[j]);
                    subvec.push_back(A[l]);
                    subvec.push_back(A[r]);
                    ans.push_back(subvec);
                    subvec.clear();
                    l++;
                }
                else if(A[i]+A[j]+A[l]+A[r]<B)
                    l++;
                else
                    r--;
            }
        }
    }
    sort(ans.begin(),ans.end());
    map<vector<int>,int> m;
    map<vector<int>,int> :: iterator it;
    for(int i=0;i<ans.size();i++)
    {
        it=m.find(ans[i]);
        if(it==m.end())
            m.insert(pair<vector<int>,int>(ans[i],1));
    }
    ans.clear();
    for(it=m.begin();it!=m.end();it++)
    {
        ans.push_back(it->first);
    }
    return  ans;
}
