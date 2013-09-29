class Solution {
public:
    int numTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int nums[n+1];
        memset(nums, 0, sizeof(int)*(n+1));
        nums[0] = 1;
        for (int i=1; i<=n; ++i)
            for (int j=0; j<i; ++j)
                nums[i] += nums[j]*nums[i-j-1];
        return nums[n];
    }
};
