class Solution {
public:
    vector<string> res;
    int len;
    string ip;
    void search(string& cur, int depth, int start)
    {
        if (start >= len)
            return;
        if (depth == 4)
        {
            string tmp = ip.substr(start);
            if ((atoi(tmp.c_str())<=255 && atoi(tmp.c_str())>0 && tmp[0]!='0') || tmp.size()==1)
                res.push_back(cur+tmp);

            return;
        }
        if (ip[start] == '0')
        {
            cur += "0.";
            search(cur, depth+1, start+1);
            cur.erase(cur.end()-2, cur.end());
        }
        else
            for (int i=1; i<=3 && start+i-1<len; ++i)
            {
                string tmp = ip.substr(start, i);
                if (atoi(tmp.c_str()) <= 255)
                {
                    //cur += '.';
                    cur += tmp;
                    cur += '.';
                    search(cur, depth+1, start+i);
                    cur.erase(cur.end()-i-1, cur.end());
                }
            }
    }
    
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        res.clear();
        len = s.size();
        ip = s;
        if (s.empty()) return res;
        string tmp = "";
        search(tmp, 1, 0);
        return res;
    }
};
