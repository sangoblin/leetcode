class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = strs.size();
        vector<vector<int> > features(len, vector<int>(26, 0));
        vector<bool> visited(len, false);
        vector<string> res;
        vector<pair<string, int> > back;
        
        for (int i=0; i<len; ++i)
        {
            int lenstr = strs[i].size();
            string tmp;
            for (int j=0; j<lenstr; ++j)
                ++features[i][strs[i][j]-'a'];
            for (int j=0; j<26; ++j)
                tmp.append(features[i][j], 'a'+j);
            back.push_back(make_pair(tmp, i));
        }
        
        sort(back.begin(), back.end(), [](const pair<string, int>& left, const pair<string, int>& right)
        {
            return left.first < right.first;
        });
        
        for (int i=0; i<len; )
        {
            int cnt = 1;
            res.push_back(strs[back[i].second]);
            while (i+cnt<len && back[i+cnt].first==back[i].first)
            {
                res.push_back(strs[back[i+cnt].second]);
                ++cnt;
            }
            if (cnt == 1)
                res.pop_back();
            i += cnt;
        }

        return res;
    }
};
