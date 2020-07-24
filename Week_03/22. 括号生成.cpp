class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        _generateParenthesis(0, 0, n, "", result);
        return result;
    }

    void _generateParenthesis(int left, int right, int max, string current, vector<string> &result) {
        // 终止条件
        if (left == max && right == max) {
            result.push_back(current);
            return ;
        }
        // 本层处理

        // 下探到下一层
        if (left < max)
            _generateParenthesis(left + 1, right, max, current + '(', result);
        if (right < left)
            _generateParenthesis(left, right + 1, max, current + ')', result);

        // 清理本层

    }
};