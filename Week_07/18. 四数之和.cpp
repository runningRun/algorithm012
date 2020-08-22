class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;

        if (nums.size() < 4)
            return result;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        int l = 0;
        int r = 0;
        for (int i1 = 0; i1 < size; ++i1) {
            for (int i2 = i1 + 1; i2 < size; ++i2) {
                l = i2 + 1;
                r = size - 1;
                while (l < r) {
                    int tmpSum = nums[i1] + nums[i2] + nums[l] + nums[r];
                    if (tmpSum == target) {
                        result.push_back({nums[i1], nums[i2], nums[l], nums[r]});
                        while (l < r && nums[l] == nums[l+1])
                            ++l;
                        while (l < r && nums[r] == nums[r-1])
                            --r;
                        l += 1;
                        r -= 1;
                    } else if (tmpSum < target) {
                        l += 1;
                    } else {
                        r -= 1;
                    }
                }
                while (i2 < size - 1 && nums[i2] == nums[i2+1])
                    ++i2;
            }
            while (i1 < size - 1 && nums[i1] == nums[i1+1])
                ++i1;
        }
        return result;
    }
};