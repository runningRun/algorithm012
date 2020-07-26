class Solution {
public:
    int totalNQueens(int n) {
        int result = 0;
        vector<string> tmpResult(n, string(n, '.'));
        _mySolveNQueens(0, n, tmpResult, result);
        return result;
    }

private:
    void _mySolveNQueens(int level, int maxLevel, vector<string> &tmpResult, int &result) {
        // cout << "level: " << level << endl;
        // for (string str : tmpResult) {
        //     cout << str << endl;
        // }
        // cout << endl;

        // 结束条件
        if (level == maxLevel) {
            result += 1;
            return ;
        }

        string &tmpLevel = tmpResult[level];
        for (int index = 0; index < tmpLevel.size(); ++index) {
            // 本层处理
            tmpLevel[index] = 'Q';
           
            if (isValid(level, index, tmpResult)) {
                // cout << "level: " << level << " index: " << index << " set to Q " << " [OK]!" << endl;
                // 进入下一层
                _mySolveNQueens(level + 1, maxLevel, tmpResult, result);
            } else {
                // cout << "level: " << level << " index: " << index << " set to Q " << " [INVALID]!" << endl;
            }

            // 本层清理
            tmpLevel[index] = '.';
        }
    }

    bool isValid(int level, int index, const vector<string> tmpResult) {
        int cLevel = 0;
        int lIndex = index - 1;
        int rIndex = index + 1;

        // column
        for (int cLevel = 0; cLevel < level; ++cLevel) {
            if ('Q' == tmpResult[cLevel][index]) {
                // cout << "test column, [" << cLevel << ", " << index << "] has set Q. INVALID!" << endl;
                return false;
            }
        }

        // left-top
        cLevel = level - 1;
        while (cLevel >= 0 && lIndex >= 0) {
            if ('Q' == tmpResult[cLevel][lIndex]) {
                // cout << "test left-top, [" << cLevel << ", " << lIndex << "] has set Q. INVALID!" << endl;
                return false;
            }
            cLevel -= 1;
            lIndex -= 1;
        }

        // right-top
        cLevel = level - 1;
        while (cLevel >= 0 && rIndex < tmpResult[level].size()) {
            if ('Q' == tmpResult[cLevel][rIndex]) {
                // cout << "test rigth-top, [" << cLevel << ", " << rIndex << "] has set Q. INVALID!" << endl;
                return false;
            }
            cLevel -= 1;
            rIndex += 1;
        }

        return true;
    }
};