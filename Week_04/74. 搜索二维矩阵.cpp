class Solution1 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
         * 1. 缩小查找范围为某一行
         *  a. matrix[i][0] < target && matrix[i+1][0] >= target
         *  b. 在第i行查找
        */
        if (matrix.empty() || matrix[0].empty()) 
            return false;
        else if (matrix[0][0] > target)
            return false;
        else if (matrix[0][0] == target)
            return true;

        int index = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        
        while (index < m && matrix[index][0] < target) {
            // cout << "matrix[" << index << ", 0] " << matrix[index][0] << endl;
            index += 1;
        }

        if (index < m && matrix[index][0] == target)
            return true;
        
        index -= 1;

        int left = 0;
        int right = n - 1;
        int mid = 0;
        // cout << "search in line: " << index << endl;
        vector<int> &vec = matrix[index];
        while (left <= right) {
            mid = (left + right) / 2;
            if (vec[mid] == target)
                return true;
            else if (vec[mid] < target)
                left = mid + 1;
            else 
                right = mid - 1;
        }
        return false;

    }
};

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
         * 1. 缩小查找范围为某一行
         *  a. matrix[i][0] < target && matrix[i+1][0] >= target
         *  b. 在第i行查找
        */
        if (matrix.empty() || matrix[0].empty()) 
            return false;
        else if (matrix[0][0] > target)
            return false;

        int index = 0;
        int m = matrix.size();
        int n = matrix[0].size();

        // 此处不能写成matrix[index++][0] < target
        // 因为如果matrix[index][0] >= target, 此时index仍然会 +1
        // 从而导致matrix[index - 1] 不再是target所在行
        while (index < m && matrix[index][0] < target) {
            index += 1;
        }

        if (index < m && matrix[index][0] == target)
            return true;
        
        index -= 1;

        int left = 0;
        int right = n - 1;    // 应该包含右边界
        int mid = 0;
        vector<int> &vec = matrix[index];
        
        // [left, right] 左右边界都包含
        while (left <= right) {
            mid = (left + right) / 2;
            if (vec[mid] == target)
                return true;
            else if (vec[mid] < target)
                left = mid + 1;
            else 
                right = mid - 1;
        }
        return false;

    }
};

/*
 * a. 每行中的整数从左到右按升序排列。
 * b. 每行的第一个整数大于前一行的最后一个整数。
 * 可以将其看出一个有序的m * n个元素的一维数组，然后强制使用二分查找
 * 只是x = mid / n; y = mid % n;
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
         * 1. 强行二分查找
        */
        if (matrix.empty() || matrix[0].empty()) 
            return false;

        int m = matrix.size();
        int n = matrix[0].size();
        int mid = 0;
        int left = 0;
        int right = m * n - 1;

        while (left <= right) {
            mid = (left + right) / 2;
            int x = mid / n;
            int y = mid % n;
            cout << "left: " << left << " right: " << right << " mid: " << mid;
            cout << " matrix[" << x << ", " << y << "] = " << matrix[x][y] << endl;
            if (matrix[x][y] == target)
                return true;
            else if (matrix[x][y] < target) 
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};

// [[1]]
// 0
// [[1],[3]]
// 3
// [[1]]
// 2
// [[1]]
// 1
// [[1,   3,  5,  7],[10, 11, 16, 20],[23, 30, 34, 50]]
// 3
// [[1,   3,  5,  7],[10, 11, 16, 20],[23, 30, 34, 50]]
// 13