/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/*
 * 使用栈结构，迭代完成
 * 1. 将根节点root入栈
 * 2. 当栈不空时
 *  a. 如果第一次在栈中**遇到**该节点(正向访问阶段)
 *     aa. 如果->left为空，则直接输出该节点的值，并且将其->right入栈(如果->right不为空)
 *     ab. 如果-left不为空，则直接将其->left入栈, 并且需要将该节点标记为**已遇到**
 *  b. 如果不是第一次在栈中遇到(回溯阶段)，则访问该节点，并且将其->right入栈(如果->right不为空)
*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodes;
        vector<int> inOrder;
        TreeNode *tmpNode = NULL;
        unordered_set<TreeNode*> accessLeft;
        if (NULL == root)
            return inOrder;
        nodes.push(root);
        while(!nodes.empty()) {
            tmpNode = nodes.top();
            if (accessLeft.find(tmpNode) == accessLeft.end()) {
                if (NULL == tmpNode->left) {
                    inOrder.push_back(tmpNode->val);
                    nodes.pop();
                    if (NULL != tmpNode->right)
                        nodes.push(tmpNode->right);
                } else {
                    nodes.push(tmpNode->left);
                    accessLeft.insert(tmpNode);
                }
            } else {
                inOrder.push_back(tmpNode->val);
                nodes.pop();
                if (NULL != tmpNode->right)
                    nodes.push(tmpNode->right);
            }
        }
        return inOrder;
    }
};

class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodes;
        vector<int> inOrder;
        TreeNode *tmpNode = NULL;
        unordered_set<TreeNode*> accessLeft;
        if (NULL == root)
            return inOrder;
        nodes.push(root);
        while(!nodes.empty()) {
            tmpNode = nodes.top();
            if (accessLeft.find(tmpNode) == accessLeft.end()) {
                if (NULL != tmpNode->left) {
                    nodes.push(tmpNode->left);
                    accessLeft.insert(tmpNode);
                    continue;
                }
            } 

            inOrder.push_back(tmpNode->val);
            nodes.pop();
            if (NULL != tmpNode->right)
                nodes.push(tmpNode->right);
                
        }
        return inOrder;
    }
};

class Solution3 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodes;
        vector<int> inOrder;
        TreeNode *tmpNode = NULL;
        unordered_set<TreeNode*> accessLeft;
        if (NULL == root)
            return inOrder;
        nodes.push(root);
        while(!nodes.empty()) {
            tmpNode = nodes.top();
            if (accessLeft.find(tmpNode) == accessLeft.end() && NULL != tmpNode->left) {
                nodes.push(tmpNode->left);
                accessLeft.insert(tmpNode);
            } else {
                inOrder.push_back(tmpNode->val);
                nodes.pop();
                if (NULL != tmpNode->right)
                    nodes.push(tmpNode->right);
            }
        }
        return inOrder;
    }
};