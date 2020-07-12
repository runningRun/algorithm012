class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index = 0;
        int jIndex = 0;
        int numsSize = nums.size();
        for (; index < numsSize; ++index) {
            if (0 != nums[index]) {
                nums[jIndex++] = nums[index];
            }
        }
        for (; jIndex < numsSize; ++jIndex) {
            nums[jIndex] = 0;
        }

        // for (index = 0; index < numsSize; ++index) {
        //     std::cout << nums[index] << " " ;
        // }
        // std::cout << std::endl;
    }
};