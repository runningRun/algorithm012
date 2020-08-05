// 暴力超时
class Solution0 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for (int index = 0; index < nums.size(); ++index) {
            int tmpSum = 0;
            for (int jIndex = index; jIndex < nums.size(); ++jIndex) {
                tmpSum += nums[jIndex];
                if (tmpSum == k)
                    count += 1;
            }
        }
        return count;
    }
};

/*
 * 前缀和(前n项之和):
 * prefixSum[0] = nums[0]
 * prefixSum[1] = nums[0] + nums[1]
 * prefixSum[2] = nums[0] + nums[1] + nums[2]
 * ......
 * prefixSum[n] = nums[0] + nums[1] + nums[2] + ... + nums[n]
 * 区间 [i...j](包含nums[i]和nums[j]) 的sum[i...j] = prefixSum[j] - prefixSum[i] + nums[i]
 * 所以即 K = prefixSum[j] - prefixSum[i] + nums[i]
 * 使用hash_multimap(unordered_multimap)存储一份prefixSum，然后遍历prefixSum, 对于每个prefixSum[i]，查找与之对应的
 * prefixSum[j]的数量
 * !!!注：为了去除重复，这里强制j >= i
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if (0 == nums.size())
            return 0;

        int count = 0;
        vector<int> prefixSum(nums.size(), 0);
        unordered_map<int, vector<int>> prefixSumMap;
        // prefixSum[i] = nums[0] + nums[1] + ... nums[i];
        prefixSum[0] = nums[0];
        prefixSumMap[prefixSum[0]].push_back(0);
        for (int index = 1; index < nums.size(); ++index) {
            prefixSum[index] = prefixSum[index - 1] + nums[index];
            prefixSumMap[prefixSum[index]].push_back(index);
        }

        // k = prefixSum[j] - prefixSum[i] + nums[i];
        // prefixSum[j] = k + prefixSum[i] - nums[i];
        for (int index = 0; index < nums.size(); ++index) {
            int tmp = k + prefixSum[index] - nums[index];
            // cout << index << " ==> " << prefixSum[index] << " tmp: " << tmp << " map[tmp].size: " << prefixSumMap[tmp].size() << endl;
            {
                auto &indexVec = prefixSumMap[tmp];
                for (auto it = indexVec.begin(); it != indexVec.end(); ++it) {
                    if (index <= *it)
                        count += 1;
                }
            }
        }
        return count;
    }
};