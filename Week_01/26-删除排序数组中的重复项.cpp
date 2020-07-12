class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2)
            return nums.size();
        int index = 0;
        int jIndex = 0;
        for (index = 1; index < nums.size(); ++index) {
            if (nums[index] != nums[jIndex]) {
                nums[++jIndex] = nums[index];
            }
        }
        return jIndex + 1;
    }
};