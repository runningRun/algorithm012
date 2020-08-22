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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int ii = 0;
        ListNode *pT = head;    // pT指向本次轮第k个节点的后一个节点(方便后续翻转本轮节点)
        while (ii < k && NULL != pT) {
            pT = pT->next;
            ii += 1;
        }
        // 这里使用ii<k是为了在k 正好等于链表长度时，继续本次反转
        if (NULL == pT && ii < k)
            return head;

        ListNode *pTRes = reverseKGroup(pT, k);
        ListNode *p = head;
        ListNode *pn = NULL;
        ListNode *newHead = NULL;
        while (p != pT) {
            pn = p->next;
            p->next = newHead;
            newHead = p;
            p = pn;
        }
        head->next = pTRes;
        head = newHead;
        return newHead;
    }
};