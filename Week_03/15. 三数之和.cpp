class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    int tmpSum = 0;
    sort(nums.begin(), nums.end());
    for (int index = 0; index < nums.size(); ++index) {
      if (nums[index] > 0)
        break;

      if (index > 0 && nums[index] == nums[index - 1])
        continue;
      int lIndex = index + 1;
      int rIndex = nums.size() - 1;
      while (lIndex < rIndex) {
        tmpSum = nums[index] + nums[lIndex] + nums[rIndex];
        if (0 == tmpSum) {
          // cout << "index: " << index << " lIndex: " << lIndex << " rIndex: " << rIndex << endl;
            result.push_back({nums[index], nums[lIndex], nums[rIndex]});
            while (lIndex < rIndex && nums[lIndex] == nums[lIndex + 1])
              lIndex += 1;
            while (lIndex < rIndex && nums[rIndex] == nums[rIndex - 1])
              rIndex -= 1;
            lIndex += 1;
            rIndex -= 1;
        } else if (tmpSum < 0) {
          // **注: 此处虽然可以减少重复，不过并不能加快运行速度**
          while (lIndex < rIndex && nums[lIndex] == nums[lIndex + 1])
            lIndex += 1;
          lIndex += 1;
        } else {
          // **注: 此处虽然可以减少重复，不过并不能加快运行速度**
          while (lIndex < rIndex && nums[rIndex] == nums[rIndex - 1])
            rIndex -= 1;
          rIndex -= 1;
        }
      }
    }
    return result;
  }
};

// 参考https://leetcode.com/problems/3sum/discuss/7402/Share-my-AC-C%2B%2B-solution-around-50ms-O(N*N)-with-explanation-and-comments
class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int tmpSum = 0;
        sort(nums.begin(), nums.end());
        for (int index = 0; index < nums.size(); ++index) {
            if (nums[index] > 0)
                break;

            int lIndex = index + 1;
            int rIndex = nums.size() - 1;
            while (lIndex < rIndex) {
                tmpSum = nums[index] + nums[lIndex] + nums[rIndex];
                if (0 == tmpSum) {
                    // cout << "index: " << index << " lIndex: " << lIndex << " rIndex: " << rIndex << endl;
                    result.push_back({nums[index], nums[lIndex], nums[rIndex]});
                    while (lIndex < rIndex && nums[lIndex] == nums[lIndex + 1])
                        lIndex += 1;
                    while (lIndex < rIndex && nums[rIndex] == nums[rIndex - 1])
                        rIndex -= 1;
                    lIndex += 1;
                    rIndex -= 1;
                } else if (tmpSum < 0) {
                    lIndex += 1;
                } else {
                    rIndex -= 1;
                }
            }
            while (index + 1 < nums.size() && nums[index] == nums[index + 1])
                index += 1;
        }
        return result;
    }
};