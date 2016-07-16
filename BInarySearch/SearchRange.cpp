/*
Search for a Range

Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm’s runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example:

Given [5, 7, 7, 8, 8, 10]

and target value 8,

return [3, 4].

*/

int bsFirst(const vector<int>& vec,int target,int start,int end)
{
    if(start>end)
        return -1;
 
    int mid=(start+end)/2;
    if(mid==start && vec[mid]==target)
        return start;
    if(mid>start && vec[mid]==target && vec[mid-1]<target)
        return mid;
    else if(target>vec[mid])
        return bsFirst(vec,target,mid+1,end);
    else
        return bsFirst(vec,target,start,mid-1);
}

int bsSecond(const vector<int>& vec,int target,int start,int end)
{
    if(start>end)
        return -1;
    int mid=(start+end)/2;
    if(mid==end && vec[mid]==target)
        return end;
    if(mid<end && vec[mid]==target && vec[mid+1]>target)
        return mid;
    else if(target<vec[mid])
        return bsSecond(vec,target,start,mid-1);
    else 
        return bsSecond(vec,target,mid+1,end);
   
}




vector<int> Solution::searchRange(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> ans;
    if(A.size()==0)
        return ans;
    int first=bsFirst(A,B,0,A.size()-1);
    if(first ==-1)
    {
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
    int second=bsSecond(A,B,0,A.size()-1);
    ans.push_back(first);
    ans.push_back(second);
}
