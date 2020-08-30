class Solution {
public:
    /*
      x 和 y = x / 2的二进制关系
      只有最低位的不同
    */
    vector<int> countBits1(int num) {
        vector<int> result(num + 1, 0);
        if (num < 1)
            return result;
        result[0] = 0;
        result[1] = 1;
        for (int ii = 2; ii <= num; ++ii) {
            result[ii] = result[ii / 2] + (ii % 2);
        }
        return result;
    }

    /*
     x & (x - 1)将最右边为1的bit位置为0
    */
    vector<int> countBits2(int num) {
        vector<int> result(num + 1, 0);
        if (num < 1)
            return result;
        result[0] = 0;
        result[1] = 1;
        for (int ii = 2; ii <= num; ++ii) {
            result[ii] = result[ii & (ii - 1)] + 1;
        }
        return result;
    }

    vector<int> countBits(int num) {
        vector<int> result(num + 1, 0);
        if (num < 1)
            return result;
        result[0] = 0;
        result[1] = 1;
        for (int ii = 2; ii <= num; ++ii) {
            result[ii] = result[ii >> 1] + (ii & 0x00000001);
        }
        return result;
    }
};