class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        // find first occurence of target
        int left = 0, right = nums.size() - 1;
        int start = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                start = mid;
            }

            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // find last occurence
        left = 0, right = nums.size() - 1;
        int end = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                end = mid;
            }

            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        // check if it is a majority elem
        if ((end - start + 1) > nums.size() / 2 && start != -1 && end != -1) {
            return true;
        }

        return false;
    }
};