/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        // F1: 递归访问
        // preorderN(root, result);

        // F2: 使用辅助栈
        stack<Node *> sNode;
        Node *tmpNode = NULL;
        if (NULL == root)
            return result;
        sNode.push(root);
        while (!sNode.empty()) {
            tmpNode = sNode.top();
            sNode.pop();
            result.push_back(tmpNode->val);
            // ！！从右往左的把子节点入栈
            for (int index = tmpNode->children.size() - 1; index >= 0; --index) {
                sNode.push(tmpNode->children[index]);
            }
        }
        return result;
    }

    void preorderN(Node *root, vector<int> &result) {
        if (root != NULL) {
            result.push_back(root->val);
            for (Node *node : root->children) {
                preorderN(node, result);
            }
        }
    }
};