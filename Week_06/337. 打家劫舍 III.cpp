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
 * 超时!!!!!!!!!!!!!!
*/
class Solution {
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> mem;      // 记录node对应的值
        return dfs(root, mem);
    }

private:
    /*
     * 注: mem为****引用****
     * int dfs(TreeNode* root, unordered_map<TreeNode*, int> &mem)
    */
    int dfs(TreeNode* root, unordered_map<TreeNode*, int> &mem) {
        if (NULL == root)
            return 0;
        if (mem.find(root) == mem.end()) {
            // 不打劫本层
            int nrobRoot = dfs(root->left, mem) + dfs(root->right, mem);
            
            // 打劫本层，则其左右子节点均不能被打劫，直接跳过
            int robRoot = 0;
            {
                int robRootLeft = 0;
                int robRootRight = 0;
                if (NULL != root->left)
                    robRootLeft = dfs(root->left->left, mem) + dfs(root->left->right, mem);
                if (NULL != root->right)
                    robRootRight = dfs(root->right->left, mem) + dfs(root->right->right, mem);
                robRoot = robRootLeft + robRootRight + root->val;
            }
            mem[root] = max(nrobRoot, robRoot);
        }
        // cout << "root: " << root->val << " rob value: " << mem[root] << endl;
        return mem[root];
    }
};