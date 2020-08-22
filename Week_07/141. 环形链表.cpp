// 快慢指针
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
        if (NULL == head)
            return false;
        ListNode *walker = head;
        ListNode *runner = head;
        while (runner != NULL && runner->next != NULL) {
            walker = walker->next;
            runner = runner->next->next;
            if (walker == runner)
                return true;
        }
        return false;
    }
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (NULL == head)
            return false;
        ListNode *pFast = head->next;
        ListNode *pSlow = head;
        while (pFast != NULL && pFast->next != NULL && pSlow != NULL) {
            if (pFast == pSlow) {
                return true;
            }
            pFast = pFast->next->next;
            pSlow = pSlow->next;
        }
        return false;
    }
};

// hash
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode *> nodes;
        ListNode *p = head;
        while (p != NULL) {
            if (nodes.find(p) == nodes.end()) {
                nodes.insert(p);
            } else {
                return true;
            }
            p = p->next;
        }
        return false;
    }
};