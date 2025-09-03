class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> monotonic;

        vector<int> ans(temperatures.size());

        for (int i = 0; i < temperatures.size(); i++) {
            while (!monotonic.empty() && temperatures[i] > temperatures[monotonic.top()]) {
                // found a warmer temperatures than the one at the top of the stack
                int idx = monotonic.top();
                ans[idx] = i - idx;
                monotonic.pop();
            }

            monotonic.push(i);
        }

        return ans;
    }
};