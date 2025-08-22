class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // prefix sum : number of occurences
        unordered_map<int,int> prefix_freq{};

        int ans = 0;
        int curr = 0;
        for (int i = 0; i < nums.size(); i++) {
            curr += nums[i];

            if (curr == goal) {
                // found a subarray starting from idx 0 that has a sum of goal
                ans++;
            }

            if (prefix_freq.contains(curr - goal)) {
                ans += prefix_freq[curr - goal];
            }

            prefix_freq[curr]++;
        }

        return ans;
    }
};