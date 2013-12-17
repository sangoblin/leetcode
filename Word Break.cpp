class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (s.empty())  return false;
        size_t len = s.size(), maxL = 0;
        vector<bool> state(len+1, false);
        state[0] = true;
        
        for (auto& _dict : dict)
            maxL = max(maxL, _dict.size());
        
        for (size_t i=1; i<=len; ++i)
            for (size_t j=1; j<=min(maxL, i); ++j)
                if (state[i-j] && dict.find(s.substr(i-j, j))!=dict.end())
                    state[i] = true;

        return state[len];
    }
};
