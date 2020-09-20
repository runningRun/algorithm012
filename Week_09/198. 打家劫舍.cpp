class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        } else if (1 == nums.size()) {
            return nums[0];
        } else if (2 == nums.size()){
            return max(nums[0], nums[1]);
        }

        // profix[i][0] 表示不打劫第i家可获得的收益
        // profix[i][1] 表示打劫第i家可获得的收益
        vector<vector<int>> profit(nums.size(), vector<int>(2, 0));
        profit[0][0] = 0;
        profit[0][1] = nums[0];
        for (int ii = 1; ii < nums.size(); ++ii) {
            profit[ii][0] = max(profit[ii-1][0], profit[ii-1][1]);
            profit[ii][1] = profit[ii-1][0] + nums[ii];
        }
        return max(profit[nums.size()-1][0], profit[nums.size()-1][1]);
    }
};