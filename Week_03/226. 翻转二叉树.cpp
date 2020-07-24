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
    TreeNode* invertTree(TreeNode* root) {
        _invertTree(root);
        return root;
    }

    void _invertTree(TreeNode *node) {
        // 终止条件
        if (NULL == node)
            return ;
        
        // 处理当前层
        TreeNode *tmpNode = node->left;
        node->left = node->right;
        node->right = tmpNode;

        // 进入下一层
        _invertTree(node->left);
        _invertTree(node->right);

        //清理当前层
    }
};