class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        result.push_back(vector<int>());
        result.push_back(nums);
        sort(nums.begin(), nums.end());
        for (int ii = 1; ii < nums.size(); ++ii) {
            vector<int> iResult(ii, 0);
            backtrack(0, ii, 0, nums, iResult, result);
        }
        return result;
    }

private:
    void backtrack(int level, int maxLevel, int index, vector<int> &nums, vector<int> &iResult, vector<vector<int>> &result) {
        if (level == maxLevel) {
            result.push_back(iResult);
            return ;
        }

        for (int ii = index; ii < nums.size(); ++ii) {
            iResult[level] = nums[ii];
            backtrack(level + 1, maxLevel, ii + 1, nums, iResult, result);
            while (ii < nums.size() - 1 && nums[ii] == nums[ii + 1])
                ++ii;
        }

    }
};