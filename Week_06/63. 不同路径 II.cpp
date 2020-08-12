class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        if (obstacleGrid.empty() || obstacleGrid[0].empty())
            return 0;

        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        //!!!!!注，这里的结果有可能会超过int的表示范围，故设置为long long
        vector<vector<long long >> pathNums(m, vector<long long>(n, 0));
        
        if (1 == obstacleGrid[m-1][n-1])
            return 0;
        
        // 最后一列，只有1种走法
        for (int i = m-1; i >= 0; --i) {
            if (0 == obstacleGrid[i][n-1]) {
                pathNums[i][n - 1] = 1;
            } else {
                // 上面的所有位置都不能再走过去了
                while (i >= 0)
                    pathNums[i--][n-1] = 0;
            }
        }

        // 最后一行，只有1种走法
        for (int j = n-1; j >= 0; --j) {
            if (0 == obstacleGrid[m-1][j]) {
                pathNums[m-1][j] = 1;
            } else {
                // 前面的位置都不能走到末端
                while (j >= 0)
                    pathNums[m-1][j--] = 0;
            }
        }

        // 填充内部
        for (int i = m - 2; i >= 0; --i) {
            for (int j = n - 2; j>= 0; --j) {
                if (1 == obstacleGrid[i][j]) {
                    pathNums[i][j] = 0;
                } else {
                    pathNums[i][j] = pathNums[i][j+1] + pathNums[i+1][j];
                }
                // cout << "i: " << i << " j: " << j << " " << pathNums[i][j] << endl;
            }
        }

        return pathNums[0][0];
    }
};