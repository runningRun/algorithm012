class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;
        int result = 0;
        vector<int> LISLength(nums.size() + 1, 0);
        for (int ii = nums.size() - 1; ii >= 0; --ii) {
            int lis = 0;
            for (int jj = ii; jj < nums.size(); ++jj) {
                if (nums[ii] < nums[jj]) 
                    lis = max(lis, LISLength[jj]);
            }
            LISLength[ii] = (1 + lis);
            result = max(result, LISLength[ii]);
        }
        return result;
    }
};