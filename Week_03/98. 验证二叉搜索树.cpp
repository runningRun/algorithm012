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
 *
 * *********!!!!错误示例!!!!************
 * [10,5,15,null,null,6,20]
*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (NULL == root)
            return true;
        
        bool tmp = true;
        if (NULL != root->left) {
            tmp &= root->left->val < root->val;
        }
        
        if (NULL != root->right) {
            tmp &= root->right->val > root->val;
        }

        return tmp && isValidBST(root->left) && isValidBST(root->right);
    }
};

// 正确的递归思路，需要引入上界、下界
// https://www.geekxh.com/1.4.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%B3%BB%E5%88%97/403.html#_03%E3%80%81%E9%80%92%E5%BD%92%E6%B1%82%E8%A7%A3
// 使用INT64_MIN、INT64_MAX, 是为了处理临界情况
// [2147483647]
// [-2147483648,null,2147483647]

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        // printf("INT32_MIN: %d, INT32_MAX: %d\n", INT32_MIN, INT32_MAX);
        // if (NULL == root || (NULL == root->left && NULL == root->right))
        //     return true;
        return isValidBST(root, INT64_MIN, INT64_MAX);
    }

private:
    bool isValidBST(TreeNode *root, long long min, long long max) {
        if (NULL == root)
            return true;
        if (root->val >= max || root->val <= min)
            return false;
        return isValidBST(root->left, min, root->val) && isValidBST(root->right, root->val, max);
    }
};

// 利用BST中序遍历的有序性
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> inorderTravel;
        inorderTravelTree(root, inorderTravel);
        return checkArray(inorderTravel);
    }

    void inorderTravelTree(TreeNode *node, vector<int> &vec) {
        if (NULL == node)
            return ;
        inorderTravelTree(node->left, vec);
        vec.push_back(node->val);
        // printf("%d ", node->val);
        inorderTravelTree(node->right, vec);
    }

    bool checkArray(vector<int> &vec) {
        for (int index = 1; index < vec.size(); ++index) {
            if (vec[index - 1] >= vec[index])
                return false;
        }
        return true;
    }
};
