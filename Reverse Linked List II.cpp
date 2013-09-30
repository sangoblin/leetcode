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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int idx = 1;
        ListNode *sentinel = new ListNode(0);
        sentinel->next = head;
        ListNode *prev = sentinel, *cur = head, *back, *tail;
        while (idx++ < m)
        {
            prev = cur;
            cur = cur->next;
        }
        tail = cur->next;
        while (idx++ <= n)
        {
            back = tail;
            tail = back->next;
            back->next = cur;
            cur = back;
        }
        prev->next->next = tail;
        prev->next = cur;
        head = sentinel->next;
        delete sentinel;
        return head;
    }
};
