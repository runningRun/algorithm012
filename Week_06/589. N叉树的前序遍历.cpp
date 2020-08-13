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

/*
 * !!!!!!!!!注：由于栈的特殊性(后进先出)!!!!!!!!!!!!!
 * 节点入栈时，需要逆着入栈
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        stack<Node*> nodes;
        vector<int> preOrder;
        Node *tmpNode = NULL;

        if (NULL == root)
            return preOrder;
        nodes.push(root);
        while(!nodes.empty()) {
            tmpNode = nodes.top();
            nodes.pop();
            preOrder.push_back(tmpNode->val);
            for (auto it = tmpNode->children.rbegin(); it != tmpNode->children.rend(); ++it) {
                nodes.push(*it);
            }
        }
        return preOrder;
    }
};