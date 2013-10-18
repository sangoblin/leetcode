class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        bool all0 = false, has0 = false;
        int m = matrix.size();
        if (m == 0) return;
        int n = matrix[0].size();
        bool origr = false, origc = false;
        
        for (int i=0; i<n; ++i)
            if (!matrix[0][i])
            {
                origr = true;
                break;
            }
        
        for (int i=0; i<m; ++i)
            if (!matrix[i][0])
            {
                origc = true;
                break;
            }
        
        
        for (int i=1; i<m; ++i)
            for (int j=1; j<n; ++j)
                if (!matrix[i][j])
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
        
        for (int i=1; i<n; ++i)
            if (!matrix[0][i])
                for (int j=1; j<m; ++j)
                    matrix[j][i] = 0;
        
        for (int i=1; i<m; ++i)
            if (!matrix[i][0])
                for (int j=1; j<n; ++j)
                    matrix[i][j] = 0;
        if (origr)
            for (int i=0; i<n; ++i)
                matrix[0][i] = 0;
        
        if (origc)
            for (int i=0; i<m; ++i)
                matrix[i][0] = 0;
    }
};
