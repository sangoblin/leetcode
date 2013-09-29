/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* list2BSTKernel(ListNode *head, ListNode* &prev, int step)
    {
        if (step == 1)
        {
            TreeNode *cur = new TreeNode(head->val);
            prev = head;
            return cur;
        }
        else if (step == 0)
        {
            prev = NULL;
            return NULL;
        }

    
        TreeNode *left = list2BSTKernel(head, prev, step/2);
        ListNode *back = prev->next;
        TreeNode *cur = new TreeNode(back->val);
        TreeNode *right = list2BSTKernel(back->next, prev, step-step/2-1);
        if (!prev)  prev = back;
        cur->left = left;
        cur->right = right;
        return cur;
    }
    
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int cnt = 0;
        ListNode *back = head;
        
        while (back)
        {
            ++cnt;
            back = back->next;
        }
        if (!cnt)   return NULL;
        else if (cnt == 1)
            return new TreeNode(head->val);
        
        return list2BSTKernel(head, back, cnt);
    }
};
