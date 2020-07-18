class Solution {
public:
    int addDigits(int num) {
        int result = num;
        while (num >= 10) {
            result = 0;
            while (num >= 10) {
                result += (num % 10);
                num /= 10;
            }
            result += num;
            num = result;
        }
        return result;
    }
};