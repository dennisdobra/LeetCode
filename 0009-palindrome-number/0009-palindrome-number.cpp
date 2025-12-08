class Solution {
public:
    bool isPalindrome(int x) {
        string val = to_string(x);

        int left = 0;
        int right = val.size() - 1;

        while (left <= right) {
            if (val[left] != val[right]) return false;

            left++;
            right--;
        }

        return true;
    }
};