class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int fact[n+1], num[n], cur = 0;
        vector<char> digits;
        for (int i=1; i<=n; ++i)
            digits.push_back('0'+i);
        string res;
        fact[0] = 1;
        fill(num, num+n, 0);
        for (int i=1; i<=n; ++i)
            fact[i] = i*fact[i-1];
        if (k>fact[n] || k<=0)    return res;
        --k;
        while (k != 0)
        {
            num[cur] = k/fact[n-cur-1];
            k = k-k/fact[n-cur-1]*fact[n-cur-1];
            ++cur;
        }
        
        for (int i=1; i<n; ++i)
        {
            res += digits[num[i-1]];
            digits.erase(digits.begin()+num[i-1]);
        }
        res += digits[0];
        return res;
    }
};
