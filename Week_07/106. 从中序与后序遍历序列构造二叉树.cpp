class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderMap;
        for (int ii = 0; ii < inorder.size(); ++ii) {
            inorderMap.insert({inorder[ii], ii});
        }
        return buildTree(0, inorder.size() - 1, postorder, 0, postorder.size() - 1, inorderMap);
    }

private:
    TreeNode *buildTree(int is, int ie, vector<int>& postorder, int ps, int pe, unordered_map<int, int> &inorderMap) {
        if (ie < is || pe < ps)
            return NULL;
        int lrIndex = inorderMap[postorder[pe]];
        TreeNode *newNode = new TreeNode(postorder[pe]);
        newNode->left = buildTree(is, lrIndex - 1, postorder, ps, ps + (lrIndex - is - 1), inorderMap);
        newNode->right = buildTree(lrIndex + 1, ie, postorder, ps + (lrIndex - is), pe - 1, inorderMap);
        return newNode;
    }
};