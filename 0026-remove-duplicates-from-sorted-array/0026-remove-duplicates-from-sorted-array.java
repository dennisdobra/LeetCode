class Solution {
    public int removeDuplicates(int[] nums) {
        // the first position where it is possible to override
        // is 1 because nums[0] is always unique
        int k = 1;

        for (int i = 1; i < nums.length; i++) {
            // if the current element is different from the previous one
            if (nums[i] != nums[i - 1]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
}