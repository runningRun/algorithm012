/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 /*层序遍历*/
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if (NULL == root)
            return result;

        queue<TreeNode*> nodes;
        int queSize = 0;
        int tmpMax = 0;

        nodes.push(root);
        while (!nodes.empty()) {
            queSize = nodes.size();
            tmpMax = nodes.front()->val;
            for (int ii = 0; ii < queSize; ++ii) {
                TreeNode* &tmpNode = nodes.front();
                if (tmpMax < tmpNode->val)
                    tmpMax = tmpNode->val;
                if (tmpNode->left)
                    nodes.push(tmpNode->left);
                if (tmpNode->right)
                    nodes.push(tmpNode->right);
                nodes.pop();
            }
            result.push_back(tmpMax);
        }
        return result;
    }
};

/*层序遍历2*/
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if (NULL == root)
            return result;

        TreeNode *tmpNode = NULL;
        int tmpLevel = 0;
        queue<pair<TreeNode*, int>> nodes;
        nodes.push({root, 0});
        while (!nodes.empty()) {
            pair<TreeNode*, int> &tmpNodeLevel = nodes.front();
            tmpNode = tmpNodeLevel.first;
            tmpLevel = tmpNodeLevel.second;
            if (tmpLevel == result.size()) {
                result.push_back(tmpNode->val);
            } else if (result[tmpLevel] < tmpNode->val){
                result[tmpLevel] = tmpNode->val;
            }
            if (tmpNode->left)
                nodes.push({tmpNode->left, tmpLevel + 1});
            if (tmpNodeLevel.first->right)
                nodes.push({tmpNode->right, tmpLevel + 1});
            nodes.pop();
        }
        return result;
    }
};

/*DFS*/
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        dfs(0, result, root);
        return result;
    }
private:
    void dfs(int level, vector<int> &result, const TreeNode *root) {
        if (NULL == root) {
            return ;
        }
        if (level == result.size()) {
            result.push_back(root->val);
        } else if (result[level] < root->val) {
            result[level] = root->val;
        }
        dfs(level + 1, result, root->left);
        dfs(level + 1, result, root->right);
    }
};