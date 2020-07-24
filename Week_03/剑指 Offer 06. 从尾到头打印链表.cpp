/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 借助双端队列的头插入
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        deque<int> dVal;
        ListNode *node = head;
        while (node != NULL) {
            dVal.push_front(node->val);
            node = node->next;
        }
        return vector<int>(dVal.begin(), dVal.end());
    }
};

// 递归调用
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> result;
        _reversePrint(head, result);
        return result;
    }

private:
    void _reversePrint(ListNode *head, vector<int> &result) {
        // 终止条件
        if (NULL == head)
            return ;

        // 本层处理

        // 进入下一层
        _reversePrint(head->next, result);

        // 本层清理
        result.push_back(head->val);
    }
    
};