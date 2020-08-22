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
    // 头插法
    ListNode* reverseList1(ListNode* head) {
        ListNode *newHead = NULL;
        ListNode *p = head;
        while (NULL != p) {
            head = p->next;
            p->next = newHead;
            newHead = p;
            p = head;
        }
        return newHead;
    }

    //递归
    ListNode* reverseList(ListNode* head) {
        if (NULL == head || NULL == head->next)
            return head;
        ListNode *cur = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return cur;
    }
};