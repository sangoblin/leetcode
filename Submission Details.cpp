class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (n <= 0) return vector<vector<int> >();
        vector<vector<int> > res(n, vector<int>(n, 0));
        int start1 = 0, end1 = n, start2 = 0, end2 = n, cnt = 0, idx = 0;
        
        while (cnt < n*n)
        {
            for (int i=start1; i<end1; ++i)
                res[idx][i] = ++cnt;
            start2 = idx+1;
            idx = end1-1;
            for (int i=start2; i<end2; ++i)
                res[i][idx] = ++cnt;
            end1 = idx;
            idx = end2-1;
            for (int i=end1-1; i>=start1; --i)
                res[idx][i] = ++cnt;
            end2 = idx;
            idx = start1;
            for (int i=end2-1; i>=start2; --i)
                res[i][idx] = ++cnt;
            start1 = idx+1;
            idx = start2;
        }
        return res;
    }
};
