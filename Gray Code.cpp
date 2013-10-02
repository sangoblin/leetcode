class Solution {
public:
    vector<int> grayCode(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (n == 0) return vector<int>{0};
        vector<int> res{0, 1};
            
        for (int i=1; i<n; ++i)
        {
            int len = res.size();

            for (int j=len-1; j>=0; --j)
                res.push_back(res[j]+(1<<i));
        }
        return res;
    }
};
