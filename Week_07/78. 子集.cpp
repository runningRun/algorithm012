class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<bool> visited(nums.size(), false);
        vector<vector<int>> result;
        result.push_back(vector<int>());
        result.push_back(nums);
        for (int ii = 1; ii < nums.size(); ++ii) {
            vector<int> iResult(ii, 0);
            backtrack(0, ii, 0, nums, visited, iResult, result);
        }
        return result;
    }

private:
    void backtrack(int level, int maxLevel, int index, vector<int> &nums, vector<bool> &visited, vector<int> &iResult, vector<vector<int>> &result) {
        if (level == maxLevel) {
            result.push_back(iResult);
            return ;
        }

        for (int ii = index; ii < nums.size(); ++ii) {
            iResult[level] = nums[ii];
            backtrack(level + 1, maxLevel, ii + 1, nums, visited, iResult, result);
        }

    }
};