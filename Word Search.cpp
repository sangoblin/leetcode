class Self
{
public:
    int again;
    int depth;
    Self(): again(0), depth(0) {}
};

class Solution {
public:
    static const int dir[4][2];
    int m,n;
    bool DFS(vector<vector<char> > &board, string& word, int x, int y, vector<vector<bool> >& visited, 
    vector<vector<Self> >& never, int depth)
    {
        if (word[0] != board[x][y]) return false;
        if (depth==never[x][y].depth && never[x][y].again) return false;
        char back = word[0];
        bool res = false;
        word.erase(word.begin());
        if (word.empty())  return true;
        visited[x][y] = true;
        for (int i=0; i<sizeof(dir)/sizeof(dir[0]); ++i)
        {
            int x_ = x+dir[i][0], y_ = y+dir[i][1];
            
            if (x_>=0 && x_<m && y_>=0 && y_<n && !visited[x_][y_])
                res |= DFS(board, word, x_, y_, visited, never, depth+1);
                
            if (res)
                return true;
        }
        word.insert(word.begin(), back);
        never[x][y].depth = depth;
        never[x][y].again = -1;
        visited[x][y] = false;
        return res;
    }

    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        m = board.size();
        if (m == 0) return false;
        n = board[0].size();
        bool res = false;
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        vector<vector<Self> > never(m, vector<Self>(n));

        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
            {
                res |= DFS(board, word, i, j, visited, never, 0);
                if (res)
                    break;
            }
        return res;
    }
};

const int Solution::dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
