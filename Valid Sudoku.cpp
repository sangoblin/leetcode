class Solution {
public:

    int m, n;
    bool check(vector<vector<char> > &board, int i, int j)
    {
        for (int k=0; k<n; ++k)
            if (k!=j && board[i][k]==board[i][j])
                return false;
        for (int k=0; k<m; ++k)
            if (k!=i && board[k][j]==board[i][j])
                return false;
        int starti = (i/3)*3, startj = (j/3)*3;
        for (int k=starti; k<starti+3; ++k)
            for (int l=startj; l<startj+3; ++l)
                if (k!=i && l!=j && board[k][l]==board[i][j])
                    return false;
        return true;
    }
    
    bool isValidSudoku(vector<vector<char> > &board) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        m = board.size();
        if (m != 9)     return false;
        n = board[0].size();
        if (n != 9)     return false;
        
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
            {
                if (board[i][j]!='.' && !check(board, i,  j))
                    return false;
            }
        return true;
    }
};
