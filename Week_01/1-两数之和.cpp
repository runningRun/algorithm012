class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int y = 0;
        vector<int> result;
        for (int index = 0; index < nums.size(); ++index) {
            y = target - nums[index];
            for (int jIndex = index + 1; jIndex < nums.size(); ++jIndex) {
                if (nums[jIndex] == y) {
                    result.push_back(index);
                    result.push_back(jIndex);
                    return result;
                }
            }
        }

        return result;
    }
};