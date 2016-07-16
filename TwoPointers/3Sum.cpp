/*
3 Sum

Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.

Example:
given array S = {-1 2 1 -4},
and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2)
*/


    int Solution::threeSumClosest(vector<int> &A, int B) {
        // Do not write main() function.
        // Do not read input, instead use the arguments to the function.
        // Do not print the output, instead return values as specified
        // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
        sort(A.begin(),A.end());
        int sum=0,diff=INT_MAX;
        int l=0,r=0;
        for(int i=0;i<A.size()-2;i++)
        {
            l=i+1;
            r=A.size()-1;
            while(l<r)
            {
                if(A[i]+A[l]+A[r]==B)
                {
                    return B;
                }
                else if(A[i]+A[l]+A[r] < B)
                {
                    int val=abs(A[i]+A[l]+A[r]-B);
                    if(val < diff)
                    {
                        diff=val;
                        sum=A[i]+A[l]+A[r];
                    }
                    l++;
                }
                else
                {
                    int val=abs(A[i]+A[l]+A[r]-B);
                    if(val < diff)
                    {
                        diff=val;
                        sum=A[i]+A[l]+A[r];
                    }
                    r--;
                }
            }
        }
        return sum;
    }

    

