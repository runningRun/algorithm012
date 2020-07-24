class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentResult(nums.size());
        set<int> usedIndex; // 记录已经被使用元素的下标
        _myPermute(0, nums.size(), usedIndex, nums, currentResult, result);
        return result;
    }

private:
    void _myPermute(int level, int maxLevel, set<int> &usedIndex, vector<int> &nums, vector<int> &currentResult, vector<vector<int>> &result) {
        // 终止条件
        if (level == maxLevel) {
            result.push_back(currentResult);
            return ;
        }

        for (int index = 0; index < nums.size(); ++index) {
            if (usedIndex.find(index) == usedIndex.end()) {
                // 本层处理
                currentResult[level] = nums[index];
                usedIndex.insert(index);
                // 进入下一层
                _myPermute(level + 1, maxLevel, usedIndex, nums, currentResult, result);
                // 本层清理
                usedIndex.erase(usedIndex.find(index));
            }
        }

    }

};