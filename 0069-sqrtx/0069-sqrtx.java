class Solution {
    public int mySqrt(int x) {
        // for an integer x return the square root of x rounded
        // down to the nearest integer
        if (x < 2) {
            // if x = 0 => return 0
            // if x = 1 => return 1
            // if x = 2 => sqrt(2) = 1.41 => return 1
            return x;
        }

        // binary search between 2 and x / 2
        int left = 2;
        int right = x / 2;
        int mid;

        while (left <= right) {
            mid = left + (right - left) / 2;

            long num = (long)mid * mid;

            if (num > x) {
                right = mid - 1;
            } else if (num < x) {
                left = mid + 1;
            } else {
                return mid;
            }
        }

        // here left is the smallest number whose square is greater than x,
        // and right is the largest number whose square is less than x
        return right;
    }
}