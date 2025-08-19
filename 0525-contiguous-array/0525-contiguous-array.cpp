class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0;

        unordered_map<int,int> map;

        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            nums[i] > 0 ? count++ : count--;

            if (count == 0) {
                ans = i + 1;
            }

            if (map.find(count) != map.end()) {
                ans = max(ans, i - map[count]);
            }

            if (map.find(count) == map.end()) {
                map[count] = i;
            }
        }

        return ans;
    }
};