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
    typedef vector<int>::iterator VIter;
    TreeNode *buildTreeKernel(VIter ib, VIter ie, VIter pb, VIter pe)
    {
        if (ib>ie)  return NULL;
        TreeNode *root = new TreeNode(*pe);
        auto index = find(ib, ie, root->val);
        root->left = buildTreeKernel(ib, index-1, pb, pb+(index-ib)-1);
        root->right = buildTreeKernel(index+1, ie, pb+(index-ib), pe-1);
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (inorder.empty())    return NULL;
        
        return buildTreeKernel(inorder.begin(), inorder.end()-1, postorder.begin(), postorder.end()-1);
    }
};
