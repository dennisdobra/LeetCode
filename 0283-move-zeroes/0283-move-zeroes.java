class Solution {
    public void moveZeroes(int[] nums) {
        int firstZero = -1;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 0) {
                firstZero = i;
                break;
            }
        }

        if (firstZero == -1) return;

        for (int i = firstZero; i < nums.length; i++) {
            if (nums[i] != 0) {
                // swap nums[i] with the zero at index 'firstZero'
                nums[firstZero] = nums[i];
                nums[i] = 0;

                // search the next firstZero starting from index firstZero
                for (int j = firstZero; j < nums.length; j++) {
                    if (nums[j] == 0) {
                        firstZero = j;
                        break;
                    }
                }
            }
        }

        return;
    }
}