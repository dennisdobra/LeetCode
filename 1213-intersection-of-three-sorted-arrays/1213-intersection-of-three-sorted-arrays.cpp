class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        vector<int> result;

        for (int i = 0; i < arr1.size(); i++) {
            if (BinarySearch(arr2, arr1[i]) && BinarySearch(arr3, arr1[i])) {
                result.push_back(arr1[i]);
            }
        }

        return result;
    }

    bool BinarySearch(vector<int> arr, int target) {
        int left = 0;
        int right = arr.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                return true;
            }

            if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};