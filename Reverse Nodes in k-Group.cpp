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
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ListNode *dummy = new ListNode(0), *prev = dummy, *cur = head, *back;
        dummy->next = NULL;
        prev->next = head;
        if (!cur)   return head;
        int cnt = 0;
        while (cur->next != NULL)
        {
            if (++cnt == k)
            {
                cnt = 0;
                if (!dummy->next)   dummy->next = prev->next;
                prev = cur;
                cur = prev->next;
                continue;
            }
            back = prev->next;

            prev->next = cur->next;
            cur->next = cur->next->next;
            prev->next->next = back;
        }
        if (cnt<k-1)
        {
            cur = prev->next;
            while (cur->next != NULL)
            {
                back = prev->next;
                prev->next = cur->next;
                cur->next = cur->next->next;
                prev->next->next = back;
            }
        }
        if (!dummy->next)   dummy->next = prev->next;
        return dummy->next;
    }
};
