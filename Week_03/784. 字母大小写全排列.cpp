
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> result;
        _myLetterCasePermutation(0, S.size(), S, result);
        return result;
    }

    void _myLetterCasePermutation(int startIndex, int maxSize, string &s, vector<string> &result) {
        if (startIndex == maxSize) {
            result.push_back(s);
            return ;
        }

        // 数字部分，直接进入下一层
        if (s[startIndex] >= '0' && s[startIndex] <= '9') {
            _myLetterCasePermutation(startIndex + 1, maxSize, s, result);
            return ;
        }

        // {
        //     // 跳过数字
        //     while (startIndex < s.size() && (s[startIndex] >= '0' && s[startIndex] <= '9'))
        //         ++startIndex;
        //     if (startIndex == s.size()) {
        //         result.push_back(s);
        //         return ;
        //     }
        // }
        char ch = s[startIndex];

        _myLetterCasePermutation(startIndex + 1, maxSize, s, result);
        if (ch >= 'A' && ch <= 'Z')
            s[startIndex] = ch + 32;
        else
            s[startIndex] = ch - 32;
        _myLetterCasePermutation(startIndex + 1, maxSize, s, result);

        s[startIndex] = ch;

    }
};


/*
 * 记录每个字母的位置，然后“填格子”：分别填上小写、大写字母
 */

class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<char> chs(S.size(), 0);
        vector<string> result;
        for (int index = 0; index < S.size(); ++index) {
            if (S[index] >= 'a' && S[index] <= 'z') {
                chs[index] = S[index];
            } else if (S[index] >= 'A' && S[index] <= 'Z') {
                chs[index] = S[index] + 32;
            }
        }
        _myLetterCasePermutation(0, S, chs, result);
        return result;
    }

private:
    void _myLetterCasePermutation(int startIndex, string &s, vector<char> &chs, vector<string> &result) {

        // cout << "start index: " << startIndex << " s: " << s << endl;

        if (startIndex == chs.size()) {
            result.push_back(s);
            return;
        }
        
        if (0 == chs[startIndex]) {
            // 如果本层是数字，则直接进入下一层
            _myLetterCasePermutation(startIndex + 1, s, chs, result);    
            return ;
        }

        {
            // 跳过数字，直到下一个字母
            // while (startIndex < chs.size() && (0 == chs[startIndex])) 
            //     ++startIndex;
            // if (startIndex == chs.size()) {
            //     result.push_back(s);
            //     return ;
            // }
        }

        s[startIndex] = chs[startIndex];
        _myLetterCasePermutation(startIndex + 1, s, chs, result);

        s[startIndex] = chs[startIndex] - 32;
        _myLetterCasePermutation(startIndex + 1, s, chs, result);

    }
};

// 参考官方题解 解法1https://leetcode-cn.com/problems/letter-case-permutation/solution/zi-mu-da-xiao-xie-quan-pai-lie-by-leetcode/
// 大小写转换 ch ^ 32
class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> result(1, "");
        int tmpSize = 0;
        char ch;

        for (int index = 0; index < S.size(); ++index) {
            ch = S[index];
            tmpSize = result.size();
            int ii = 0;
            if (ch >= '0' && ch <= '9') {
                for (ii = 0; ii < tmpSize; ++ii) {
                    result[ii].push_back(ch);
                }
            } else {
                for (ii = 0; ii < tmpSize; ++ii) {
                    string tmpStr = result[ii];
                    result[ii].push_back(ch);
                    tmpStr.push_back(ch ^ 32);
                    result.push_back(tmpStr);
                }
            }
        }
        return result;
    }
};