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
    ListNode *deleteDuplicates(ListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (!head || !head->next)  return head;
        ListNode *dummy = new ListNode(0), *cur = head, *cand = head, *back;
        int prev = head->val, state = 0;
        dummy->next = head;
        ListNode *prev_ = dummy;

        while (cur->next)
        {
            if (cur->next->val != prev)
            {
                if (!state)
                {
                    cand->val = cur->val;
                    prev_ = cand;
                    cand = cand->next;
                }
                prev = cur->next->val;
                state = 0;
            }
            else
               state = 1;

            back = cur;
            cur = cur->next;
        }
        if (back->val != cur->val)
        {
            cand->val = cur->val;
            prev_ = cand;
        }
        prev_->next = nullptr;
        back = dummy->next;
        delete dummy;
        return back;
    }
};
