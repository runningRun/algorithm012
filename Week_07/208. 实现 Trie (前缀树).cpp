
class TrieNode {
public:
    TrieNode() : children(26, NULL) {
        isLeave = false;
    }
    bool containChild(char ch) {
        return !(children[ch - 'a'] == NULL);
    }

    TrieNode *getChildTrieNode(char ch) {
        return children[ch - 'a'];
    }

    TrieNode *insertChildTridNode(char ch) {
        TrieNode *newNode = NULL;
        if (containChild(ch)) {
            newNode = children[ch - 'a'];
        } else {
            newNode = new TrieNode();
            children[ch - 'a'] = newNode;
        }
        return newNode;
    }

    void setLeave() {
        isLeave = true;
    }

    bool getIsLeave() {
        return isLeave;
    }

    ~TrieNode() {
        for (TrieNode *&child : children) {
            if (NULL != child) {
                delete child;
                child = NULL;
            }
        }
    }

private:
    vector<TrieNode* > children;
    bool isLeave;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {

    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *node = &root;
        for (int ii = 0; ii < word.size(); ++ii) {
            if (node->containChild(word[ii])) {
                node = node->getChildTrieNode(word[ii]);
            } else {
                node = node->insertChildTridNode(word[ii]);
            } 
        }
        node->setLeave();
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *node = &root;
         for (int ii = 0; ii < word.size(); ++ii) {
            if (node->containChild(word[ii])) {
                node = node->getChildTrieNode(word[ii]);
            } else {
                return false;
            } 
        }
        return node->getIsLeave();
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *node = &root;
        for (int ii = 0; ii < prefix.size(); ++ii) {
            if (node->containChild(prefix[ii])) {
                node = node->getChildTrieNode(prefix[ii]);
            } else {
                return false;
            } 
        }
        return true;
    }

private:
    TrieNode root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */