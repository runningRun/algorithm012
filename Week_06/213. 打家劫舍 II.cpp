/*
 *1. 如果打劫nums[0]，nums[1]、nums[n-1]均不能再被打劫，剩余打劫空间为nums[2...n-2]，这部分就完全变成了198.打家劫舍
 *2. 如果不打劫nums[0], 则nums[1]和nums[n-1]均不受影响，此时剩余打劫空间为nums[1...n-1], 这部分也完全成了198问题
 * 
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int result = nums[0];
        switch(nums.size()) {
            case 1: 
                result = nums[0];
                break;
            case 2:
                result = max(nums[0], nums[1]);
                break;
            case 3:
                result = max(max(nums[0], nums[1]), nums[2]);
                break;
            default:
                // 取了nums[0],则nums[1]和nums[n-1]都不能取，可以正常取nums[2...n-2]
                int rob0 = rob(nums, 2, nums.size() - 1) + nums[0]; 
                cout << "rob0 result: " << rob0 << endl;
                // 不取nums[0], 则nums[1...n-1]都可以正常取
                int nrob0 = rob(nums, 1, nums.size());
                cout << "nrob0 result: " << nrob0 << endl;

                result = max (rob0, nrob0);
                break;
        }

        return result;
    }

private:
    int rob(vector<int>& nums, int from, int end) {
        if (nums.empty())
            return 0;
        /*
         * dp[0][i] 不取nums[i]时，当前所窃金额最大值
         ** 因为不打算取nums[i], 所以nums[i-1]取没取，都可以，只需要取最大值
         ** dp[0][i] = max(dp[0][i-1], dp[1][i-1]);
         * dp[1][i] 取了nums[i]时，当前所窃金额最大值
         ** 如果要取nums[i]，所以只能nums[i-1]肯定不能取
         ** dp[1][i] = dp[0][i] + nums[i];
        */
        
        vector<vector<int>> dp(2, vector<int>(end - from, 0));   
        dp[0][0] = 0;
        dp[1][0] = nums[from];
        for (int i = 1; i+from < end; ++i) {
            dp[0][i] = max(dp[0][i-1], dp[1][i-1]);
            dp[1][i] = dp[0][i-1] + nums[i+from];

            // cout << i+from << " 结果: " << "不取, " << dp[0][i] << "; 取, " << dp[1][i] << endl;
        }

        return max(dp[0][end-from-1], dp[1][end-from-1]);
    }
};