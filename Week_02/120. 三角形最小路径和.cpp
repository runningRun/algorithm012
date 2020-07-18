class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> tmpMinPath = triangle[triangle.size() - 1];
        for (int index = triangle.size() - 2; index >= 0; --index) {
            for (int jIndex = 0; jIndex < index + 1; ++jIndex) {
                tmpMinPath[jIndex] = triangle[index][jIndex] + min(tmpMinPath[jIndex], tmpMinPath[jIndex + 1]);
            }
        }
        return tmpMinPath[0];
    }
};