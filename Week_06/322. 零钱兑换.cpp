class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 1)
            return 0;
        // dp[i] 表示最小需要dp[i]枚硬币才能组成金额i
        vector<int> dp(amount + 1, amount+1);
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int &coin : coins) {
                if (i < coin)
                    continue;
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};


// 使用BFS
class Solution1 {
public:
    int coinChange(vector<int>& coins, int amount) {
        // [] 1 返回 -1
        // [] 0 返回 0
        // [1] 0 返回 0
        if (0 == amount )
            return 0;

        if (coins.empty())
            return -1;

        sort(coins.begin(), coins.end(), greater<int>()); // 降序
        if (amount < coins[coins.size() - 1]) // 比最小的硬币面值还小，肯定不行的嘛
            return -1;
        int level = 0;

        // BFS
        queue<int> intervalResult;
        unordered_map<int, bool> visited;

        intervalResult.push(amount);
        while (!intervalResult.empty()) {
            int tmpSize = intervalResult.size();
            level += 1;
            for (int index = 0; index < tmpSize; ++index) {
                int tmpValue = intervalResult.front();
                // cout << "tmpValue: " << tmpValue << endl;
                intervalResult.pop();
                for (int coin : coins) {
                    int aa = tmpValue - coin;
                    if (aa < 0 || visited.find(aa) != visited.end())
                        continue;
                        
                    if (aa == 0) {
                        return level;
                    }

                    intervalResult.push(aa);
                    visited.insert(pair<int, bool>(aa, true));
                }
            }
        }

        return -1;
    }
};