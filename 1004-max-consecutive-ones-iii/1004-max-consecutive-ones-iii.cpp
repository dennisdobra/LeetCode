class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int numZeroes = 0;
        int answer = 0;
        int left = 0;

        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) {
                numZeroes++;
            }

            while (numZeroes == k + 1) {
                if (nums[left] == 0) {
                    numZeroes--;
                }

                left++;
            }

            answer = max(answer, right - left + 1);
        }

        return answer;
    }
};