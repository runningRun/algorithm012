class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> tmpResult(k);
        _myCombine(0, k, n, 1, tmpResult, result);
        return result;
    }
private:
    // startIndex是为了去除一个元素多次使用
    void _myCombine(int level, int k, int n, int startIndex, vector<int> &currentResult, vector<vector<int>> &result) {
        // 结束条件
        if (level == k) {
            result.push_back(currentResult);
            return ;
        }

        // 本层处理
        for (int index = startIndex; index <= n; ++index) {
            currentResult[level] = index;
            // 进入下一层
            _myCombine(level + 1, k, n, index + 1, currentResult, result);
        }
        
    }
};