/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!root || (!root->left && !root->right))  return;
        
        auto parent = root, son = root->left?root->left:root->right;
        
        while (son)
        {
            auto back = son;
            
            while (son)
            {
                if (parent->left && parent->right)
                {
                    son->next = parent->right;
                    son = son->next;
                }
                do
                {parent = parent->next;}
                while (parent && (!parent->left && !parent->right));
                if (!parent)    break;
                son->next = parent->left?parent->left:parent->right;
                son = son->next;
            }
            
            parent = back;
            while (parent && (!parent->left && !parent->right))
                parent = parent->next;
            if (!parent)    break;
            son = parent->left?parent->left:parent->right;
        }
    }
};
