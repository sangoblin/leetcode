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
    ListNode* sortListKernel(ListNode* head, int number, ListNode*& tail)
    {
        if (number == 1)
        {
            tail = head;
            return head;
        }
        
        auto head1 = sortListKernel(head, number/2, tail);
        auto head2 = sortListKernel(tail->next, number-number/2, tail);
        return merge(head1, number/2, head2, number-number/2, tail);
    }
    
    ListNode* merge(ListNode* head1, int number1, ListNode* head2, int number2, ListNode*& tail)
    {
        auto dummy = new ListNode(-1), prev = dummy;
        //int cnt1 = 0, cnt2 = 0;
        
        while (number1>0 && number2>0)
        {
            if (head1->val <= head2->val)   --number1;
            else    --number2;
            
            auto cur = (head1->val<=head2->val)?&head1:&head2;
            prev->next = *cur;
            *cur = (*cur)->next;
            prev = prev->next;
        }
        
        if (number1)
        {
            prev->next = head1;
            while (number1-- > 0)
                prev = prev->next;
        }

        prev->next = head2;
        
        int cnt = number1+number2;
        while (cnt-- > 0)
            prev = prev->next;
        tail = prev;
        
        auto tmp = dummy->next;
        delete dummy;
        return tmp;
    }
    
    ListNode *sortList(ListNode *head) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        if (!head)  return nullptr;
        int cnt = 0;
        auto cur = head;
        while (cur)
        {
            ++cnt;
            cur = cur->next;
        }
        ListNode* tail;
        return sortListKernel(head, cnt, tail);
    }
};
