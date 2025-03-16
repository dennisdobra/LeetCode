class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            int max_idx = std::min<int>(i + k, static_cast<int>(nums.size() - 1));
            for (int j = i + 1; j <= max_idx; j++) {
                if (nums[i] == nums[j]) {
                    return true;
                }
            }
        }
        return false;
    }
};