class Solution {
public:
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x<0)    return false;
        long long res = 0, back = x;
        
        while (x)
        {
            res = res*10+x%10;
            x /= 10;
        }
        
        return (res == back)? true:false;
    }
};
