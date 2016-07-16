/*
Determine if a Sudoku is valid, according to: http://sudoku.com.au/TheRules.aspx

The Sudoku board could be partially filled, where empty cells are filled with the character ‘.’.

The input corresponding to the above configuration :

["53..7....", "6..195...", ".98....6.", "8...6...3", "4..8.3..1", "7...2...6", ".6....28.", "...419..5", "....8..79"]

A partially filled sudoku which is valid.
*/

int Solution::isValidSudoku(const vector<string> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    map<char,char> m;
    map<char,char>::iterator it;
    //check horizontal lines
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(A[i][j]!='.')
            {
                it=m.find(A[i][j]);
                if(it==m.end())
                    m.insert(pair<char,char>(A[i][j],1));
                else
                    return 0;
            }
        }
        m.clear();
    }
    //check vertical lines
    for(int j=0;j<9;j++)
    {
        for(int i=0;i<9;i++)
        {
            if(A[i][j]!='.')
            {
                it=m.find(A[i][j]);
                if(it==m.end())
                    m.insert(pair<char,char>(A[i][j],1));
                else
                    return 0;
            }
        }
        m.clear();
    }
    
    //check section wise
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            for(int k=i*3;k<3*i+3;k++)
            {
                for(int l=j*3;l<3*j+3;l++)
                {
                    if(A[k][l]!='.')
                    {
                        it=m.find(A[k][l]);
                        if(it==m.end())
                            m.insert(pair<char,char>(A[k][l],1));
                        else
                            return false;
                    }
                }
            }
            m.clear();
        }
    }
    
    return 1;
}
