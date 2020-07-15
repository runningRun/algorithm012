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
        stack<TreeNode *> nodes;
        TreeNode *tmpNode = NULL;
        map<TreeNode*, int> hasVisit;
        vector<int> result;
        
        if (NULL == root)
            return result;

        nodes.push(root);
        while (!nodes.empty()) {
            tmpNode = nodes.top();
            /*
             * 当访问某个节点N时，需要知道是从父节点访问的，还是左子树返回时访问的
            */
            if (NULL != tmpNode->left && hasVisit.end() == hasVisit.find(tmpNode->left)) {
                nodes.push(tmpNode->left);
                hasVisit[tmpNode->left] = 1;
            } else {
                result.push_back(tmpNode->val);
                nodes.pop();
                if (NULL != tmpNode->right) {
                    nodes.push(tmpNode->right);
                }
            }
        }

        return result;
    }
};