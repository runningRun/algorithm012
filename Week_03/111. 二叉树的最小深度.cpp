/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 如果单纯的比较左右子树的最小深度，则不符合题意
// 题目中定义：最小深度是从根节点到最近叶子节点的最短路径上节点的数量
// 如果有一个子树为NULL，例如输入为[1,2], 则正确的最小深度为2，而不是1
/*
 **************错误****************
*/
class Solution {
public:
    int minDepth(TreeNode* root) {
        // 终止条件
        if (NULL == root) {
            return 0;
        }

        // 本层处理

        // 进入下一层
        int lMinDepth = minDepth(root->left);
        int rMinDepth = minDepth(root->right);
        
        return lMinDepth < rMinDepth ? lMinDepth + 1 :  rMinDepth + 1;
    }
};


/*
 ******正确的**递归**方式*********
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        // 终止条件
        if (NULL == root) {
            return 0;
        }

        if (NULL == root->left && NULL == root->right) {
            return 1;
        }

        // 本层处理

        // 进入下一层
        if (NULL == root->left) 
            return minDepth(root->right) + 1;
        if (NULL == root->right)
            return minDepth(root->left) + 1;
        
        int lMinDepth = 0;
        int rMinDepth = 0;
        lMinDepth = minDepth(root->left);
        rMinDepth = minDepth(root->right);
        return lMinDepth < rMinDepth ? lMinDepth + 1 :  rMinDepth + 1;
    }
};

// 层次遍历，遇到的第一个**叶子节点**所在层次，即为最小深度
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (NULL == root)
            return 0;

        queue<pair<TreeNode*, int>> levelTraver;
        levelTraver.push({root, 1});

        while (!levelTraver.empty()) {
            pair<TreeNode*, int> tmp = levelTraver.front();
            TreeNode *tmpNode = tmp.first;
            levelTraver.pop();
            
            if (NULL == tmpNode->left && NULL == tmpNode->right)
                return tmp.second;

            if (NULL != tmpNode->left)
                levelTraver.push({tmpNode->left, tmp.second + 1});

            if (NULL != tmpNode->right)
                levelTraver.push({tmpNode->right, tmp.second + 1});
        }
        // 仅仅为了程序编译通过
        return 0;
    }
};