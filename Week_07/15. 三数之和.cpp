class Solution {
public:
    vector<vector<int>> threeSum4dfs(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty() || nums.size() < 3)
            return result;

        vector<int> intervalResult(3, 0);
        sort(nums.begin(), nums.end());
        dfs(0, 3, 0, nums, intervalResult, result);
        return result;
    }

private:
    void dfs(int level, int maxLevel, int index, vector<int> &nums, vector<int> &iResult, vector<vector<int>> &result) {
        if (level == maxLevel) {
            if (iResult[0] + iResult[1] +iResult[2] == 0) {
                result.push_back(iResult);
            }
            return ;
        }
        for (int ii = index; ii < nums.size(); ++ii) {
            iResult[level] = nums[ii];
            if (iResult[0] + iResult[1] + iResult[2] <= 0)
                dfs(level+1, maxLevel, ii + 1, nums, iResult, result);
            while (ii < nums.size() - 1 && nums[ii] == nums[ii+1])
                ++ii;
        }
        iResult[level] = 0;
    }

public:
    vector<vector<int>> threeSum4map(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty() || nums.size() < 3)
            return result;
        sort(nums.begin(), nums.end());
        unordered_multimap<int, int> numsMap;
        for (int ii = 0; ii < nums.size(); ++ii) {
            numsMap.insert(pair<int, int>{nums[ii], ii});;
        }
        for (int ii = 0; ii < nums.size(); ++ii) {
            for (int jj = ii+1; jj < nums.size(); ++jj) {
                if (nums[ii] + nums[jj] <= 0) {
                    int n = -(nums[ii] + nums[jj]);
                    if (numsMap.find(n) != numsMap.end()) {
                        auto pp = numsMap.equal_range(n);
                        for (auto pb = pp.first; pb != pp.second ; ++pb) {
                            if (pb->second > jj) {
                                result.push_back({nums[ii], nums[jj], n});
                                break;
                            }
                        }                        
                    }
                }
                while (jj < nums.size() - 1 && nums[jj] == nums[jj+1])
                    ++jj;
            }
            while (ii < nums.size() - 1 && nums[ii] == nums[ii+1])
                ++ii;
        }
        return result;
    }

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.empty() || nums.size() < 3)
            return result;
        sort(nums.begin(), nums.end());

        for (int ii = 0; ii < nums.size(); ++ii) {
            if (nums[ii] > 0)
                break;
            int L = ii + 1;
            int R = nums.size() - 1;
            while (L < R) {
                int tmpSum = nums[ii] + nums[L] + nums[R];
                if (tmpSum == 0) {
                    result.push_back({nums[ii], nums[L], nums[R]});
                    while (L < R && nums[L] == nums[L + 1])
                        ++L;
                    while (L < R && nums[R] == nums[R - 1])
                        --R;
                    L += 1;
                    R -= 1;
                } else if (tmpSum < 0) {
                    L += 1;
                } else {
                    R -= 1;
                }
            }
            while (ii < nums.size() - 1 && nums[ii] == nums[ii+1])
                ++ii;
        }

        return result;
    }

};