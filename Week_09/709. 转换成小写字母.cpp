class Solution {
public:
    string toLowerCase(string str) {
        for (char &ch : str) {
            if (ch >= 'A' && ch <= 'Z')
                ch |= 32;
        }
        return str;
    }
};