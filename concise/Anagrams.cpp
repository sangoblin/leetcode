class Solution {
public:
     vector<string> anagrams(vector<string> &strs) {
        vector<string> cc;
        map<string, vector<string> > dict;
        vector<string>::iterator st;
        for(st = strs.begin(); st != strs.end(); st++) {
            string key = *st;
            sort(key.begin(), key.end());
            dict[key].push_back(*st);
        }
        map<string, vector<string> >::iterator it;
        for(it = dict.begin(); it != dict.end(); it++) {
            if(it->second.size() > 1)
                for(st = it->second.begin(); st != it->second.end(); st++)
                    cc.push_back(*st);
        }
        return cc;
    }
};
