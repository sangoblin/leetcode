class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head || k <= 1) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode *pre = &dummy;

        int i = 0;
        while (head) {
            i++;
            if (i % k == 0) {
                pre = reverse(pre, head->next);                
                head = pre->next;
            } else {
                head = head->next;   
            }
        }

        return dummy.next;
    }

    ListNode *reverse(ListNode *pre, ListNode *next) {
        ListNode *last = pre->next;
        ListNode *cur = last->next;
        while (cur != next) {
            last->next = cur->next;
            cur->next = pre->next;
            pre->next = cur;

            cur = last->next;
        }
        return last;
    }
};
