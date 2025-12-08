class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> monotonic;
        vector<int> ans(temperatures.size());

        for (int i = 0; i < temperatures.size(); i++) {
            while (!monotonic.empty() && temperatures[i] > temperatures[monotonic.top()]) {
                // we found a warmer day
                ans[monotonic.top()] = i - monotonic.top();
                monotonic.pop();
            }

            monotonic.push(i);
        }

        return ans;
    }
};