/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // stack<TreeNode *> nodes;
        TreeNode *tmpNode = root;
        vector<int> result;
        
        if (NULL == root)
            return result;
        // 递归方式
        // inorderTraversalHelper(root, result);

        // 循环+标记
        stack<pair<TreeNode*, bool>> extNodes;
        extNodes.push({root, false});
        
        while (!extNodes.empty()) {
            pair<TreeNode*, bool> &extNode = extNodes.top();
            // printf("current top: %d\n", extNode.first->val);
            if (extNode.first->left && !extNode.second) {
                extNodes.push({extNode.first->left, false});
                // printf("push: %d\n", extNode.first->left->val);
                extNode.second = true;
                continue;
            }
            result.push_back(extNode.first->val);
            extNodes.pop();
            if (extNode.first->right) {
                extNodes.push({extNode.first->right, false});
            }
        }

        return result;
    }

private:

    void inorderTraversalHelper(TreeNode *node, vector<int> &result) {
        if (NULL != node->left)
            inorderTraversalHelper(node->left, result);

        result.push_back(node->val);

        if (NULL != node->right)
            inorderTraversalHelper(node->right, result);
    }
};