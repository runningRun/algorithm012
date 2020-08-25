class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.empty() || 1 == nums.size())
            return 0;
        if (nums[0] >= nums.size() - 1)
            return 1;

        cout << "nums.size(): " << nums.size() << endl;
        int result = 0;
        int maxPos = 0;
        queue<pair<int, int>> nodes;
        vector<bool > visited(nums.size(), false);
        
        for (int ii = 1; ii <= nums[0]; ++ii) {
            nodes.push({ii, nums[ii]});
        }
        maxPos = nums[0];
        result = 1;
        while (!nodes.empty()) {
            int nodesCount = nodes.size();
            result += 1;
            for (int ii = 0; ii < nodesCount; ++ii) {
                int index = nodes.front().first;
                int step = nodes.front().second;
                nodes.pop();
                if (index + step >= nums.size() - 1)
                    return result;
                if (index + step <= maxPos)
                    continue;

                for (int ii = maxPos; ii <= index + step; ++ii) {
                    if (visited[ii])
                        continue;
                    nodes.push({ii, nums[ii]});
                    visited[ii] = true;
                }
                maxPos = index + step;
            }
        }
        return -1;
    }
};