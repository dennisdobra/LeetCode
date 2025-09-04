class StockSpanner {
public:
    stack<pair<int,int>> stack;

    StockSpanner() {}
    
    int next(int price) {
        int ans = 1;

        while (!stack.empty() && price >= stack.top().first) {
            ans += stack.top().second;
            stack.pop();
        }

        // put the index in the stack
        stack.push({price, ans});

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */