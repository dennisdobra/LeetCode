class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        vector<int> solution;

        if (nums1.size() < nums2.size()) {
            for (int i = 0; i < nums1.size(); i++) {
                if (binarySearch(nums2, nums1[i]) != -1) {
                    solution.push_back(nums1[i]);
                }
            }
        } else {
            for (int i = 0; i < nums2.size(); i++) {
                if (binarySearch(nums1, nums2[i]) != -1) {
                    solution.push_back(nums2[i]);
                }
            }
        }

        return solution;
    }

private:
    int binarySearch(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                nums[mid] = INT_MIN;
                sort(nums.begin(), nums.end());
                return mid;
            } else if (target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return -1;
    }
};