/*
2 Sum

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 < index2. Please note that your returned answers (both index1 and index2 ) are not zero-based.
Put both these numbers in order in an array and return the array from your function ( Looking at the function signature will make things clearer ). Note that, if no pair exists, return empty list.

If multiple solutions exist, output the one where index2 is minimum. If there are multiple solutions with the minimum index2, choose the one with minimum index1 out of them.

Input: [2, 7, 11, 15], target=9
Output: index1 = 1, index2 = 2

*/

vector<int> Solution::twoSum(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> vec;
    if(A.size()==0)
        return vec;
    if(A.size()==1)
        return vec;
    map<int,int> m;
    map<int,int>::iterator it;
    for(int i=0;i<A.size();i++)
    {
        it=m.find(B-A[i]);
        if(it==m.end())
            m.insert(pair<int,int>(A[i],i+1));
    }
    for(int i=0;i<A.size();i++)
    {
        it=m.find(B-A[i]);
        if(it!=m.end())
        {
            if(it->second!=i+1)
            {
                vec.push_back(it->second);
                vec.push_back(i+1);
                break;
            }
        }
    }
    sort(vec.begin(),vec.end());
    return vec;
   
}
