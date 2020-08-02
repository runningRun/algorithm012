class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int index = 0;
        int jIndex = 0;
        while (index < g.size() && jIndex < s.size()) {
            if (g[index] <= s[jIndex]) {
                index += 1;
            }
            jIndex += 1;
        }
        return index;
    }
};