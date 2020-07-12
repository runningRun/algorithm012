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
    bool hasPathSum(TreeNode* root, int sum) {
        if (NULL != root){
            sum  -= root->val;
            if (NULL == root->left && NULL == root->right) {
                if (0 == sum)
                    return true;
                else 
                    return false;
            }
            return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
        } else
            return false;
    }
};