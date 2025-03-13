class Solution {
public:
    bool checkIfExist(vector<int>& arr) {

        /* Brute Force */
        // sort(arr.begin(), arr.end(), greater<int>());

        // int i, j;
        // for (i = 0; i < arr.size(); i++) {
        //     for (j = 0; j < arr.size(); j++) {
        //         if (arr[i] == 2 * arr[j] && i != j) {
        //             return true;
        //         }
        //     }
        // }

        /* Binary Search */
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size(); i++) {
            if (binarySearch(arr, 2 * arr[i]) != -1 && binarySearch(arr, 2 * arr[i]) != i) {
                return true;
            }
        }
        return false;
    }

private:
    int binarySearch(vector<int>& arr, int target) {
        int l = 0;
        int r = arr.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (arr[mid] == target) {
                return mid;
            } else if (target < arr[mid]) {
                r = mid - 1;
            } else if (target > arr[mid]) {
                l = mid + 1;
            }
        }

        cout << "jf" << endl;

        return -1;
    }
};