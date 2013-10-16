/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        map<RandomListNode*, RandomListNode*> record;
        if (!head)  return nullptr;
        RandomListNode *res = new RandomListNode(head->label);
        record[head] = res;
        record[nullptr] = nullptr;
        
        while (head != nullptr)
        {
            RandomListNode *cur = record[head];
            
            if (record.find(head->next) != record.end())
                cur->next = record[head->next];
            else
            {
                RandomListNode* tmp = new RandomListNode(head->next->label);
                cur->next = tmp;
                record[head->next] = tmp;
            }
            
            if (record.find(head->random) != record.end())
                cur->random = record[head->random];
            else
            {
                RandomListNode* tmp = new RandomListNode(head->random->label);
                cur->random = tmp;
                record[head->random] = tmp;
            }

            head = head->next;
        }
        
        return res;
    }
};
