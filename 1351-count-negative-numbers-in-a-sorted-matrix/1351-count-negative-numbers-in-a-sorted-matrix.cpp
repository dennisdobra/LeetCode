class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;

        for (int i = 0; i < grid.size(); i++) {
            count += FirstNegative(grid[i]);
        }

        return count;
    }

    int FirstNegative(vector<int> row) {
        int index = row.size();
        int left = 0, right = row.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (row[mid] < 0) {
                index = mid;
            }

            if (row[mid] >= 0) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return row.size() - index;
    }
};