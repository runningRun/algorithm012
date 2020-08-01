// class Solution {
// public:
//     bool isPerfectSquare(int num) {
//         long long i = 1;
//         while (i * i < num) {
//             i += 1;
//         }
//         return i * i == num ;
//     }
// };

/*
 * https://leetcode-cn.com/problems/valid-perfect-square/solution/ceng-ceng-di-jin-zhu-bu-zui-you-de-si-chong-jie-fa/
 * 1 + 3 + 5 + ... + 2n - 1 == n^2
 */
class Solution {
public:
    bool isPerfectSquare(int num) {
        long i = 1;
        long sum = 0;
        while (sum < num) {
            sum += i;
            i += 2;
        }

        return sum == num;
    }
};


/*
 * !!!!!!!!!!!!! i and sum must be type long or long long !!!!!!!!!!!!!!!!!!!!!
 */