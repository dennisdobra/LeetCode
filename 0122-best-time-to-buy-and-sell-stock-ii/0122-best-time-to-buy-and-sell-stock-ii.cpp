class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, stock;
        bool baught = false;

        for (int i = 0; i < prices.size() - 1; i++) {
            // wait (can't sell)
            if (prices[i] > prices[i + 1] && baught == false) {
                continue;
            }

            // prices are going up => buy
            if (prices[i] < prices[i + 1] && baught == false) {
                stock = prices[i];
                baught = true;
                // continue;
            }

            // the price is going down => sell the stock
            if (prices[i] > prices[i + 1] && baught == true) {
                maxProfit += prices[i] - stock;
                baught = false;
            }

            if (i + 1 == prices.size() - 1 && baught == true) {
                maxProfit += prices[i + 1] - stock;
            }
        }

        return maxProfit;
    }
};