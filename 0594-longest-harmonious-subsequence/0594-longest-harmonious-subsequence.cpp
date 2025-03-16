class Solution {
public:
    int findLHS(vector<int>& nums) {
        int max_len = 0;

        for (int i = 0; i < nums.size(); i++) {
            int min = nums[i];
            int max = INT_MAX;
            int curr_len = 1;

            for (int j = 0; j < nums.size(); j++) {
                if (max != INT_MAX) {
                    if (nums[j] != min && nums[j] != max) {
                        continue;
                    }
                }

                if (nums[j] == min && i != j) {
                    curr_len++;
                } else if (nums[j] == nums[i] + 1) {
                    max = nums[j];
                    curr_len++;
                }
            }

            if (curr_len > max_len && max != INT_MAX) {
                max_len = curr_len;
            }
        }

        return max_len;
    }
};