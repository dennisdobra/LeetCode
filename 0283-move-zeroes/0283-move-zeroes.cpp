class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;  // will iterate over the zeros in the vector
        int j = 0;  // will iterate over the non-zero elements in the vector

        bool found_zero = false;
        bool found_non_zero = false;

        while (i < nums.size() && j < nums.size()) {
            // set i at the first zero
            while (i < nums.size() && nums[i] != 0) {
                i++;
            }

            if (i < nums.size()) {
                found_zero = true;
            }

            // set j at the first non zero elem after the current element => don't bring the zeros in the front
            j = i;
            while (j < nums.size() && nums[j] == 0) {
                j++;
            }

            if (j < nums.size()) {
                found_non_zero = true;
            }

            if (found_zero && found_non_zero && i < j) {
                swap(nums[i], nums[j]);
                found_zero = false;
                found_non_zero = false;
            }

            if (found_zero == true && found_non_zero == true) {
                break;
            }
        }
    }
};