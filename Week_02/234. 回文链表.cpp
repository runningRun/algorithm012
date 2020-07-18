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
    bool isPalindrome(ListNode* head) {
        stack<int> sValue;
        ListNode *p = head;
        bool result = true;

        while(NULL != p) {
            sValue.push(p->val);
            p = p->next;
        }
        p = head;
        while(NULL != p) {
            if (p->val != sValue.top()) {
                result = false;
                break;
            }
            p = p->next;
            sValue.pop();
        }

        return result;

    }
};