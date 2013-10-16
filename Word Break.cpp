class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (s.empty())  return false;
        int len = s.size();
        vector<bool> state(len+1, false);
        state[0] = true;
        
        for (int i=1; i<=len; ++i)
            for (int j=0; j<i; ++j)
                if (state[j] && dict.find(s.substr(j, i-j))!=dict.end())
                    state[i] = true;

        
        return state[len];
    }
};
