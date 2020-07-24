class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> currentResult(nums.size());
        set<int> usedIndex; // 记录已经被使用元素的下标
        set<string> resultSet; // 将结果转换为string，然后计入set中，用于结果去重
        _myPermute(0, nums.size(), usedIndex, nums, currentResult, result, resultSet);
        return result;
    }

private:
    void _myPermute(int level, int maxLevel, set<int> &usedIndex, vector<int> &nums, vector<int> &currentResult, vector<vector<int>> &result, set<string> &resultSet) {
        // 终止条件
        if (level == maxLevel) {

            // 使用stringstream 将结果组织成字符串
            stringstream strStream;
            for (int ele : currentResult) {
                strStream << ele;
            }
            string strResult = strStream.str();
            if (resultSet.find(strResult) == resultSet.end()) {
                // cout << "result str: " << strResult << endl;
                result.push_back(currentResult);
                resultSet.insert(strResult);
            }
            return ;
        }

        for (int index = 0; index < nums.size(); ++index) {
            if (usedIndex.find(index) == usedIndex.end()) {
                // 本层处理
                currentResult[level] = nums[index];
                usedIndex.insert(index);
                // 进入下一层
                _myPermute(level + 1, maxLevel, usedIndex, nums, currentResult, result, resultSet);
                // 本层清理
                usedIndex.erase(usedIndex.find(index));
            }
        }

    }
};

/*
 * 待验证方法
 * 作者：da-li-wang
 * 链接：https://leetcode-cn.com/problems/permutations-ii/solution/c-jian-dan-hui-su-by-da-li-wang/
 * 来源：力扣（LeetCode）
 * 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
    void backtrace(map<int, int>& m, int k, int n,
                   vector<int>& v, vector<vector<int> >& res) {
        if (k == n) {
            res.push_back(v);
            return;
        }
        for (auto& p : m) {
            if (p.second == 0) continue;
            --p.second;
            v.push_back(p.first);
            backtrace(m, k + 1, n, v, res);
            ++p.second;
            v.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map<int, int> m;
        for (auto x : nums) ++m[x];
        vector<vector<int> > res;
        vector<int> v;
        backtrace(m, 0, nums.size(), v, res);
        return res;
    }
};