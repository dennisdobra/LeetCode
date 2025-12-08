class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int max_profit = 0;

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                // found the best price to buy the stock
                minPrice = prices[i];
            } else if (prices[i] - minPrice > max_profit) {
                max_profit = prices[i] - minPrice;
            }
        }

        return max_profit;
    }
};