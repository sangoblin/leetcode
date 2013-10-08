/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *prev=head, *back=head;
        if (!head)  return head;
        int cnt = 1, len = 1;
        while (back->next)
        {
            ++len;
            back = back->next;
        }
        
        k = k%len;
        if (k == 0) return head;

        while (cnt++<len-k)
            prev = prev->next;
      
        back->next = head;
        head = prev->next;
        prev->next = nullptr;
        return head;
    }
};
