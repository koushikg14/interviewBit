/*


For Given Number N find if its COLORFUL number or not

Return 0/1

COLORFUL number:

A number can be broken into different sub-sequence parts. 
Suppose, a number 3245 can be broken into parts like 3 2 4 5 32 24 45 324 245. 
And this number is a COLORFUL number, since product of every digit of a sub-sequence are different

Example:

N = 23
2 3 23
2 -> 2
3 -> 3
23 -> 6
this number is a COLORFUL number since product of every digit of a sub-sequence are different. 

Output : 1

*/

int Solution::colorful(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
	    if(A==0)
	        return true;
	    map<int,int> m;
	    map<int,int> :: iterator it;
	    vector<int> vec;
	    int num=A,rem;
	    while(num>0)
	    {
	        rem=num%10;
	        vec.push_back(rem);
            num/=10;
	    }
	    reverse(vec.begin(),vec.end());
	    if(vec.size()==1)
	        return true;
	    int prod;
	    for(int i=0;i<vec.size();i++)
	    {
	        prod=1;
	        for(int j=i;j<vec.size();j++)
	        {   
	            prod*=vec[j];
	            it=m.find(prod);
	            if(it==m.end())
	                m.insert(pair<int,int>(prod,1));
	            else
	                return 0;
	        }
	    }
        return 1;
}
