class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> count_odd{{0, 1}};
        // map: number of odd elements -> number of subbarays

        int curr = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 != 0) {
                curr++;
            }
            
            ans += count_odd[curr - k];

            count_odd[curr]++;
        }

        return ans;
    }
};