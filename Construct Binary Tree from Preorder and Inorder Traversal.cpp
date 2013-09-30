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
    TreeNode *buildTreeKernel(vector<int> &preorder, vector<int> &inorder, int beginP, int len, int beginI)
    {
        TreeNode *root = new TreeNode(preorder[beginP]);
        if (len == 1)   return root;
        else if (len == 0)  return NULL;
        int index = find(inorder.begin(), inorder.end(), preorder[beginP])-inorder.begin()-beginI;
        
        TreeNode *left = buildTreeKernel(preorder, inorder, beginP+1, index, beginI);
        TreeNode *right = buildTreeKernel(preorder, inorder, beginP+index+1, len-index-1, beginI+index+1);
        root->left = left;
        root->right = right;
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int len1 = preorder.size(), len2 = inorder.size();
        if (len1 == 0)  return NULL;
        
        return buildTreeKernel(preorder, inorder, 0, len1, 0);
    }
};
