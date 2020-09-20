class Solution {
public:
    string reverseStr(string s, int k) {
        if (s.empty())
            return s;
        _reverseStr(s, 0, s.size(), k);
        return s;
    }
private:
    void _reverseStr(string &s, int index, int length, int k) {
        int l = index;
        int r = length - 1;
        
        if (length - index >= k) {
            // 翻转[index, index + k - 1]
            r = index + k - 1;
        }
        // cout << "index: " << index << " l: " << l << " r: " << r << endl;
        for (; l <= r; ++l, --r) {
            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
        }
        // cout << "start index: " << index << " after reverse: " << s << endl; 
        if (length - index < 2 * k)
            return ;
        _reverseStr(s, index + 2 * k, length, k);
    }
};