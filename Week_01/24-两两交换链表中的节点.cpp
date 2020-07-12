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
    ListNode* swapPairs(ListNode* head) {
        
        if (NULL == head || NULL == head->next) 
            return head;
        
        ListNode *p = head->next;
        head->next = swapPairs(p->next);
        p->next = head;
        
        return p;
    }
};