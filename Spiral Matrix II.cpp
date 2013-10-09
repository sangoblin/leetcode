class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (n <= 0) return vector<vector<int> >();
        vector<vector<int> > res(n, vector<int>(n, 0));
        int start1 = 0, end1 = n, start2 = 0, end2 = n, cnt = 0;
        
        while (cnt < n*n)
        {
            for (int i=start1; i<end1; ++i)
                res[start1][i] = ++cnt;
            ++start2;
            for (int i=start2; i<end2; ++i)
                res[i][end1-1] = ++cnt;
            --end1;
            for (int i=end1-1; i>=start1; --i)
                res[end1][i] = ++cnt;
            --end2;
            for (int i=end2-1; i>=start2; --i)
                res[i][start1] = ++cnt;
            ++start1;
        }
        return res;
    }
};
