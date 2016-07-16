/*


Given an even number ( greater than 2 ), return two prime numbers whose sum will be equal to given number.

NOTE A solution will always exist. read Goldbach’s conjecture

Example:


Input : 4
Output: 2 + 2 = 4

If there are more than one solutions possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b,
and [c,d] is another solution with c <= d, then

[a, b] < [c, d] 

If a < c OR a==c AND b < d. 


*/

vector<int> Solution::primesum(int A) {
    vector<int> ans;
    vector<int> temp;
    for(int i=2;i<A;i++)
    {
        int flag=0;
        for(int j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            for(int j=2;j<=sqrt(A-i);j++)
            {
                if((A-i)%j==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                ans.push_back(i);
                ans.push_back(A-i);
                return ans;
            }     
        }
       
    }
    return ans;
}
