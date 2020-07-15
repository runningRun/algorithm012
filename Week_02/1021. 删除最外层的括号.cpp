/*
 * 思路：遍历字符串，遇到左括号就入栈，遇到右括号就出栈，每次栈空的时候，都说明找到了一个原语，记录下每个原语的起始位置和结束位置，
 *       取原字符串在原语的起始位置+1到原语的结束位置的子串便得到原语删除了最外层括号的字符串，拼接，即可解出答案。

作者：zi-mo-10
链接：https://leetcode-cn.com/problems/remove-outermost-parentheses/solution/chao-xiang-xi-ti-jie-si-lu-jie-zhu-zhan-yuan-yu-hu/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
    string removeOuterParentheses(string S) {
        int lParentheses = 0;
        int rParentheses = 0;
        int index = 0;
        int lIndex = 0;
        string result = "";

        for (; index < S.size(); ++index) {
            if (S[index] == '(')
                lParentheses += 1;
            else    //')'
                rParentheses += 1;

            if (rParentheses == lParentheses) {
                // cout << "lIndex: " << lIndex << " index: " << index << " str: " << S.substr(lIndex + 1, index - lIndex - 1) << endl;
                result += S.substr(lIndex + 1, index - lIndex - 1);
                lIndex = index + 1;
                // lParentheses = 0;
                // rParentheses = 0;
            }

        }

        return result;

    }
};

/*
    https://leetcode.com/problems/remove-outermost-parentheses/discuss/270022/JavaC%2B%2BPython-Count-Opened-Parenthesis
*/
class Solution {
public:
    string removeOuterParentheses(string S) {
        int open = 0;
        int index = 0;
        string result = "";

        for (; index < S.size(); ++index) {
            if ('(' == S[index] && open++ > 0)
                result += S[index];
            if (')' == S[index] && --open > 0) //')'
                result += S[index];
        }

        return result;

    }
};