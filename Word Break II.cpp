class Solution {
public:
    int len = 0;
    vector<string> res;
    bool wordBreakKernel(int idx, unordered_set<string>& dict, string& s, vector<bool>& state, string cur)
    {
       if (idx >= len) 
       {
            cur.pop_back();
            res.push_back(cur);
            return true;
       }
       
       if (state[idx])    return false;
       
       bool found = false;
       
       for (int i=idx; i<len; ++i)
       {
           string sub = s.substr(idx, i-idx+1);
            if (dict.find(sub)!=dict.end())
                if (wordBreakKernel(i+1, dict, s, state, cur+sub+' '))
                    found = true;
       }
       if (!found)
            state[idx] = true;
       return found;
    }
    
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        res.clear();
        if (s.empty())  return res;
        len = s.size();
        vector<bool> state(len, false);
        
        wordBreakKernel(0, dict, s, state, "");
        
        return res;
    }
};
