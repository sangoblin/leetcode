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
    
    vector<TreeNode *> genTreesKernel(int n, int start)
    {
        vector<TreeNode*> res;
        if(n == 0)  
        {
            res.push_back(NULL);
            return res;
        }
    
        for (int i=1; i<=n; ++i)
        {
            vector<TreeNode *> left = genTreesKernel(i-1, start);
            vector<TreeNode *> right = genTreesKernel(n-i, start+i);
            int lenl = left.size(), lenr = right.size();
            for (int m=0; m<lenl; ++m)
                for (int n=0; n<lenr; ++n)
                {
                    TreeNode *tmpN = new TreeNode(start+i);
                    tmpN->left = left[m];
                    tmpN->right = right[n];
                    res.push_back(tmpN);
                }
        }
        return res;
    }

    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<TreeNode*> res;
        if (n == 0) 
        {
            res.push_back(NULL);
            return res;
        }
        
        return genTreesKernel(n, 0);
    }
};
