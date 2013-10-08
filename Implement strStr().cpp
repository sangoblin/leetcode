class Solution {
public:
    void calPrefix(vector<int>& pi, char *needle, int len)
    {
        int k = 0;
        pi[0] = 0;
        for (int q=1; q<len; ++q)
        {
            while (k>0 && needle[k]!=needle[q])
                k = pi[k-1];
            if (needle[k] == needle[q])
                ++k;
            pi[q] = k;
        }
    }

    char *strStr(char *haystack, char *needle) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = strlen(haystack), m = strlen(needle), q = 0;
        if (!m && !n) return "";
        else if (!m)    return haystack;
        vector<int> pi(m);
        calPrefix(pi, needle, m);
        for (int i=0; i<n; ++i)
        {
            while (q>0 && haystack[i]!=needle[q])
                q = pi[q-1];
            if (haystack[i] == needle[q])
                ++q;
            if (q == m)
                return haystack+i-m+1;
        }
        return nullptr;
    }
};
