class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = grid.size();
        if (m == 0)  return 0;
        int n = grid[0].size();
        int nums[m][n];
        nums[0][0] = grid[0][0];
        for (int i=1; i<m; ++i)
            nums[i][0] = nums[i-1][0]+grid[i][0];
        for (int i=1; i<n; ++i)
            nums[0][i] = nums[0][i-1]+grid[0][i];
        
        for (int i=1; i<m; ++i)
            for (int j=1; j<n; ++j)
            nums[i][j] = min(nums[i-1][j], nums[i][j-1])+grid[i][j];
        
        return nums[m-1][n-1];
    }
};
