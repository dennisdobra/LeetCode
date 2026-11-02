class Solution {
    List<List<Integer>> triplets = new ArrayList<>();

    // Time Complexity: O(nlog) from sort + O(n^2) bc of the nested for loops
    // Space Complexity: O(n)
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);

        // fix the first element of the triplet
        for (int i = 0; i < nums.length; i++) {
            // since the array is sorted, if the first element is > 0
            // => the next two elements of the triplet will be > 0
            if (nums[i] > 0) break;

            // avoid fixing the same first element multiple times
            // because we do not want duplicate triplets
            if (i == 0 || nums[i] != nums[i - 1]) {
                twoSum(nums, i);
            }
        }

        return triplets;
    }

    public void twoSum(int[] nums, int i) {
        Set<Integer> seen = new HashSet<>();

        // iterate from i + 1 to the end and try to fix the second elements of the triplet
        // and then check if we've previously seen the complement, which actually makes
        // nums[j] the third element in the triplet
        for (int j = i + 1; j < nums.length; j++) {
            // now which is the third element
            int complement = 0 - nums[j] - nums[i];

            // if we've seen the complement element in the past => now that
            // we have seen all three elements we can form a triplet
            if (seen.contains(complement)) {
                triplets.add(List.of(nums[i], complement, nums[j]));

                // we must avoid fixing the same element nums[j] multiple times
                // becuase if the array has duplicates we will also have duplicate triplets
                while (j + 1 < nums.length && nums[j] == nums[j + 1]) {
                    j++;
                }
            }

            // mark the current element as seen
            seen.add(nums[j]);
        }
    }
}