class Solution {
public:
    int numDistinct(string S, string T)
    {
        vector<int> f(T.size()+1);
        f[T.size()] = 1;
        for (int i = S.size()-1; i >= 0; --i) 
            for (int j = 0; j < T.size(); ++j) 
                f[j] += (S[i]==T[j])*f[j+1];

        return f[0];
    }
};
