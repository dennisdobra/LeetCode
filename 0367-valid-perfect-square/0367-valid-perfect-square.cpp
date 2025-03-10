class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num < 2) {
            return true;
        }

        int left = 2;
        int right = num / 2;

        while (left <= right) {
            double mid = left + (right - left) / 2;

            double var = mid * mid;
            if (var < INT_MAX && (int)var == num) {
                return true;
            } else if (mid * mid > num) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return false;
    }
};