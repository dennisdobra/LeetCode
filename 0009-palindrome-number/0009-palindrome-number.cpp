class Solution {
public:
    bool isPalindrome(int x) {
        /* APPROACH 1: CONVERT TO STRING */
        // string val = to_string(x);

        // int left = 0;
        // int right = val.size() - 1;

        // while (left <= right) {
        //     if (val[left] != val[right]) return false;

        //     left++;
        //     right--;
        // }

        // return true;

        /* APPROACH 2: NO CONVERSION TO STRING */
        if (x < 0) return false;

        int reverse = 0;
        int copy = x;

        while (copy != 0) {
            reverse = reverse * 10 + (copy % 10);
            copy = copy / 10;
        }

        return reverse == x;
    }
};