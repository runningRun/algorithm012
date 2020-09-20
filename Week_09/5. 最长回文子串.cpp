class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2)
            return s;
        int startIndex = 0;
        int maxLen = 1;
        for (int ii = 0; ii < s.size(); ++ii) {
            expandPalindrome(ii, ii, s, startIndex, maxLen);
            expandPalindrome(ii, ii + 1, s, startIndex, maxLen);
        }
        return s.substr(startIndex, maxLen);
    }

    void expandPalindrome(int j, int k, string &s, int &si, int &len) {
        while (j >= 0 && k < s.size() && s[j] == s[k]) {
            --j;
            ++k;
        }
        // j += 1;
        // k -= 1;
        // if (k - j + 1 > len) {
        //     si = j;
        //     len = k - j + 1;
        // }
        if (k - j - 1 > len) {
            si = j + 1;
            len = k - j - 1;
        }
        // cout << "[" << j << ", " << k << "]" << endl;
    }
};