/*


The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P.......A........H.......N
..A..P....L....S....I...I....G
....Y.........I........R

And then read line by line: PAHNAPLSIIGYIR
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"

**Example 2 : **
ABCD, 2 can be written as

A....C
...B....D

and hence the answer would be ACBD.
*/

string Solution::convert(string A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
  
    vector<vector<char>> vec(B);
        string ans;
        int pos=0;
        int index=0;
        while(index<A.length())
        {
            if(pos%2==0)
            {
                for(int j=0;j<B && index<A.length();j++)
                {
                    vec[j].push_back(A[index++]);
                }
            }
            else
            {
                for(int j=B-2;j>0 && index<A.length();j--)
                {
                    vec[j].push_back(A[index++]);
                }
            }
            pos++;
        }
        
        for(int i=0;i<B;i++)
        {
            for(int j=0;j<vec[i].size();j++)
             {
                 ans+=vec[i][j];
             }
        }
        return ans;
}
