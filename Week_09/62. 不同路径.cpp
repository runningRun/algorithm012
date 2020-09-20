// 回溯 + Memo
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m , vector<int>(n, -1));

        return backtrace(0, 0, m, n, memo);
    }

private:
    int backtrace(int i, int j, int m, int n, vector<vector<int>> &memo) {
        if (i >= m || j >= n)
            return 0;
        if (-1 != memo[i][j])
            return memo[i][j];
        if (i == m - 1 && j == n - 1) {
            return 1;
        } else {
            memo[i][j] = backtrace(i, j+1, m, n, memo) + backtrace(i+1, j, m, n, memo);
        }
        // cout << i << ", " << j << " " << memo[i][j] << endl;
        return memo[i][j];
    }
};

// DP
class Solution1 {
public:
    int uniquePaths(int m, int n) {
        if (0 == m || 0 == n)
            return 0;

        vector<vector<int>> pathNums(m, vector<int>(n, 0));
        
        // 最后一列，只有1种走法
        for (int i = 0; i < m; ++i) {
            pathNums[i][n - 1] = 1;
        }
        // 最后一行，只有1种走法
        for (int j = 0; j < n; ++j) {
            pathNums[m-1][j] = 1;
        }

        // 填充内部
        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j>= 0; --j)
                pathNums[i][j] = pathNums[i][j+1] + pathNums[i+1][j];
        }

        return pathNums[0][0];

    }
};