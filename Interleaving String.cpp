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

        inter[0][0] = true;
        
        for (int i=0; i<=len1; ++i)
            for (int j=0; j<=len2; ++j)
            {
                if (i<len1 && s1[i]==s3[i+j] && inter[i][j])
                    inter[i+1][j] = true;
                if (j<len2 && s2[j]==s3[i+j] && inter[i][j])
                    inter[i][j+1] = true;
            }
        return inter[len1][len2];
    }
};
