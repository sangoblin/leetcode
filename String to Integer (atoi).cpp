class Solution {
public:
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stringstream num(str);
        char first;
        int sign = 1, res;
        num >> first;
        if (first!='+' && first!='-' && !isdigit(first))
            return 0;
        else
            num.putback(first);
        num >> res;
        return res;
    }
};
