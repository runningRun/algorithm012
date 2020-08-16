class Solution {
public:
    // 自底向上
    int minimumTotal1(vector<vector<int>>& triangle) {
        vector<int> tmpMinPath = triangle[triangle.size() - 1];
        for (int index = triangle.size() - 2; index >= 0; --index) {
            for (int jIndex = 0; jIndex < index + 1; ++jIndex) {
                tmpMinPath[jIndex] = triangle[index][jIndex] + min(tmpMinPath[jIndex], tmpMinPath[jIndex + 1]);
            }
        }
        return tmpMinPath[0];
    }

    // 自顶向下 + 记忆化
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty() || triangle[0].empty())
            return 0;
        vector<vector<pair<bool, int>>> memo(triangle.size(), vector<pair<bool, int>>(triangle.size(), {false, 0}));

        return dfs(0, 0, triangle, memo);
    }

private:
    int dfs(int i, int j, vector<vector<int>>& triangle, vector<vector<pair<bool, int>>> &memo) {
        if (i == triangle.size())
            return 0;
        if (memo[i][j].first)
            return memo[i][j].second;
        
        int left = dfs(i+1, j, triangle, memo);
        int right = dfs(i+1, j+1, triangle, memo);
        int result = min(left, right) + triangle[i][j];
        memo[i][j] = {true, result};
        return result;
    }

};