class Solution {
public:
    double myPow(double x, int n) {
        if (0 == n || x == 1.00000f)
            return 1.0;
        return n > 0 ?  fastPow(x, n) : 1 / fastPow(x, -1 * (long long int)n); 
    }

private:
// x = 1.00000, n = -2147483648
    double fastPow(double x, long long int n) {
        if (0 == n)
            return 1.0f;
        double tmpResult = fastPow(x, n / 2);
        return 0 == n % 2 ? tmpResult * tmpResult : tmpResult * tmpResult * x;
    }
};