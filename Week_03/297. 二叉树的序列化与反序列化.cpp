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
 * !!!!!!!!!!!!注意点!!!!!!!!!!!!!!
 * ** 1. 序列化时，即使是最底层的叶子节点，也要加上null，方便反序列化
 * ** 2. 由于可能不是完全二叉树，所以不能使用使用如下方法构建二叉树
 * TreeNode* buildTree(int currIndex, vector<string>& strNodes) {
        if (currIndex >= strNodes.size() || 0 == strNodes[currIndex].compare(string("null"))) 
            return NULL;
            
        TreeNode *node = new TreeNode(0);
        int val = 0;
        val = stoi(strNodes[currIndex]);
        node->val = val;

        if ((2 * currIndex + 1) < strNodes.size()) {
            node->left = buildTree(2 * currIndex + 1, strNodes);
        }

        if ((2 * currIndex + 2) < strNodes.size()) {
            node->right = buildTree(2 * currIndex + 2, strNodes);
        }

        return node;
    }
 * 参考题解
 * https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/solution/shou-hui-tu-jie-gei-chu-dfshe-bfsliang-chong-jie-f/
 */

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return levelSerialize(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return levelDeserialize(data);
    }
private:
    string levelSerialize(TreeNode* root) {
         if (NULL == root) {
            return "";
        }

        deque<string> nodeVal;
        queue<TreeNode*> nodes;
        TreeNode *tmpNode = NULL;

        nodes.push(root);
        while(!nodes.empty()) {
            tmpNode = nodes.front();
            nodes.pop();
            if (NULL == tmpNode) {
                nodeVal.push_back("N");
            } else {
                nodeVal.push_back(to_string(tmpNode->val));
                nodes.push(tmpNode->left);
                nodes.push(tmpNode->right);
            }
        }

        // while (nodeVal.back() == "null")
        //     nodeVal.pop_back();
        string result("[");
        for (string tmpNodeVal : nodeVal) {
            result += tmpNodeVal;
            result += ",";
        }
        result[result.size() - 1] = ']';
        // cout << "result: " << result << endl;
        return result;
    }

    TreeNode* levelDeserialize(string data) {
        if (data.empty())
            return NULL;
        string tmpVal("");
        vector<string> strNodeVec;
        for (int index = 1; index < data.size() - 1; ++index) {
            if (',' == data[index]) {
                // cout << "tmp val: " << tmpVal << endl;
                strNodeVec.push_back(tmpVal);
                tmpVal = "";
            } else {
                tmpVal += data[index];
            }
        }
        if (tmpVal.size() > 0) {
            // cout << "tmp val: " << tmpVal << endl;
            strNodeVec.push_back(tmpVal);
        }

        return levelBuildTree(strNodeVec);
    }

    TreeNode* levelBuildTree(vector<string>& strNodes) {
        if (strNodes.empty())
            return NULL;

        int index = 0;
        string lValueStr("");
        string rValueStr("");
        TreeNode *root = new TreeNode(stoi(strNodes[0]));
        TreeNode *tmpNode = NULL;
        queue<TreeNode*> nodes;
        nodes.push(root);

        index = 1;
        while (index < strNodes.size() - 2) {
            tmpNode = nodes.front();
            nodes.pop();
            lValueStr = strNodes[index];
            rValueStr = strNodes[index + 1];
            // cout << "l value: " << lValueStr << " r value: " << rValueStr << endl;
            if (lValueStr.compare("N")) {
                // cout << "create left node" << endl;
                tmpNode->left = new TreeNode(stoi(lValueStr));
                nodes.push(tmpNode->left);
            }

            if (rValueStr.compare("N")) {
                // cout << "create right node" << endl;
                tmpNode->right = new TreeNode(stoi(rValueStr));
                nodes.push(tmpNode->right);
            }
            
            index += 2;

        }
        return root;
    }
}; 


/*************************神一般的代码**********************************/
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/discuss/74259/Recursive-preorder-Python-and-C%2B%2B-O(n)
class Codec {
public:

    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }

    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }

private:

    void serialize(TreeNode* root, ostringstream& out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "# ";
        }
    }

    TreeNode* deserialize(istringstream& in) {
        string val;
        in >> val;
        if (val == "#")
            return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));