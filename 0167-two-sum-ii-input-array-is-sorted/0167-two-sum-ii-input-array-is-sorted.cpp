class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> solution(2);

        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            if (numbers[left] + numbers[right] == target) {
                solution[0] = left + 1;
                solution[1] = right + 1;
                break;
            }

            if (numbers[left] + numbers[right] < target) {
                left++;                
            } else if (numbers[left] + numbers[right] > target) {
                right--;
            }
        }

        return solution;
    }
};