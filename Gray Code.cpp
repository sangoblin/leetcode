class Solution {
public:
    vector<int> grayCode(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (n == 0) return vector<int>{0};
        vector<int> res{0, 1}, power(n);
        for (int i=0; i<n; ++i)
            power[i] = 1<<i;
            
        for (int i=1; i<n; ++i)
        {
            vector<int> tmp = res;
            for (auto iter=tmp.rbegin(); iter!=tmp.rend(); ++iter)
            {
                *iter += power[i];
                res.push_back(*iter);
            }
        }
        return res;
    }
};
