/*
 * 将str转换成'a' ~ 'z'的hash数组
*/
/*
 **执行用时：256 ms, 在所有 C++ 提交中击败了6.97%的用户**
 **内存消耗：20.7 MB, 在所有 C++ 提交中击败了21.74%的用户**
 */
 /*
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        string strHashValue;
        map<string, int> hashValueVecIndex;

        for (string str : strs) {
            strHashValue = getHashValue(str);
            auto it = hashValueVecIndex.find(strHashValue);
            if ( it != hashValueVecIndex.end()) {
                result[it->second].push_back(str);
            } else {
                hashValueVecIndex[strHashValue] = result.size();
                vector<string> vec = {str};
                result.push_back(vec);
            }
        }
        return result;
    }

    string getHashValue(string str) {
        int hash1[26] = {0};
        string hashStr("");

        for (int index = 0; index < str.size(); ++index) {
            hash1[str[index] - 'a'] += 1;
        }

        for (int index = 0; index < 26; ++index) {
            hashStr += to_string(hash1[index]);
            hashStr += 'a' + index;
        }

        return hashStr;

    }
};
*/

/*
 **执行用时：108 ms, 在所有 C++ 提交中击败了26.37%的用户
 **内存消耗：16.4 MB, 在所有 C++ 提交中击败了100.00%的用户
*/
/*
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> strEctopic;
        for (string str : strs) {
            string tmpStr(str);
            sort(tmpStr.begin(), tmpStr.end());
            auto it = strEctopic.find(tmpStr);
            if (it != strEctopic.end()) {
                strEctopic[tmpStr].push_back(str);
            } else {
                vector<string> tmpVec;
                tmpVec.push_back(str);
                strEctopic[tmpStr] = tmpVec;
            }
        }
        vector<vector<string>> result(strEctopic.size());
        int index = 0;
        for (auto it = strEctopic.begin(); it != strEctopic.end(); ++it) {
            result[index++] = it->second;
        }
        return result;
    }
};
*/

/*
 **  map<string, int> strResultIndex;**
 ** 执行用时：92 ms, 在所有 C++ 提交中击败了41.14%的用户
 ** 内存消耗：15.9 MB, 在所有 C++ 提交中击败了100.00%的用户
*/

/*
 ** unordered_map<string, int> strResultIndex;
 **执行用时：72 ms, 在所有 C++ 提交中击败了70.73%的用户
 **内存消耗：16 MB, 在所有 C++ 提交中击败了100.00%的用户
 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, int> strResultIndex;
        for (string str : strs) {
            string tmpStr(str);
            sort(tmpStr.begin(), tmpStr.end());
            auto it = strResultIndex.find(tmpStr);
            if (it != strResultIndex.end()) {
                result[strResultIndex[tmpStr]].push_back(str);
            } else {
                vector<string> tmpVec;
                tmpVec.push_back(str);
                strResultIndex[tmpStr] = result.size();
                result.push_back(tmpVec);
            }
        }
        return result;
    }
};


// 算术基本定理，又称为正整数的唯一分解定理，即：每个大于1的自然数，要么本身就是质数，要么可以写为2个以上的质数的积，而且这些质因子按大小排列之后，写法仅有一种方式。

// 利用这个，我们把每个字符串都映射到一个正数上。

// 用一个数组存储质数 prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103}。

// 然后每个字符串的字符减去 ' a ' ，然后取到 prime 中对应的质数。把它们累乘。

// 例如 abc ，就对应 'a' - 'a'， 'b' - 'a'， 'c' - 'a'，即 0, 1, 2，也就是对应素数 2 3 5，然后相乘 2 * 3 * 5 = 30，就把 "abc" 映射到了 30。

// 作者：windliang
// 链接：https://leetcode-cn.com/problems/group-anagrams/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by--16/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。