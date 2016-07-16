/*
Anagrams

Given an array of strings, return all groups of strings that are anagrams. Represent a group by a list of integers representing the index in the original list. Look at the sample case for clarification.

    Anagram : a word, phrase, or name formed by rearranging the letters of another, such as 'spar', formed from 'rasp' 

    Note: All inputs will be in lower-case. 

Example :

Input : cat dog god tca
Output : [[1, 4], [2, 3]]

cat and tca are anagrams which correspond to index 1 and 4.
dog and god are another set of anagrams which correspond to index 2 and 3.
The indices are 1 based ( the first element has index 1 instead of index 0).

    Ordering of the result : You should not change the relative ordering of the words / phrases within the group. Within a group containing A[i] and A[j], A[i] comes before A[j] if i < j. 

*/

vector<vector<int> > Solution::anagrams(const vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<int>> vec;
    map<string,vector<int>> m;
    map<string,vector<int>> :: iterator it;
    string temp;
    for(int i=0;i<A.size();i++)
    {
        temp=A[i];
        sort(temp.begin(),temp.end());
        m[temp].push_back(i+1);
    }
    for(it=m.begin();it!=m.end();it++)
    {
        vector<int> tmp=it->second;
        sort(tmp.begin(),tmp.end());
        vec.push_back(tmp);
    }
    return vec;
}
