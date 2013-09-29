/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *a2BSTKernel(vector<int> &num, int begin, int end)
    {
        if (begin > end)    return NULL;
    
        int cur = begin+(end-begin)/2;
        TreeNode *curN = new TreeNode(num[cur]);
        curN->left = a2BSTKernel(num, begin, cur-1);
        curN->right = a2BSTKernel(num, cur+1, end);
        return curN;
    }
    
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len = num.size();
        if (len == 0)   return NULL;
        
        return a2BSTKernel(num, 0, len-1);
    }
};
