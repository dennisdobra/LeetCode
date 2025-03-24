class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        int reds = 0, whites = 0;
        while (left < right) {
            if (nums[left] == 0) {
                reds++;
            } else if (nums[left] == 1) {
                whites++;
            }

            if (nums[right] == 0) {
                reds++;
            } else if (nums[right] == 1) {
                whites++;
            }

            left++;
            right--;
        }

        if (nums.size() % 2 != 0) {
            if (nums[left] == 0) {
                reds++;
            } else if (nums[left] == 1) {
                whites++;
            }
        }
        
        for (int i = 0; i < reds; i++) {
            nums[i] = 0;
        }

        for (int i = reds; i < whites + reds; i++) {
            nums[i] = 1;
        }

        for (int i = reds + whites; i < nums.size(); i++) {
            nums[i] = 2;
        }
    }
};