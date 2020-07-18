/*
 * 参考题解：https://leetcode-cn.com/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/solution/mian-shi-ti-59-i-hua-dong-chuang-kou-de-zui-da-1-6/
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        if (nums.size() < k) {
            vector<int> emptyVec = {};
            return emptyVec;
        }
        
        vector<int> result(nums.size() - k + 1);
        deque<int> kWindow(k);
        int numsSize = nums.size();
        int index = 0;
        for (index = 0; index < k; ++index) {
            while (!kWindow.empty() && kWindow.back() < nums[index])
                kWindow.pop_back();
            kWindow.push_back(nums[index]);
        }
        result[0] = kWindow.front();

        for (index = k; index < numsSize; ++index) {
            if (kWindow.front() == nums[index - k])
                kWindow.pop_front();
            while (!kWindow.empty() && kWindow.back() < nums[index])
                kWindow.pop_back();
            kWindow.push_back(nums[index]);
            result[index - k + 1] = kWindow.front();
        }

        return result;
    }
};

/*
 *
 *  while (!kWindow.empty() && kWindow.back() <= nums[index])
        kWindow.pop_back();
    如果使用 <= 来删除kWindow的队尾元素，则
    输入：[-7,-8,7,5,7,1,6,0] 
          4
    输出：[7,7,7,6,6]
    预期：[7,7,7,7,7]
    
    原因是下标为nums[4]为7，会把kWindow里面的nums[2]的7冲掉
    并且当index == 6时，此时kWindow中7是nums[4]的7，但由于
    kWindow.front() == nums[index - k]，所以会kWindow.pop_front()
    导致kWindow中没有7
 *
 *   for (index = k; index < nums.size(); ++index) {
        if (kWindow.size() == k)
            kWindow.pop_front();
        while (!kWindow.empty() && kWindow.back() <= nums[index])
            kWindow.pop_back();
        kWindow.push_back(nums[index]);
        result[index - k + 1] = kWindow.front();
    }

    如果依靠 kWindow.size() == k 来删除头元素，则案例
    输入：[1,3,1,2,0,5]
          3
    输出：[3,3,3,5]
    预期：[3,3,2,5]

    原因是2进入时，会把1从队列尾部移除，0 进入前，kWindow中元素为：3，2
    结果0再进入时，kWindow.front()仍然是3，所以通过 
    kWindow.front() == nums[index - k]滤除“过期”的3
    
 * 
 * 
*/