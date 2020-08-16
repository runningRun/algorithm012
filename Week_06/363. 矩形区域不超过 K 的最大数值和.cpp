// 使用“滚动”数组
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int maxSum = INT_MIN;
        int tmpSum = 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        // 以列为单位从左向右滚动
        // https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/solution/javacong-bao-li-kai-shi-you-hua-pei-tu-pei-zhu-shi/
        for (int l = 0; l < cols; ++l) {
           vector<int> rollSum(rows, 0);
           for (int r = l; r < cols; ++r) {
                for (int i = 0; i < rows; ++i) {
                    rollSum[i] += matrix[i][r];
                }
                maxSum = max(maxSubArray0(rollSum, k), maxSum);
                // cout << "l: " << l << " r: " << r << " sum: " << maxSum << endl;
           }
        }

        return maxSum;
    }

private:
    int maxSubArray0(vector<int>& nums, int k) {
        int max = INT_MIN;
        for (int l = 0; l < nums.size(); l++) {
            int sum = 0;
            for (int r = l; r < nums.size(); r++) {
                sum += nums[r];
                if (sum > max && sum <= k) 
                    max = sum;
                if (max == k)
                    return k; // 尽量提前
            }
        }
        return max;
    }
// 作者：lzhlyle
// 链接：https://leetcode-cn.com/problems/max-sum-of-rectangle-no-larger-than-k/solution/javacong-bao-li-kai-shi-you-hua-pei-tu-pei-zhu-shi/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
int maxSubArray(vector<int>& nums, int k) {
       if (nums.empty())
            return 0;
        int maxSum = INT_MIN;
        int tmpSum = 0;
        int tmpMaxSum = 0;
        for (int index = 0; index < nums.size(); ++index) {
            tmpSum = 0;
            tmpMaxSum = INT_MIN;
            for (int jIndex = index; jIndex < nums.size(); ++jIndex) {
                tmpSum += nums[jIndex];
                if (tmpMaxSum < tmpSum && tmpSum <= k)
                    tmpMaxSum = tmpSum;
            }
            // cout << "\tfrom: " << index << " tmpMaxSum: " << tmpMaxSum << " k: " << k << endl;
            if (maxSum < tmpMaxSum && tmpMaxSum <= k)
                maxSum = tmpMaxSum;
            // maxSum = max(maxSum, tmpMaxSum);
        }
        return maxSum;
    }
};