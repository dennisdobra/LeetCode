class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> ans(prices.size());

        stack<int> stack;

        for (int i = 0; i < prices.size(); i++) {
            // see if the current price can be a discount for the previous items
            while (!stack.empty() && prices[i] <= prices[stack.top()]) {
                // the current item can serve as a discount for item at index stack.top()
                ans[stack.top()] = prices[stack.top()] - prices[i];
                stack.pop(); // the item has found its discount
            }

            // put the index of the item in the stack - this item will need a discount
            stack.push(i);
        }

        // check if we have prices withou discounts
        while (!stack.empty()) {
            ans[stack.top()] = prices[stack.top()];
            stack.pop();
        }

        return ans;
    }
};