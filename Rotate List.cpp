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
        ListNode *prev, *back=head, *dummy = new ListNode(0);
        if (!head)  return head;
        int cnt = 1, len = 1;
        while (back->next)
        {
            ++len;
            back = back->next;
        }
        k = k%len;
        if (k == 0) return head;
        back = head;
        while (cnt++<k && back->next)
            back = back->next;

        dummy->next = head;
        prev = head;
        while (back->next)
        {
            dummy = dummy->next;
            prev = prev->next;
            back = back->next;
        }
        back->next = head;
        dummy->next = nullptr;
        return prev;
    }
};
