class Solution {
public:
    int search(vector<int>& nums, const int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            if (target == nums[mid])
                return mid;
            else if (nums[mid] >= nums[left]) {
                // 左半部分有序递增
                if (target > nums[mid] || target < nums[left]) {
                    // 不在左半部分
                    left = mid + 1;
                } else {
                    // nums[left] <= taget < nums[mid]
                    right = mid - 1;
                }
            } else {
                // 右半部分有序递增
                if (target > nums[right] || target < nums[mid]) {
                    right = mid - 1;
                } else {
                    // nums[mid] < target <= nums[right]
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};