class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
            return 0;
        int minPrice = INT_MAX;
        int result = INT_MIN;
        for (int ii = 0; ii < prices.size(); ++ii) {
            result = max(result, prices[ii] - minPrice);
            if (prices[ii] < minPrice)  {
                minPrice = prices[ii];
            }
        }
        if (result < 0)
            result = 0;
        return result;
    }
};