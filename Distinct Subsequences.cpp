class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = S.size(), len2 = T.size();
        if (len1 < len2)    return 0;
        
        int dp[len1+1][len2+1], curl[len1+1];
        memset(dp, 0, sizeof(int)*(len1+1)*(len2+1));
        memset(curl, 0, (len1+1)*sizeof(int));
        
        for (int i=0; i<=len1; ++i)
            dp[i][0] = 1;
        
        for (int i=1; i<=len1; ++i)
        {
            curl[i] = curl[i-1];
            for (int j=1; j<=curl[i-1]+1; ++j) //should use i-1 and j-1 as the subscript
            {
                dp[i][j] = dp[i-1][j];
                if (S[i-1] == T[j-1])
                    dp[i][j] += dp[i-1][j-1];
            }
            if (S[i-1] == T[curl[i-1]])
                curl[i] = min(curl[i]+1, len2);
        }
        
        return dp[len1][len2];   
    }
};
