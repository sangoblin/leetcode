class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> res;
        int len = L.size(), lenS = S.size();
        if (!len)    return res;
        int lens = L[0].size(), cnt = 0;
        vector<bool> visited(len, false);
        unordered_map<string, int> dict;
        for (int i=0; i<len; ++i)
            ++dict[L[i]];
        auto nd = dict;
            
        for (int i=0; i<lenS-lens+1; ++i)
        {
            string&& tmp = S.substr(i, lens);

            bool found = false;
            
            if (nd.find(tmp) == nd.end())
            {
                if (cnt)
                {
                    i -= cnt*lens;
                    cnt = 0;
                    nd = dict;
                }
                continue;
            }
            else
            {
                i += lens-1;
                --nd[tmp];
                if (nd[tmp] == 0)
                    nd.erase(tmp);
                ++cnt;
            }
            
           if (cnt == len)
           {
                if (nd.empty())
                    found = true;
                nd = dict;
                i -= cnt*lens-1;
                cnt = 0;
            }

            if (found)
                res.push_back(i);
        }
        return res;
    }
};
