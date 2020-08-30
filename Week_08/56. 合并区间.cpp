class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        if (intervals.empty() || intervals[0].empty())
            return result;
        sort(intervals.begin(), intervals.end(), verctorCmp);

        int bIndex = intervals[0][0];
        int eIndex = intervals[0][1];
        for (int ii = 1; ii < intervals.size(); ++ii) {
            int tB = intervals[ii][0];
            int tE = intervals[ii][1];
            if (tB > eIndex || tE < bIndex) {
                result.push_back({bIndex, eIndex});
                bIndex = tB;
                eIndex = tE;
            } else {
                bIndex = min(bIndex, tB);
                eIndex = max(eIndex, tE);
            }
        }
        result.push_back({bIndex, eIndex});
        return result;
    }
private:
    struct _verctorCmp {
        bool operator() (vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        }
    } verctorCmp;
};