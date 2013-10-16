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
        if (!root)  return;
        queue<TreeLinkNode*> level;
        level.push(root);

        while (!level.empty())
        {
            int cnt = 0, len = level.size();
            TreeLinkNode* prev;
            while (cnt++ < len)
            {
                auto tmp = level.front();
                if (cnt == 1)   prev = tmp;
                else
                {
                    prev->next = tmp;
                    prev = prev->next;
                }
                
                level.pop();
                if (tmp->left)    level.push(tmp->left);
                if (tmp->right)   level.push(tmp->right);
            }
        }
    }
};
