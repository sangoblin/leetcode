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
    bool DFS(vector<vector<char> > &board, string& word, int x, int y, bool **visited)
    {
        if (word[0] != board[x][y]) return false;
        //if (depth==never[x][y].depth && never[x][y].again) return false;
        char back = word[0];
        bool res = false;
        word.erase(word.begin());
        if (word.empty())  return true;
        visited[x][y] = true;
        for (int i=0; i<sizeof(dir)/sizeof(dir[0]); ++i)
        {
            int x_ = x+dir[i][0], y_ = y+dir[i][1];
            
            if (x_>=0 && x_<m && y_>=0 && y_<n && !visited[x_][y_])
                res |= DFS(board, word, x_, y_, visited);
                
            if (res)
                //break;
                return true;
        }
        word.insert(word.begin(), back);
        //never[x][y].depth = depth;
        //never[x][y].again = -1;
        return res;
    }

    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        m = board.size();
        if (m == 0) return false;
        n = board[0].size();
        bool res = false;

        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
            {
                bool** visited = new bool*[m*sizeof(bool*)];
            	//Self **never = new Self*[m];
        				for (int i=0; i<m; ++i)
        				{
        					visited[i] = new bool[n];
        					//never[i] = new Self[n];
        					memset(visited[i], 0, n*sizeof(bool));
        					//memset(never[i], 0,);
        				}
                res |= DFS(board, word, i, j, visited);
                if (res)
                    break;
                 for (int i=0; i<m; ++i)
                 {
                    delete[] visited[i];
                    //delete[] never[i];
                 }
                delete[] visited;
                //delete[] never;
            }
        return res;
    }
};

const int Solution::dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
