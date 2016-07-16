/*
Largest Continuous Sequence Zero Sum

Find the largest continuous sequence in a array which sums to zero.

Example:


Input:  {1 ,2 ,-2 ,4 ,-4}
Output: {2 ,-2 ,4 ,-4}

    NOTE : If there are multiple correct answers, return the sequence which occurs first in the array. 

*/

vector<int> Solution::lszero(vector<int> &A) {
    vector<int> ans;
    if(A.size()==0 )
        return ans;
    int sum=0,n=A.size();
    vector<int> arr(n);
    map<int,int> m;
    map<int,int>:: iterator it;
    int maxlen=INT_MIN;
    for(int i=0;i<n;i++)
    {
        sum+=A[i];
        if(sum==0)
        {
            if(i+1 >maxlen)
                maxlen=i+1;
            ans.clear();
            for(int k=0;k<=i;k++)
                ans.push_back(A[k]);
        }
        arr[i]=sum;
    }
 
    for(int i=0;i<n;i++)
    {
        it=m.find(arr[i]);
        if(it==m.end())
            m.insert(pair<int,int>(arr[i],i));
        else
        {
            if(i!=it->second && (i-(it->second))>maxlen)
            {
                maxlen=i-(it->second);
                ans.clear();
                for(int k=it->second+1;k<=i;k++)
                    ans.push_back(A[k]);
            }
        }
    }
    return ans;
}
