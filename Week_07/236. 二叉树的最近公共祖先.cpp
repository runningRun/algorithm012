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
    /*
     * 因为不是满二叉树，所以不能通过数组，使用(index - 1) / 2的方式
     * 获取其父指针
    */
    TreeNode* lowestCommonAncestorError(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> nodes;
        int pIndex = 0;
        int qIndex = 0;
        nodes.push_back(root);
        for (int ii = 0; ii < nodes.size(); ++ii) {
            if (NULL != nodes[ii]) {
                nodes.push_back(nodes[ii]->left);
                nodes.push_back(nodes[ii]->right);
            }
            if (p == nodes[ii]) {
                pIndex = ii;
            }
            if (q == nodes[ii]) {
                qIndex = ii;
            }
        }

        while (pIndex != qIndex) {
            if (pIndex > qIndex) {
                pIndex = (pIndex - 1) / 2;
            } else {
                qIndex = (qIndex - 1) / 2;
            }
        }
        return nodes[pIndex];
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (NULL == root || p == root || q == root)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (NULL == left)
            return right;
        if (NULL == right)
            return left;
        return root;
    }

    TreeNode* lowestCommonAncestor4map(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (NULL == root)
            return NULL;
        unordered_map<TreeNode*, TreeNode*> parent;
        unordered_set<TreeNode*> pParent;

        dfs(root, parent);
        pParent.insert(p);
        pParent.insert(root);
        // cout << "p: " << p;
        while (p != root) {
            p = parent[p];
            // cout << " " << p;
            pParent.insert(p);
        }

        while (q != root) {
            if (pParent.find(q) != pParent.end())
                return q;
            q = parent[q];
        }
        return root;
     }

private:
    void dfs(TreeNode *root, unordered_map<TreeNode*, TreeNode*> &parent) {
        if (NULL != root->left) {
            // cout << root << " " << root->left << endl;
            parent.insert({root->left, root});
            dfs(root->left, parent);
        }
        if (NULL != root->right) {
            // cout << root << " " << root->right << endl;
            parent.insert({root->right, root});
            dfs(root->right, parent);
        }
    }
};