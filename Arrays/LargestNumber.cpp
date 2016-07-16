/*


Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/



bool compare(int lhs,int rhs)
{
    string s1=to_string(lhs)+to_string(rhs);
    string s2=to_string(rhs)+to_string(lhs);
    return s1>s2;
}


string auxfunc(vector<int>vec)
{
    string ans;
    sort(vec.begin(),vec.end(),compare);
    for(int i=0;i<vec.size();i++)
        ans+=to_string(vec[i]);
    int i=0;
    while(i<ans.size())
    {
        if(ans[0]=='0')
            ans.erase(ans.begin());
        else
            break;
    }
    if(ans.size()==0)
        ans+='0';
    return ans;
}

string Solution::largestNumber(const vector<int> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    return auxfunc(A);
}
