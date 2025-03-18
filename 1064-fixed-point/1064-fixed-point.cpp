class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        int index = -1;

        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == mid) {
                index = mid;
                right = mid - 1;
            } else if (arr[mid] > mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return index;
    }
};