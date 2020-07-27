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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderEleIndex;
        for (int idx = 0; idx < inorder.size(); ++idx) {
            inorderEleIndex.insert({inorder[idx], idx});
        }

        return _myBuildTree(preorder, 0, preorder.size(), inorder, 0, inorder.size(), inorderEleIndex);
    }
private:
    TreeNode* _myBuildTree(vector<int>& preorder, int pStart, int pEnd, vector<int>& inorder, int iStart, int iEnd, unordered_map<int, int>& inorderEleIndex) {
        if (pStart == pEnd)
            return NULL;
        TreeNode *node = new TreeNode(preorder[pStart]);
        int iIdx = inorderEleIndex[preorder[pStart]];
        node->left = _myBuildTree(preorder, pStart + 1, pStart + 1 + (iIdx - iStart), inorder, iStart, iIdx - 1, inorderEleIndex);
        node->right = _myBuildTree(preorder, pStart + 1 + (iIdx - iStart), pEnd, inorder, iIdx + 1, iEnd, inorderEleIndex);
        return node;
    }
};