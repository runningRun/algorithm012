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
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (NULL == root)
            return 0;
        int lDepth = maxDepth(root->left);
        int rDepth = maxDepth(root->right);
        // printf("value: %d, lDepth: %d, rDepth: %d\n", root->val, lDepth, rDepth);
        return lDepth > rDepth ? lDepth + 1 : rDepth + 1;
    }
};*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (NULL == root)
            return 0;
        queue<pair<TreeNode *, int>> nodeQueue;
        nodeQueue.push({root, 1});
        int maxDepth = 0;
        while (!nodeQueue.empty()) {
            pair<TreeNode *, int> tmpLevel = nodeQueue.front();
            nodeQueue.pop();
            // printf("val: %d, level: %d\n", tmpLevel.first->val, tmpLevel.second);
            if (tmpLevel.first->left) {
                nodeQueue.push({tmpLevel.first->left, tmpLevel.second + 1});
            }
            if (tmpLevel.first->right) {
                nodeQueue.push({tmpLevel.first->right, tmpLevel.second + 1});
            }
            maxDepth = tmpLevel.second;
        }
        return maxDepth;
    }
};