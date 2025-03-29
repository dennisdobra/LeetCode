class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int left = 0;
        int answer = 0;
        int numZeroes = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) {
                numZeroes++;
            }

            while (numZeroes == 2) {
                if (nums[left] == 0) {
                    numZeroes--;
                }
                left++;
            }

            answer = max(answer, right - left + 1);
        }

        return answer;
    }

    int countZeros(vector<int>& nums, int left, int right) {
        int count = 0;

        for (int i = left; i <= right; i++) {
            if (nums[i] == 0) {
                count++;
            }
        }

        return count;
    }
};