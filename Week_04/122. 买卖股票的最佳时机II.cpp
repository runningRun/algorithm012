class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int index = 0;
        for (index = 1; index < prices.size(); ++index) {
            if (prices[index] > prices[index - 1])
                res += (prices[index] - prices[index - 1]);
        }
        return res;
    }
};