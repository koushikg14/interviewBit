/*


Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:

Given intervals [1,3],[6,9] insert and merge [2,5] would result in [1,5],[6,9].

Example 2:

Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] would result in [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Make sure the returned intervals are also sorted.

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
vector<Interval> Solution::insert(vector<Interval> &intervals, Interval newInterval) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    if(intervals.size()==0)
    {
        intervals.push_back(newInterval);
        return intervals;
    }
    int i=0;
    for(i=0;i<intervals.size();i++)
    {
        if(intervals[i].start > newInterval.start)
            break;
    }
        
    intervals.insert(intervals.begin()+i,newInterval);
    stack<Interval> st;
    st.push(intervals[0]);
    for(int i=1;i<intervals.size();i++)
    {
        Interval temp=st.top();
        if(intervals[i].start <= temp.end)
        {
            if(intervals[i].end > temp.end)
                temp.end=intervals[i].end;
            st.pop();
            st.push(temp);
        }
        else
            st.push(intervals[i]);
    }
    
    
    intervals.clear();
    while(!st.empty())
    {
        intervals.push_back(st.top());
        st.pop();
    }
    reverse(intervals.begin(),intervals.end());
    return intervals;
}
