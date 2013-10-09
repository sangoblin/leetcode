class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> res;
        int len = L.size(), lenS = S.size();
        if (!len)    return res;
        int lens = L[0].size(), cnt = 0;
        map<string, int> dict, nd;
        for (int i=0; i<len; ++i)
            ++dict[L[i]];
            
        for (int i=0; i<lenS-len*lens+1; ++i)
        {
            nd.clear();
            
            bool found = true;
            
            for (int j=0; j<len; ++j)
            {
                string&& tmp = S.substr(i+j*lens, lens);
                ++nd[tmp];
                if (nd[tmp] > dict[tmp])
                {
                    found = false;
                    break;
                }
            }
                        
            if (found)
                res.push_back(i);
        }
        return res;
    }
};
