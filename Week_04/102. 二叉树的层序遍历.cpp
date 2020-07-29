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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<TreeNode*, int>> nodes;
        vector<vector<int>> result;
        if (NULL != root)
            nodes.push({root, 0});
        while (!nodes.empty()) {
            /*
             ***注: 此处用的是引用，所以只能在本轮循环结束时pop**
            */
            pair<TreeNode*, int> &tmpNodePair = nodes.front();
            if (tmpNodePair.second == result.size()) {
                result.push_back(vector<int>{tmpNodePair.first->val});
            } else {
                result[tmpNodePair.second].push_back(tmpNodePair.first->val);
            }
            if (NULL != tmpNodePair.first->left)
                nodes.push({tmpNodePair.first->left, tmpNodePair.second + 1});
            if (NULL != tmpNodePair.first->right)
                nodes.push({tmpNodePair.first->right, tmpNodePair.second + 1});
            nodes.pop();
        }
        return result;
    }
};

// 使用递归
class Solution {
public:
     vector<vector<int>> levelOrder(TreeNode* root) {
         vector<vector<int>> result;
         _myLevelOrder(root, 0, result);
         return result;
     }
private:
    void _myLevelOrder(TreeNode* node , int nodeLevel, vector<vector<int>>& result) {
        // 终止条件
        if (NULL == node)
            return ;
        
        // 本层处理
        if (nodeLevel == result.size()) {
            result.push_back({node->val});
        } else {
            result[nodeLevel].push_back(node->val);
        }

        // 进入下一层
        _myLevelOrder(node->left, nodeLevel + 1, result);
        _myLevelOrder(node->right, nodeLevel + 1, result);
    }
};

// 使用层次遍历，每次循环清空一层，复杂度同样是O(n)
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode *> nodes;
        if (NULL != root)
            nodes.push(root);
        while(!nodes.empty()) {
            vector<int> tmpResult;
            int tmpSize = nodes.size();
            TreeNode *tmpNode = NULL;
            for (int n = 0; n < tmpSize; ++n) {
                tmpNode = nodes.front();
                tmpResult.push_back(tmpNode->val);
                if (NULL != tmpNode->left)
                    nodes.push(tmpNode->left);
                if (NULL != tmpNode->right)
                    nodes.push(tmpNode->right);
                nodes.pop();
            }
            result.push_back(tmpResult);
        }
        return result;
    }
};
