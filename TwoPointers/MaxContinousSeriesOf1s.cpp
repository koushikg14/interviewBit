/*
Max Continuous Series of 1s

You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.
Find the position of zeros which when flipped will produce maximum continuous series of 1s.

For this problem, return the indices of maximum continuous series of 1s in order.

Example:

Input : 
Array = {1 1 0 1 1 0 0 1 1 1 } 
M = 1

Output : 
[0, 1, 2, 3, 4] 

If there are multiple possible solutions, return the sequence which has the minimum start index.
*/

vector<int> Solution::maxone(vector<int> &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<int> vec;
    int wl=0,wr=0;
    int maxlen=INT_MIN,count=0;
    int i=0;
    while(wr < A.size())
    {
        if(A[wr]==1)
        {
           wr++;
        }
        else if(A[wr]==0)
        {
            if(count<B)
            {
                wr++;
                count++;
            }
            else
            {
                if(wr-wl>maxlen)
                {
                    vec.clear();
                    maxlen=wr-wl;
                    for(int i=wl;i<wr;i++)
                        vec.push_back(i);
                }
                while(A[wl]==1)
                    wl++;
                    count--;
                    wl++;
               // }
            }
        }
        
    }
    if(wr-wl > maxlen)
    {
        vec.clear();
        for(int i=wl;i<wr;i++)
            vec.push_back(i);
    }
    return vec;
}
