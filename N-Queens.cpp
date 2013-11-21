class Solution {
public:
    vector<vector<string> > res;
    int lines;
    static const int dirNum = 4;
    static const int dir[dirNum][2];

    
    void search(vector<vector<bool> >& queens, int level)
    {
        if (level == lines)
        {
            vector<string> tmpV;
            for (int i=0; i<lines; ++i)
            {
                string tmpStr;
                for (int j=0; j<lines; ++j)
                    if(queens[i][j])
                        tmpStr += 'Q';
                    else
                        tmpStr += '.';
                tmpV.push_back(tmpStr);
            }
            res.push_back(tmpV);
            return;
        }
        
        for (int i=0; i<lines; ++i)
        {
            bool available = true;
            
            for (int j=0; j<level; ++j)
                if (queens[j][i])
                {
                    available = false;
                    break;
                }
                
            if (!available)     continue;
            
            for (int j=0; j<dirNum; ++j)
            {
                int tmpx = level+dir[j][0], tmpy = i+dir[j][1];
                while (tmpx>=0 && tmpx<lines && tmpy>=0 && tmpy<lines)
                {
                    if (queens[tmpx][tmpy])
                    {
                        available = false;
                        break;
                    }
                    tmpx += dir[j][0];
                    tmpy += dir[j][1];
                }
                if (!available)  break;
            }
            
            if (available)
            {
                queens[level][i] = true;
                search(queens, level+1);
                queens[level][i] = false;   
            }
        }
    }
    
    vector<vector<string> > solveNQueens(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        res.clear();
        lines = n;
        vector<vector<bool> > queens(n, vector<bool>(n, false));
        
        search(queens, 0);
        return res;
    }
};

const int Solution::dir[][2] = {{1,1}, {1,-1}, {-1,1}, {-1,-1}};
