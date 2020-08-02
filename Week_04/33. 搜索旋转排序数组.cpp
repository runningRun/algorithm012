class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while (left <= right) {
            mid = (left + right) / 2;
            cout << "left: " << left << " right: " << right << " mid: " << mid << endl;
            if (nums[mid] == target)
                return mid;
            // 非严格递增
            // [3,1], target = 1
            if (nums[mid] >= nums[left]) {
                // 左边有序递增
                if (nums[mid] < target) {
                    // 递增部分最右边元素小于目标元素
                    // 即[left...mid] < target
                    left = mid + 1;
                } else if (nums[left] > target) {
                    // 递增部分最左边元素大于目标元素
                    // 即[left...mid] > target
                    left = mid + 1;
                } else {
                    // 最左边元素小于目标元素
                    // 即[left...t] <= target and [t+1...mid] > target
                    right = mid - 1;
                }
            } else {
                // 右边有序递增
                if (nums[mid] > target) {
                    // 递增部分最左边元素大于目标元素
                    // 即[mid...right] > target
                    right = mid - 1;
                } else if (nums[right] < target) {
                    // 最右边元素小于目标元素
                    // 即[mid...right] < target
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};