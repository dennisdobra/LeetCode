class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int numRows = matrix.size();
        int numCols = matrix[0].size();

        if (numRows == 1 && numCols == 1 && matrix[0][0] != target) {
            return false;
        }

        int left = 0, right = numRows - 1;
        int row = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (target >= matrix[mid][0] && target <= matrix[mid][numCols - 1]) {
                row = mid;
                break;
            } else if (target < matrix[mid][0]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (row == -1) {
            return false;
        }

        left = 0;
        right = matrix[row].size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (matrix[row][mid] == target) {
                return true;
            } else if (target < matrix[row][mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return false;
    }
};