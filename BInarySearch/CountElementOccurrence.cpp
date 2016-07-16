/*
Given a sorted array of integers, find the number of occurrences of a given target value.
Your algorithm’s runtime complexity must be in the order of O(log n).
If the target is not found in the array, return 0

**Example : **
Given [5, 7, 7, 8, 8, 10] and target value 8,
return 2.
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

int Solution::findCount(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int first=bsFirst(A,B,0,A.size()-1);
   // cout<<first<<endl;
    if(first ==-1)
        return 0;
    int second=bsSecond(A,B,0,A.size()-1);
    //cout<<second<<endl;
    return second-first+1;
}
