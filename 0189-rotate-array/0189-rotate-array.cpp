class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() == 1) {
            return;
        }

        k %= nums.size();

        // complexitate temporala: O(n * k)
        // int last, i, j;
        // for (i = 0; i < k; i++) {
        //     last = nums[nums.size() - 1];
        //     for (j = nums.size() - 1; j > 0; j--) {
        //         nums[j] = nums[j - 1];
        //     }
        //     nums[0] = last;
        // }

        // complexitate temporala: O(n)
        vector<int> result(nums.size());

        for (int i = 0; i < nums.size(); i++) {
            int idx = (i + k) % nums.size();
            result[idx] = nums[i];
        }

        for (int i = 0; i < nums.size(); i++) {
            nums[i] = result[i];
        }
    }
};