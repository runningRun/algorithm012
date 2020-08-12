class Solution1 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> pathSum(m, vector<int>(n, 0));
        int index = 0;
        int jIndex = 0;
        // 最后一列
        pathSum[m-1][n-1] = grid[m-1][n-1];
        for (index = m - 2; index >= 0; --index) {
            pathSum[index][n-1] = grid[index][n-1] + pathSum[index+1][n-1];
        }

        // 最后一行
        for (jIndex = n - 2; jIndex >= 0; --jIndex) {
            pathSum[m-1][jIndex] = grid[m-1][jIndex] + pathSum[m-1][jIndex+1];
        }

        for (index = m - 2; index >= 0; --index) {
            for (jIndex = n - 2; jIndex >= 0; --jIndex) {
                pathSum[index][jIndex] = grid[index][jIndex] + min(pathSum[index][jIndex+1], pathSum[index+1][jIndex]);
            }
        } 
        return pathSum[0][0];

    }
};

// dfs + 剪枝
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty())
            return 0;
        int m = grid.size();
        int n = grid[0].size();

        unordered_map<long long int, int> iResult;
        return dfs(0, 0, m, n, grid, iResult);
    }

private:
    int dfs(int i, int j, int m, int n, vector<vector<int>> &grid, unordered_map<long long int, int> &iResult) {
        if (i == m || j == n)
            return INT_MAX;

        // stringstream ss;
        // ss << i << "-" << j;
        long long pair = 0;
        pair = i;
        pair = pair << 32;
        pair |= j;
        if (iResult.find(pair) != iResult.end())
            return iResult[pair];

        if (i == m - 1 && j == n - 1)
            return grid[i][j];
        
        int ijR = dfs(i, j+1, m, n, grid, iResult);
        int ijD = dfs(i+1, j, m, n, grid, iResult);
        int result = grid[i][j] + min(ijR, ijD);
        iResult.insert({pair, result});

        return result;
    }
};

