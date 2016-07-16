/*


Given a collection of intervals, merge all overlapping intervals.

For example:

Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.

*/
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 bool compare(Interval lhs,Interval rhs)
 {
    return lhs.start<rhs.start;
 }
 
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(A.size()==0 || A.size()==1)
        return A;
    sort(A.begin(),A.end(),compare);
    stack<Interval> st;
    st.push(A[0]);
    for(int i=1;i<A.size();i++)
    {
        Interval temp=st.top();
        if(temp.end >= A[i].start)
        {
            if(temp.end < A[i].end)
                temp.end=A[i].end;
            st.pop();
            st.push(temp);
        }
        else
            st.push(A[i]);
    }
    A.clear();
    while(!st.empty())
    {
        A.push_back(st.top());
        st.pop();
    }
    reverse(A.begin(),A.end());
    return A;
}
