class Solution {
public:
    int len = 0;
    bool wordBreakKernel(int idx, unordered_set<string>& dict, string& s, vector<bool>& state)
    {
       if (idx >= len)  return true;
       if (state[idx])    return false;
       
       for (int i=idx; i<len; ++i)
            if (dict.find(s.substr(idx, i-idx+1))!=dict.end() && wordBreakKernel(i+1, dict, s, state))
                    return true;
       
       state[idx] = true;
       return false;
    }
    
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (s.empty())  return false;
        len = s.size();
        vector<bool> state(len, false);
        
        return wordBreakKernel(0, dict, s, state);
    }
};
