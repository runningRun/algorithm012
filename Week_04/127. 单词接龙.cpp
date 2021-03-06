//参考题解 https://leetcode.com/problems/word-ladder/discuss/40707/C%2B%2B-BFS
/*
 * 已begindWord为起点，根据wordList列表，构建层次树，然后使用BFS
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {    
        set<string> bankSet(wordList.begin(), wordList.end());
        unordered_map<string, set<string>> neighbor;
        queue<string> words;
        words.push(beginWord);
        while (bankSet.find(beginWord) != bankSet.end()) {
            bankSet.erase(bankSet.find(beginWord));
        }
        while (!words.empty()) {
            string word = words.front();
            words.pop();
            for (auto it = bankSet.begin(); it != bankSet.end(); ++it) {
                if (1 == getDistance(word, *it)) {
                    neighbor[word].insert(*it);
                    words.push(*it);
                    bankSet.erase(it);
                }
            }
        }
        // for (auto it = neighbor.begin(); it != neighbor.end(); ++it) {
        //     cout << it->first << " neighbor with: " ;
        //     for (auto ii =  it->second.begin(); ii != it->second.end(); ++ii) {
        //         cout << *ii << ", ";
        //     }
        //     cout << endl;
        // }

        int result = 0;
        queue<pair<string, int>> wordsWithLevel;
        wordsWithLevel.push({beginWord, 1});
        while (!wordsWithLevel.empty()) {
            int size = wordsWithLevel.size();
            pair<string, int> &tmpPair = wordsWithLevel.front();
            string tmpWord = tmpPair.first;
            int level = tmpPair.second;
            // cout << tmpWord << " level: " << level << endl;
            set<string> &tmpNeighbors = neighbor[tmpWord];
            if (tmpNeighbors.find(endWord) != tmpNeighbors.end()) {
                result = level + 1;
            } else {
                for (string tt : tmpNeighbors) {
                    wordsWithLevel.push({tt, level + 1});
                }
            }
            wordsWithLevel.pop();
        }
        return result;
    }
private:
    int getDistance(string word, string word2) {
        int l1 = word.length();
        int l2 = word.length();
        int distance = 0;
        int index = 0;
        for (index = 0; index < l1 && index < l2; ++index) {
            if (word[index] != word2[index])
                distance += 1;
        }

        distance += (l1 - index);
        distance += (l2 - index);
        
        return distance;
    }
};



class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {    
        set<string> bankSet(wordList.begin(), wordList.end());
        unordered_map<string, set<string>> neighbor;
        queue<string> words;
        words.push(beginWord);
        while (bankSet.find(beginWord) != bankSet.end()) {
            bankSet.erase(bankSet.find(beginWord));
        }
        while (!words.empty()) {
            string originalWord = words.front();
            string word = originalWord;
            words.pop();
            for (int index = 0; index < word.size(); ++index) {
                char tmpCh = word[index];
                for (int iaz = 0; iaz < 26; ++iaz) {
                    if (tmpCh != iaz + 'a') {
                        word[index] = iaz + 'a';
                        auto it = bankSet.find(word);
                        if (bankSet.find(word) != bankSet.end()) {
                            neighbor[originalWord].insert(word);
                            words.push(word);
                            bankSet.erase(it);
                        }
                    }
                }
                word[index] = tmpCh;
            }
        }
        // for (auto it = neighbor.begin(); it != neighbor.end(); ++it) {
        //     cout << it->first << " neighbor with: " ;
        //     for (auto ii =  it->second.begin(); ii != it->second.end(); ++ii) {
        //         cout << *ii << ", ";
        //     }
        //     cout << endl;
        // }

        int result = 0;
        queue<pair<string, int>> wordsWithLevel;
        wordsWithLevel.push({beginWord, 1});
        while (!wordsWithLevel.empty()) {
            int size = wordsWithLevel.size();
            pair<string, int> &tmpPair = wordsWithLevel.front();
            string tmpWord = tmpPair.first;
            int level = tmpPair.second;
            // cout << tmpWord << " level: " << level << endl;
            set<string> &tmpNeighbors = neighbor[tmpWord];
            if (tmpNeighbors.find(endWord) != tmpNeighbors.end()) {
                result = level + 1;
            } else {
                for (string tt : tmpNeighbors) {
                    wordsWithLevel.push({tt, level + 1});
                }
            }
            wordsWithLevel.pop();
        }
        return result;
    }
private:
    int getDistance(string word, string word2) {
        int l1 = word.length();
        int l2 = word.length();
        int distance = 0;
        int index = 0;
        for (index = 0; index < l1 && index < l2; ++index) {
            if (word[index] != word2[index])
                distance += 1;
        }

        distance += (l1 - index);
        distance += (l2 - index);
        
        return distance;
    }
};


/*
 * 1. bankSet使用unordered_set，比使用普通set能节省约900ms!!!!!!!!!!!!!!!!!!
 * 2. 每次将word修改一个字母，查找bankSet中是否有该邻居(neighbor)
*/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {    
        unordered_set<string> bankSet(wordList.begin(), wordList.end());
        unordered_map<string, set<string>> neighbor;
        queue<string> words;
        words.push(beginWord);
        while (bankSet.find(beginWord) != bankSet.end()) {
            bankSet.erase(bankSet.find(beginWord));
        }
        while (!words.empty()) {
            string originalWord = words.front();
            string word = originalWord;
            words.pop();
            for (int index = 0; index < word.size(); ++index) {
                char tmpCh = word[index];
                for (int iaz = 0; iaz < 26; ++iaz) {
                    if (tmpCh != iaz + 'a') {
                        word[index] = iaz + 'a';
                        auto it = bankSet.find(word);
                        if (bankSet.find(word) != bankSet.end()) {
                            neighbor[originalWord].insert(word);
                            words.push(word);
                            bankSet.erase(it);
                        }
                    }
                }
                word[index] = tmpCh;
            }
        }
        // for (auto it = neighbor.begin(); it != neighbor.end(); ++it) {
        //     cout << it->first << " neighbor with: " ;
        //     for (auto ii =  it->second.begin(); ii != it->second.end(); ++ii) {
        //         cout << *ii << ", ";
        //     }
        //     cout << endl;
        // }

        int result = 0;
        queue<pair<string, int>> wordsWithLevel;
        wordsWithLevel.push({beginWord, 1});
        while (!wordsWithLevel.empty()) {
            int size = wordsWithLevel.size();
            pair<string, int> &tmpPair = wordsWithLevel.front();
            string tmpWord = tmpPair.first;
            int level = tmpPair.second;
            // cout << tmpWord << " level: " << level << endl;
            set<string> &tmpNeighbors = neighbor[tmpWord];
            if (tmpNeighbors.find(endWord) != tmpNeighbors.end()) {
                result = level + 1;
            } else {
                for (string tt : tmpNeighbors) {
                    wordsWithLevel.push({tt, level + 1});
                }
            }
            wordsWithLevel.pop();
        }
        return result;
    }
};


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {    
        unordered_set<string> bankSet(wordList.begin(), wordList.end());
        if (bankSet.find(endWord) == bankSet.end())
            return 0;
        unordered_map<string, set<string>> neighbor;
        queue<string> words;
        words.push(beginWord);
        while (bankSet.find(beginWord) != bankSet.end()) {
            bankSet.erase(bankSet.find(beginWord));
        }
        while (!words.empty()) {
            string originalWord = words.front();
            string word = originalWord;
            words.pop();
            for (int index = 0; index < word.size(); ++index) {
                char tmpCh = word[index];
                for (int iaz = 0; iaz < 26; ++iaz) {
                    // if (tmpCh != iaz + 'a') {
                        word[index] = iaz + 'a';
                        auto it = bankSet.find(word);
                        if (bankSet.find(word) != bankSet.end()) {
                            neighbor[originalWord].insert(word);
                            words.push(word);
                            bankSet.erase(it);
                        }
                    // }
                }
                word[index] = tmpCh;
            }
        }
        // for (auto it = neighbor.begin(); it != neighbor.end(); ++it) {
        //     cout << it->first << " neighbor with: " ;
        //     for (auto ii =  it->second.begin(); ii != it->second.end(); ++ii) {
        //         cout << *ii << ", ";
        //     }
        //     cout << endl;
        // }

        queue<string> wordsWithLevel;
        wordsWithLevel.push(beginWord);
        int level = 1;
        while (!wordsWithLevel.empty()) {
            int size = wordsWithLevel.size();
            for (int ii = 0; ii < size; ++ ii) {
                string &tmpWord = wordsWithLevel.front();
                set<string> &tmpNeighbors = neighbor[tmpWord];
                if (tmpNeighbors.find(endWord) != tmpNeighbors.end()) {
                    return level + 1;
                } else {
                    for (string tt : tmpNeighbors) {
                        wordsWithLevel.push(tt);
                    }
                }
                wordsWithLevel.pop();
            }
            level += 1;
        }
        // cout << "level: " << level << endl;
        return 0;
    }
};

/*
 * 官方题解：https://leetcode-cn.com/problems/word-ladder/solution/dan-ci-jie-long-by-leetcode/
 * F1: BFS
*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {   
        // 以输入hit, cog, ["hot","dot","dog","lot","log","cog"]为例
        /* 将wordList格式化为:
         * hot: *ot => [hot, dot, lot]; h*t => [hot]; ho* => [hot]
         * dot: *ot                   ; d*t => [dot]; do* => [dot, dog]
         * dog: *og => [dog, log, cog]; d*g => [dog]; do* 
         * lot: *ot                   ; l*t => [lot]; lo* => [lot, log]
         * log: *og                   ; l*g => [log]; lo*
         * cog: *og                   ; c*g => [cog]; co* => [cog]
        */

        unordered_map<string, unordered_set<string>> formatWordMap;
        for (string word : wordList) {
            string tmpWord = word;
            for (int index = 0; index < tmpWord.size(); ++index) {
                char oldChar = tmpWord[index];
                tmpWord[index] = '*';
                formatWordMap[tmpWord].insert(word);
                tmpWord[index] = oldChar;
            }
        }

        // for (pair<const string, unordered_set<string>> &item : formatWordMap) {
        //     cout << item.first << ": ";
        //     for (const string &v : item.second) {
        //         cout << " " << v;
        //     }
        //     cout << endl;
        // }

        // BFS
        map<string, bool> visited;
        queue<pair<string, int>> wordLevelQueue;
        wordLevelQueue.push({beginWord, 1});
        while (!wordLevelQueue.empty()) {
            pair<string, int> node = wordLevelQueue.front();
            wordLevelQueue.pop();
            string tmpWord = node.first;
            int tmpLevel = node.second;
            // 处理每一个与之相邻的单词
            for (int index = 0; index < tmpWord.size(); ++index) {
                char oldChar = tmpWord[index];
                tmpWord[index] = '*';
                if (visited[tmpWord]) {
                    tmpWord[index] = oldChar;
                    continue;
                }

                // 获取经过变换第index位可以到达的邻居
                unordered_set<string> &neighbors = formatWordMap[tmpWord];
                if (neighbors.find(endWord) != neighbors.end()) {
                    // 找到了目标节点
                    return tmpLevel + 1;
                } else {
                    // 每一个相邻节点入Queue
                    for (const string &neighbor : neighbors) {
                        wordLevelQueue.push({neighbor, tmpLevel + 1});
                    }
                }
                visited[tmpWord] = true;
                tmpWord[index] = oldChar;
            }
        }

        return 0;
    }
};

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {   
        // 以输入hit, cog, ["hot","dot","dog","lot","log","cog"]为例
        /* 将wordList格式化为:
         * hot: *ot => [hot, dot, lot]; h*t => [hot]; ho* => [hot]
         * dot: *ot                   ; d*t => [dot]; do* => [dot, dog]
         * dog: *og => [dog, log, cog]; d*g => [dog]; do* 
         * lot: *ot                   ; l*t => [lot]; lo* => [lot, log]
         * log: *og                   ; l*g => [log]; lo*
         * cog: *og                   ; c*g => [cog]; co* => [cog]
        */

        unordered_map<string, unordered_set<string>> formatWordMap;
        for (string word : wordList) {
            string tmpWord = word;
            for (int index = 0; index < tmpWord.size(); ++index) {
                char oldChar = tmpWord[index];
                tmpWord[index] = '*';
                formatWordMap[tmpWord].insert(word);
                tmpWord[index] = oldChar;
            }
        }

        for (pair<const string, unordered_set<string>> &item : formatWordMap) {
            cout << item.first << ": ";
            for (const string &v : item.second) {
                cout << " " << v;
            }
            cout << endl;
        }

        // BFS
        map<string, bool> visited;
        queue<pair<string, int>> wordLevelQueue;
        wordLevelQueue.push({beginWord, 1});
        visited[beginWord] = true;
        while (!wordLevelQueue.empty()) {
            pair<string, int> node = wordLevelQueue.front();
            wordLevelQueue.pop();
            string tmpWord = node.first;
            int tmpLevel = node.second;
            cout << "word: " << tmpWord << ":" << endl;
            // 处理每一个与之相邻的单词
            for (int index = 0; index < tmpWord.size(); ++index) {
                char oldChar = tmpWord[index];
                tmpWord[index] = '*';
                cout << "\t" << tmpWord << "==>";
                if (visited[tmpWord]) {
                    tmpWord[index] = oldChar;
                    cout << "-----------visited!" << endl;
                    continue;
                }

                // 获取经过变换第index位可以到达的邻居
                unordered_set<string> &neighbors = formatWordMap[tmpWord];
                if (neighbors.find(endWord) != neighbors.end()) {
                    // 找到了目标节点
                    // return tmpLevel + 1;
                    cout << " found!! " << endl;
                    continue;
                } else {
                    // 每一个相邻节点入Queue
                    for (const string &neighbor : neighbors) {
                        cout << neighbor << " " ;
                        wordLevelQueue.push({neighbor, tmpLevel + 1});
                    }
                }
                visited[tmpWord] = true;
                tmpWord[index] = oldChar;
                cout << endl;
            }
            cout << endl;
        }

        return 0;
    }
};


// 别人44ms代码
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordDict(wordList.begin(), wordList.end());
        if (wordDict.find(endWord) == wordDict.end()) return 0;
        int step(0);
        unordered_set<string> begSet{beginWord}, endSet{endWord};
        while (begSet.size() > 0) {
            ++step;
            unordered_set<string> temp;
            for (unordered_set<string>::iterator itr = begSet.begin(); itr != begSet.end(); ++itr) {
                wordDict.erase(*itr);
            }
            for (unordered_set<string>::iterator itr = begSet.begin(); itr != begSet.end(); ++itr) {
                for (int i = 0; i < itr->size(); ++i) {
                    string str(*itr);
                    for (char c = 'a'; c <= 'z'; ++c) {
                        str[i] = c;
                        if (endSet.find(str) != endSet.end()) return ++step;
                        if (wordDict.count(str) != 0) temp.insert(str);
                    }
                }
            }
            if (temp.size() < endSet.size()) {
                begSet = temp;
            }
            else {
                begSet = endSet;
                endSet = temp;
            }
        }
        return 0;
    }
};