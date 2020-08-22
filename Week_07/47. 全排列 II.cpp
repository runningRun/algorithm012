class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<bool> visited(nums.size(), false);
        vector<int> iResult(nums.size(), 0);
        sort(nums.begin(), nums.end());
        _permute(0, nums.size(), visited, nums, iResult, result);
        return result;
    }

private:
    void _permute(int level, int maxLevel, vector<bool> &visited, vector<int> &nums, vector<int> &iResult, vector<vector<int>> &result) {
        if (level == maxLevel) {
            result.push_back(iResult);
            return ;
        }

        for (int index = 0; index < nums.size(); ++index) {
            if (!visited[index]) {
                visited[index] = true;
                // cout << "level: " << level << " try value: " << nums[index] << endl;
                iResult[level] = nums[index];
                _permute(level + 1, maxLevel, visited, nums, iResult, result);
                visited[index] = false;
                while (index < nums.size() - 1 && nums[index] == nums[index + 1])
                    ++index;
            }
        }
    }
};