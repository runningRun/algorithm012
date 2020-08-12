class Solution {
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