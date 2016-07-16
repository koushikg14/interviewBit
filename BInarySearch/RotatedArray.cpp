/*
Rotated Array

Suppose a sorted array A is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

The array will not contain duplicates.

        NOTE 1: Also think about the case when there are duplicates. Does your current solution work? How does the time complexity change?*


        */


int Helper(const vector<int>& vec,int start,int end)
{
    if(start==end)
        return vec[start];
   
    int mid=(start+end)/2;
    if(mid>start && vec[mid]<vec[mid-1])
        return vec[mid];
    if(mid<end && vec[mid]>vec[mid+1])
        return vec[mid+1];
    if(vec[mid]>vec[end])
        return Helper(vec,mid+1,end);
    else
        return Helper(vec,start,mid-1);
}



int Solution::findMin(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size()==0)
        return -1;
    if(A[0]<=A[A.size()-1])
        return A[0];
    return Helper(A,0,A.size()-1);
}
