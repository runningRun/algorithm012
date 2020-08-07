class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (0 == digits.size())
            return result;
        vector<string> al2str = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        // digits.size()即表示格子的数量
        // 每个格子中候选的字母为digits[index] 按键对应的字符串中的字符
        string tmpResult(digits.size(), '*');
        dfs(0, digits.size(), digits, al2str, tmpResult, result);

        return result;
    }

private:
    void dfs(int level, int maxLevel, string &digits, vector<string> &al2str, string &tmpResult, vector<string> &result) {
        // cout << "level: " << level << " maxLevel: " << maxLevel << " tmpResult: " << tmpResult << endl;
        if (level == maxLevel) {
            // cout << "result: " << tmpResult << endl;
            result.push_back(tmpResult);
            return ;
        }
        const string &candidate  = al2str[digits[level] - '0'];
        for (char ch : candidate) {
            tmpResult[level] = ch;
            dfs(level + 1, maxLevel, digits, al2str, tmpResult, result);
        }

    }
};