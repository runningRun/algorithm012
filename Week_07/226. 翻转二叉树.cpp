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
        if (NULL == root) 
            return root;
        queue<TreeNode*> nodes;
        TreeNode *tmpNode = NULL;
        nodes.push(root);
        
        while (!nodes.empty()) {
            tmpNode = nodes.front();
            nodes.pop();
            TreeNode *t = tmpNode->left;
            tmpNode->left = tmpNode->right;
            tmpNode->right = t;
            if (NULL != tmpNode->left)
                nodes.push(tmpNode->left);
            if (NULL != tmpNode->right)
                nodes.push(tmpNode->right);
        }

        return root;
    }
    TreeNode* invertTree1(TreeNode* root) {
        if (NULL == root)
            return NULL;
        invertTree(root->left);
        invertTree(root->right);
        TreeNode *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        return root;
    }
};