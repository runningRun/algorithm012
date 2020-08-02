// 暴力
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (0 == nums.size())
            return 0;

        int index = 0;
        int result = nums[0];
        for (index = 0; index < nums.size() - 1; ++index) {
            if (nums[index] < nums[index + 1]) {
                continue;
            } else {
                result = nums[index + 1];
            }
        }
        return result;
    }
};

// 参考：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/solution/yi-wen-jie-jue-4-dao-sou-suo-xuan-zhuan-pai-xu-s-3/
/*
 * 1. 如果nums[left] <= nums[right] 则表示[left, right]已有序递增，所以直接返回nums[left]
 * 2. 如果nums[left] <= nums[mid] 则表示[left, mid]已经有序递增，最小值肯定不在该区间，最小值在[mid+1, right]查找
 * 3. 否则，[left, mid]不是有序区间，最小值在[left, mid]区间查找
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        if (0 == nums.size())
            return 0;

        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while (left <= right) {
            if (nums[left] <= nums[right]) {
                return nums[left];
            }
            mid = (left + right) / 2;
            cout << "left: " << left << " right: " << right << " mid: " << mid << endl;
            if (nums[left] <= nums[mid]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return nums[right];
    }
};