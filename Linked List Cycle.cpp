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
    bool hasCycle(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (nullptr == head)    return false;
        auto slow = head, fast = head->next;
        
        while (slow)
        {
            if (fast == slow)   return true;
            slow = slow->next;
            if (nullptr==fast || nullptr==fast->next)    return false;
            fast = fast->next->next;
        }
    }
};
