class Solution {
public:
    // 2的幂次对应的二进制表示时，只有1位bit位为1
    // n & (n - 1)表示将最右边的bit置为0
    bool isPowerOfTwo1(int n) {
        if (0 == n)
            return false;
        long long x = n;
        long long nn = (long long)n - 1;
        return 0 == (x & nn);
    }

    // x & (-x) 表示只保留最右边bit位的1
    bool isPowerOfTwo(int n) {
        if (0 == n)
            return false;
        long long x = n;
        long long nn = -1 * (long long)n;
        return x == (x & nn);
    }
};

