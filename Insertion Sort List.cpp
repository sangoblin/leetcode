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
    ListNode *insertionSortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (!head)  return nullptr;
        auto cur = head->next, prev = head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        while (cur)
        {
            auto tmp = dummy, back = cur->next;
            while (tmp->next!=cur && tmp->next->val<=cur->val)
                tmp = tmp->next;

            if (tmp->next != cur)
            {
                auto _tmp = tmp->next;
                tmp->next = cur;
                cur->next = _tmp;
                prev->next = back;
            }
            else
                prev = prev->next;
                
            cur = back;
        }
        cur = dummy->next;
        delete dummy;
        return cur;
    }
};
