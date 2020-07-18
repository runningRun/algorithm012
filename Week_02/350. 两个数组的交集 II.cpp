/*
 * multiset
 */
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        multiset<int> nums1Set(nums1.begin(), nums1.end());
        for (int index = 0; index < nums2.size(); ++index) {
            auto it = nums1Set.find(nums2[index]);
            if ( it != nums1Set.end()) {
                result.push_back(nums2[index]);
                nums1Set.erase(it);
            }
        }
        return result;
    }
};