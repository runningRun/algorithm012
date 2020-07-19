class Solution {
public:
    string reverseWords(string s) {
        stack<string> wordsStack;
        string word = "";
        string result = "";

        for (int index = 0; index < s.size(); ++index) {
            if (' ' == s[index]) {
                if (0 != word.size()) {
                    wordsStack.push(word);
                }
                word = "";
            } else {
                word += s[index];
            }
        }

        // 一定不要忘记把最后一个单词入栈
        if (word.size() > 0)
            wordsStack.push(word);

        while (!wordsStack.empty()) {
            result += wordsStack.top();
            wordsStack.pop();
            result += ' ';
        }
        if (result.size() > 0) {
            result[result.size() - 1] = 0;
        }
        return result;

    }
};