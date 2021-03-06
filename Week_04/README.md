学习笔记
贪心算法：是一种在每一步选择中都采取在当前状态下最好或最优(即最有利)的选择，从而希望导致结果是全局最好或最优的算法
与动态规划的区别：
  贪心算法：对每个子问题的解决方案都做出选择，不能回退(能回退的话就成了回溯了)
  动态规划：会保存以前的运算结果，并根据以前的结果对当前进行选择，有回退功能

  贪心算法：当下做局部最优判断
  回溯：能够回退
  动态规划：最优判断 + 回退

二分查找前提：
  目标函数单调(递增或递减)
  存在上下界
  随机访问(索引访问)

```
// 使用二分查找，寻找一个半有序数组 [4, 5, 6, 7, 0, 1, 2] 中间无序的地方

/*
 * 1. 如果nums[left] <= nums[right] 则表示[left, right]已有序递增，所以直接返回nums[left]
 * 2. 如果nums[left] <= nums[mid] 则表示[left, mid]已经有序递增，最小值肯定不在该区间，最小值在[mid+1, right]查找
 * 3. 否则，[left, mid]不是有序区间，最小值在[left, mid]区间查找
 * 4. 最终right即为中间无序的断点
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
```