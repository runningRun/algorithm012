class Solution1 {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        } else if (1 == nums.size()) {
            return nums[0];
        } else if (2 == nums.size()) {
            return max(nums[0], nums[1]);
        }
        
        /*
         * dp[0][i] 不取nums[i]时，当前所窃金额最大值
         ** 因为不打算取nums[i], 所以nums[i-1]取没取，都可以，只需要取最大值
         ** dp[0][i] = max(dp[0][i-1], dp[1][i-1]);
         * dp[1][i] 取了nums[i]时，当前所窃金额最大值
         ** 如果要取nums[i]，所以只能nums[i-1]肯定不能取
         ** dp[1][i] = dp[0][i] + nums[i];
        */
        vector<vector<int>> dp(2, vector<int>(nums.size(), 0));   
        dp[0][0] = 0;
        dp[1][0] = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            dp[0][i] = max(dp[0][i-1], dp[1][i-1]);
            dp[1][i] = dp[0][i-1] + nums[i];

            // cout << i << " 结果: " << "不取, " << dp[0][i] << "; 取, " << dp[1][i] << endl;
        }

        return max(dp[0][nums.size()-1], dp[1][nums.size()-1]);
    }
};


/*
 * 使用DFS，不打劫nums[i]，下一步就从nums[i+1]开始
 * 打劫nums[i],则只能从nums[i+2]开始了
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        } else if (1 == nums.size()) {
            return nums[0];
        } else if (2 == nums.size()) {
            return max(nums[0], nums[1]);
        }

        vector<int> mem(nums.size(), -1);

        return dfs(0, nums, mem);
    }

private:
    int dfs(int start, vector<int> &nums, vector<int> &mem) {
        if (start >= nums.size())
            return 0;
        if (-1 == mem[start])
            mem[start] = max(dfs(start+1, nums, mem), nums[start] + dfs(start+2, nums, mem));
        return mem[start];
    }
};