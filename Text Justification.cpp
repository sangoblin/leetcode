class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = words.size();
        vector<string> res;
        
        for (int i=0; i<len; ++i)
        {
            int space = 0, cnt = i;
            while (space<=L && i<len)
            {
                space += words[i].size();
                if (space < L)
                {
                    ++space;
                    if (++i == len)
                    { 
                        --i;
                        break;
                    }
                }
                else
                    break;
            }
            if (space > L)
                space -= words[i--].size()+1;
                
            int rspace = (i==len-1)?i-cnt:L-space+(i-cnt);
            string tmp;
            for (int j=i; j>cnt; --j)
            {
                tmp.insert(0, words[j]);
                int tmpi = rspace/(j-cnt);
                rspace -= tmpi;
                tmp.insert(tmp.begin(), tmpi, ' ');
            }
            tmp.insert(0, words[cnt]);
            
            if (tmp.size() < L)
                tmp.insert(tmp.end(), L-tmp.size(), ' ');
                
            res.push_back(tmp);
        }
        return res;
    }
};
