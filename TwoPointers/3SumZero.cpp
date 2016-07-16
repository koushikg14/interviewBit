/*
3 Sum Zero

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:

    Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
    The solution set must not contain duplicate triplets.

    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2) 

*/

vector<vector<int> > Solution::threeSum(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<int>> vec;
    if(A.size()<3)
        return vec;
    vector<int> subvec;
    int l=0,r=0;
    sort(A.begin(),A.end());
    map<vector<int>,int> m;
    map<vector<int>,int>::iterator it;
    for(int i=0;i<A.size()-2;i++)
    {
        l=i+1;
        r=A.size()-1;
        while(l<r)
        {
            if((A[i]+A[l]+A[r])==0)
            {
                subvec.push_back(A[i]);
                subvec.push_back(A[l]);
                subvec.push_back(A[r]);
                sort(subvec.begin(),subvec.end());
                it=m.find(subvec);
                if(it==m.end())
                {   
                    m.insert(pair<vector<int>,int>(subvec,1));
                    vec.push_back(subvec);
                }
                subvec.clear();
                l++;
                r--;
            }
            else if(A[i]+A[l]+A[r] < 0)
                l++;
            else
                r--;
        }
    }
    sort(vec.begin(),vec.end());
    return vec;
}
