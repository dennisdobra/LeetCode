class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        if (nums.size() == 1) {
            return;
        }

        sort(nums.begin(), nums.end());

        if (nums.size() == 2) {
            return;
        }

        vector<int> copy = nums;

        int index = 0;
        for (int i = 0; i < nums.size(); i = i + 2) {
            nums[i] = copy[index];
            index++;
        }

        for (int i = nums.size() - 1 - (nums.size() % 2); i >= 1; i = i - 2) {
            nums[i] = copy[index];
            index++;
        }
    }
};
