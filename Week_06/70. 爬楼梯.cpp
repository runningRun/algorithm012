class Solution {
public:
    // 自顶向下 + 记忆化
    int climbStairs1(int n) {
        if (n <= 1)
            return n;
        vector<int> memo(n+1, 0);
        return dfs(n, memo);
    }

    // 自底向上f[i] = f[i-1] + f[i-2]
    int climbStairs(int n) {
        if (0 == n || 1 == n)
            return 1;
        vector<int> memo(n+1, 0);
        memo[0] = 1;
        memo[1] = 1;
        for (int ii = 2; ii <= n; ++ii) {
            memo[ii] = memo[ii - 1] + memo[ii - 2];
        }

        return memo[n];
    }
    int climbStairs2(int n) {
        if (0 == n || 1 == n)
            return 1;
        int i0 = 1;
        int i1 = 1;
        
        int result = 0;
        for (int ii = 2; ii <= n; ++ii) {
            result = i0 + i1;
            int tmp = i0;
            i0 = i1;
            i1 = tmp + i1;    
        }
        return result;
    }

private:
    int dfs(int level, vector<int> &memo) {
        // !!!!!!!!!!!!  注，此处level为0时返回1  !!!!!!!!!!!!!!!!
        if (1 == level || 0 == level) {
            return 1;
        }
        if (0 != memo[level])
            return memo[level];
        return memo[level] = dfs(level - 1, memo) + dfs(level - 2, memo);

    }

};