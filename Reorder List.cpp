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
    void reorderList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int num = 0, cnt = 0;
        auto prev = head, back = head, cur = head;
        while (prev)
        {
            ++num;
            prev = prev->next;
        }
        if (num <= 2)   return;
        num = ceil(num/2.);
        prev = head;
        while (++cnt < num)
            prev = prev->next;
        back = prev->next;
        prev->next = nullptr;
        prev = back;
        cur = prev->next;
        prev->next = nullptr;
        while (cur)     //reverse the back half of the linked list
        {
            back = cur->next;
            cur->next = prev;
            prev = cur;
            cur = back;
        }
        cur = head;
        while (cur)
        {
            back = cur->next;
            cur->next = prev;
            if (prev)
            {
                cur = prev->next;
                prev->next = back;
                prev = cur;
            }
            cur = back;
        }
    }
};
