class Solution {
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

/*
 * 使用vector记录解决方案
 * 但会超时
*/
class Solution {
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
        
        // 其实还是填格子，每个面额的硬币对应一个格子，
        // 格子里是几，就表示用几枚本种硬币
        // 回溯
        vector<int> countOfCoint(coins.size(), 0);
        vector<vector<int>> result;

        backTrace(0, amount, coins, countOfCoint, result);
        if (result.empty())
            return -1;
        int minCoins = INT_MAX;
        int tmpCount = 0;
        for (vector<int> &vec : result) {
            tmpCount = 0;
            for (int num : vec) {
                // cout << num << " ";
                tmpCount += num;
            }
            minCoins = min(tmpCount, minCoins);
            // cout << endl;
        }
        return minCoins;
    }

private:
    void backTrace(int index, int amount, vector<int> &coins, vector<int> &countOfCoint, vector<vector<int>> &result) {
        // cout << "index: " << index << " amount: " << amount << endl;
        // 结束条件
        if (0 == amount) {
            // 满足条件
            // 不需要再进行后续检测
            result.push_back(countOfCoint);
        }

        // 不满足条件，但也已经到结尾了
        if (index == coins.size()) {
            return;
        }

        int count = amount / coins[index];
        int left = amount % coins[index];
        int k = 0;
        while (k <= count) {
            countOfCoint[index] = count - k;
            backTrace(index + 1, left + k * coins[index], coins, countOfCoint, result);
            countOfCoint[index] = 0;
            k += 1;
        }
    }
};


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // [] 1 返回 -1
        // [] 0 返回 0
        // [1] 0 返回 0
        if (0 == amount )
            return 0;

        if (coins.empty())
            return -1;

        sort(coins.rbegin(), coins.rend()); // 降序
        int level = 0;
        int minCoins = INT_MAX;
        int tmpCount = 0;
        backTrace(0, amount, coins, minCoins, tmpCount);
        return minCoins == INT_MAX ? -1 : minCoins;
    }

private:
    void backTrace(int index, int amount, vector<int> &coins, int &minCoins, int tmpCount) {
        // cout << "index: " << index << " amount: " << amount << endl;
        // 结束条件
        if (0 == amount) {
            // 满足条件
            // 不需要再进行后续检测
            minCoins = min(minCoins, tmpCount);
        }

        // 不满足条件，但也已经到结尾了
        if (index == coins.size()) {
            return;
        }

        int count = amount / coins[index];
        /*
         * 本方式的精髓在于tmpCount + count < minCoins
         * 如果使用count个coins[index]时，硬币的数量已经超过了当前最小结果，count-1个coins[index]就更不用考虑了，
         * 因为coins[index+1] < coin[index]，少使用一个coins[index]只会增加更多的coins[index+1...n]
        */
        while (count >= 0 && tmpCount + count < minCoins) {
            backTrace(index + 1, amount - count * coins[index], coins, minCoins, tmpCount + count);
            count -= 1;
        }
    }
};


// [288,160,10,249,40,77,314,429]
// 9208
// [470,35,120,81,121]
// 9825
// [270,373,487,5,62]
// 8121
// [186,419,83,408]
// 6249
// [1,2,5]
// 11
// []
// 1
// []
// 0
// [1]
// 0
// [2]
// 1