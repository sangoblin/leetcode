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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *dummy = new ListNode(0), *insert = dummy, *large = NULL, *back, *prev = NULL;
        dummy->next = head;
        while (head)
        {
            if (head->val >= x)
            {
                large = large?large:head;
                prev = head;
                head = head->next;
            }
            else
            {
                insert->next = head;
                back = head->next;
                head->next = large;
                insert = head;
                head = back;
                if (prev)  prev->next = back;
            }
        }
        insert->next = large;
        head = dummy->next;
        delete dummy;
        return head;
    }
};
