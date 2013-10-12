class Solution {
public:
    enum {ROW=0, COL, BLOCK};
    int m, n;
    bool search(vector<vector<char> > &board, vector<vector<bool> > (&env)[3], int i, int j)
    {
        if (j >= n)
        {
            j = 0;
            ++i;
        }
        if (i>=m)   return true;
        if (board[i][j] != '.')
            return search(board, env, i, j+1);
        else
        {
            for (int k=1; k<=9; ++k)
            {
                if (!env[ROW][i][k] && !env[COL][j][k] && !env[BLOCK][(i/3)*3+j/3][k])
                {
                    board[i][j] = '0'+k;
                    env[ROW][i][k] = env[COL][j][k] = env[BLOCK][(i/3)*3+j/3][k] = true;
                    if (search(board, env, i, j+1))
                        return true;
                    else
                        env[ROW][i][k] = env[COL][j][k] = env[BLOCK][(i/3)*3+j/3][k] = false;
                }
            }
            board[i][j] = '.';
            return false;
        }
    }
    
    void solveSudoku(vector<vector<char> > &board) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<vector<bool> > env[3];
        
        for (int i=0; i<3; ++i)
            env[i].resize(9);
        for (int i=0; i<3; ++i)
            for (int j=0; j<9; ++j)
            env[i][j].resize(10, false);
        //init
        m = board.size();
        if (m != 9) return;
        n = board[0].size();
        if (n != 9) return;
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                if (isdigit(board[i][j]))
                {
                    env[ROW][i][board[i][j]-'0'] = true;
                    env[COL][j][board[i][j]-'0'] = true;
                    env[BLOCK][(i/3)*3+j/3][board[i][j]-'0'] = true;
                }
        search(board, env, 0, 0);
    }
};
