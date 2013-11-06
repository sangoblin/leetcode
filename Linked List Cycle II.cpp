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
    ListNode *detectCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (!head)  return nullptr;
        auto slow = head, fast = head;
        
        while (slow)
        {
            slow = slow->next;
            if (!fast)  return nullptr;
            fast = fast->next;
            if (!fast)  return nullptr;
            fast = fast->next;
            if (slow == fast)   break;
        }
        slow = head;
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
