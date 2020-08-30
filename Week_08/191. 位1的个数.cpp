class Solution {
public:
    int hammingWeight(uint32_t n) {
        if (0 == n) {
            return 0;
        }
        int count = 0;
        while (n > 0) {
            n = n & (n - 1);
            count += 1;
        }
        return count;
    }
};