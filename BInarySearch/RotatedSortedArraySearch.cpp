/*
Rotated Sorted Array Search

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2 ).

You are given a target value to search. If found in the array, return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Input : [4 5 6 7 0 1 2] and target = 4
Output : 0

*/

int binarySearch(const vector<int>& A,int target,int start,int end)
{
    if(start>end)
        return -1;
    int mid=start+(end-start)/2;
    if(A[mid]==target)
        return mid;
    else if(A[mid]>target)
        return binarySearch(A,target,start,mid-1);
    else
        return binarySearch(A,target,mid+1,end);
}

int getPivot(const vector<int>& A,int start,int end)
{
    if(start>end)
        return -1;
    if(start==end)
        return start;
    
    int mid=start+(end-start)/2;
    if(mid<end && A[mid]>A[mid+1])
        return mid;
    else if(mid>start && A[mid]<A[mid-1])
        return mid-1;
    else if(A[mid]>A[end])
        return getPivot(A,mid+1,end);
    else
        return getPivot(A,start,mid-1);
}



int Solution::search(const vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size()==0)
        return -1;
    int pivot=0;
    if(A[0]<A[A.size()-1])
        pivot=-1;
    if(pivot==-1)
        return binarySearch(A,B,0,A.size()-1);
    else
    {
        pivot=getPivot(A,0,A.size()-1);
        if(A[pivot]==B)
            return pivot;
        else if(B>=A[0])
            return binarySearch(A,B,0,pivot-1);
        else
            return binarySearch(A,B,pivot+1,A.size()-1);
    }
    return 0;
}
