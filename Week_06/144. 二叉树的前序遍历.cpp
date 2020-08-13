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
 * !!!!!由于栈的特殊性(后进先出)!!!!!!!!
 * 先入->right右子树，再入->left左子树
*/
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> nodes;
        vector<int> preOrder;
        TreeNode *tmpNode = NULL;

        if (NULL == root)
            return preOrder;
        nodes.push(root);
        while(!nodes.empty()) {
            tmpNode = nodes.top();
            nodes.pop();
            preOrder.push_back(tmpNode->val);
            if (NULL != tmpNode->right)
                nodes.push(tmpNode->right);
            if (NULL != tmpNode->left)
                nodes.push(tmpNode->left);
        }
        return preOrder;
    }
};