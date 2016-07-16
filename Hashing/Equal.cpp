/*
Equal

Given an array A of integers, find the index of values that satisfy A + B = C + D, where A,B,C & D are integers values in the array

Note:

1) Return the indices `A1 B1 C1 D1`, so that 
  A[A1] + A[B1] = A[C1] + A[D1]
  A1 < B1, C1 < D1
  A1 < C1, B1 != D1, B1 != C1 

2) If there are more than one solutions, 
   then return the tuple of values which are lexicographical smallest. 

Assume we have two solutions
S1 : A1 B1 C1 D1 ( these are values of indices int the array )  
S2 : A2 B2 C2 D2

S1 is lexicographically smaller than S2 iff
  A1 < A2 OR
  A1 = A2 AND B1 < B2 OR
  A1 = A2 AND B1 = B2 AND C1 < C2 OR 
  A1 = A2 AND B1 = B2 AND C1 = C2 AND D1 < D2

Example:

Input: [3, 4, 7, 1, 2, 9, 8]
Output: [0, 2, 3, 5] (O index)

If no solution is possible, return an empty list.
*/

vector<int> Solution::equal(vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> ans;
    if(A.size()<4)
        return ans;
    map<int,vector<int> > m;
    map<int,vector<int> >::iterator it;
    for(int i=0;i<A.size();i++)
    {
        for(int j=i+1;j<A.size();j++)
        {
            int sum=A[i]+A[j];
            it=m.find(sum);
            if(it==m.end())
            {
                vector<int> vec;
                vec.push_back(i);
                vec.push_back(j);
                m.insert(pair<int,vector<int>>(sum,vec));
                vec.clear();
            }
            else 
            {
                vector<int> temp=it->second;
                vector<int> vec;
                if(i!=temp[0] && i!=temp[1] && j!=temp[0] && j!=temp[1])
                {
                    if(ans.size()==0)
                    {
                        ans.push_back(temp[0]);
                        ans.push_back(temp[1]);
                        ans.push_back(i);
                        ans.push_back(j);
                    }
                    else
                    {
                        vec.push_back(temp[0]);
                        vec.push_back(temp[1]);
                        vec.push_back(i);
                        vec.push_back(j);
                        if(vec[0] < ans[0])
                        {
                            ans=vec;
                        }
                        else if(vec[0]==ans[0] && vec[1]<ans[1])
                        {
                            ans=vec;
                        }
                        else if(vec[0]==ans[0] && vec[1]==ans[1] && vec[2]<ans[2])
                            ans=vec;
                        else if(vec[0]==ans[0] && vec[1]==ans[1] && vec[2]==ans[2] && vec[3]<ans[3])
                            ans=vec;
                    }
                   
                    
                }
            }
        }
    }
    return ans;
}

