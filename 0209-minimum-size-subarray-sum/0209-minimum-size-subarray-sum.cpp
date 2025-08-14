class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int curr = 0;
        bool found = false;
        int ans = nums.size();

        for (int right = 0; right < nums.size(); right++) {
            curr += nums[right];

            while (curr >= target) {
                if (curr >= target) {
                    ans = min(ans, right - left + 1);
                }

                found = true;
                curr -= nums[left];
                left++;
            }
        }

        if (curr >= target && found == false) {
            cout << "gev" << endl;
            return nums.size();
        }

        return !found ? 0 : ans;
    }
};