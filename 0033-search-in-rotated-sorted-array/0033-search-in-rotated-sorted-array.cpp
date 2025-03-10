class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        // find the index of the smallest elem
        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[nums.size() - 1]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        int pivot = left;

        if (target == nums[pivot]) {
            return pivot;
        }

        left = pivot;
        right = (pivot + nums.size() - 1) % nums.size();

        if (left == right) {
            if (target != nums[left]) {
                return -1;
            } else {
                return left;
            }
        }

        // binary search on the left of the pivot
        int answer = binarySearch(nums, 0, pivot - 1, target);
        if (answer != -1) {
            return answer;
        } else {
            // binary search on the right of the pivot
            return binarySearch(nums, pivot + 1, nums.size() - 1, target);
        }

        return -1;
    }

private:
    int binarySearch(vector<int>& nums, int l, int r, int target) {
        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (target < nums[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return -1;
    }
};
