class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = s.size();
        if (len==0 || s[0]=='0') return 0;
        
        int ways[len+1];
        memset(ways, 0, sizeof(int)*(len+1));
        
        ways[0] = 1;
        ways[1] = 1;
        for (int i=1; i<len; ++i)
        {
            if (s[i]=='0' && (atoi(s.substr(i-1, 2).c_str())==0 || atoi(s.substr(i-1, 2).c_str())>20))
                return 0;
            else if (s[i] != '0')
                ways[i+1] += ways[i];
            if (s[i-1]!='0' && atoi(s.substr(i-1, 2).c_str())<=26)
                ways[i+1] += ways[i-1];
        }
        return ways[len];
    }
};
