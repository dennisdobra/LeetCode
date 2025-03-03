class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /* Complexitate temp: O(n^2) */
        
        // int buy, sell, maxProfit = 0;
        // for (int i = 0; i < prices.size() - 1; i++) {
        //     for (int j = i + 1; j < prices.size(); j++) {
        //         if (prices[j] - prices[i] > maxProfit) {
        //             maxProfit = prices[j] - prices[i];
        //             buy = i;
        //             sell = j;
        //         }
        //     }
        // }

        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else if (prices[i] - minPrice > maxProfit) {
                maxProfit = prices[i] - minPrice;
            }
        }

        return maxProfit;
    }
};