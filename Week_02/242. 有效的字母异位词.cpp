class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        int sArray[26] = { 0 };
        int tArray[26] = { 0 };
        int index = 0;
        int size = s.size();
        for (; index < size; ++index) {
            sArray[s[index] - 'a'] += 1;
            tArray[t[index] - 'a'] += 1;
        }

        for (index = 0; index < 26; ++index) {
            if (sArray[index] != tArray[index])
                return false;
        }
        return true;
    }
};

/*
 * 使用字符计数
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;

        int sArray[26] = { 0 };
        int index = 0;
        int size = s.size();
        for (; index < size; ++index) {
            sArray[s[index] - 'a'] -= 1;
            sArray[t[index] - 'a'] += 1;
        }

        for (index = 0; index < 26; ++index) {
            if (sArray[index] != 0)
                return false;
        }
        return true;
    }
};