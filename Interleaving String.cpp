class Solution {
public:
    int len1, len2, len3;

    bool isInterleave(string s1, string s2, string s3) {
        // Note: The Solution object is instantiated only once and is reused by each test case. 
        len1 = s1.size();
        len2 = s2.size();
        len3 = s3.size();
        if (len1+len2 != len3)  return false;
        if (!len1)  return s2==s3;
        if (!len2)  return s1==s3;
        vector<vector<bool> > inter(len1+1, vector<bool>(len2+1, false));
        inter[len1][len2] = true;
        
        for (int i=len1; i>=0; --i)
            for (int j=len2; j>=0; --j)
            {
                if (i-1>=0 && s1[i-1]==s3[i+j-1] && inter[i][j])
                    inter[i-1][j] = true;
                if (j-1>=0 && s2[j-1]==s3[i+j-1] && inter[i][j])
                    inter[i][j-1] = true;
            }
        return inter[0][0];
    }
};
