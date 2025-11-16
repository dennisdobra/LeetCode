class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> numbers;

        for (int num : nums) {
            numbers.insert(num);
        }

        int n = nums.size();
        for (int i = 0; i <= n; i++) {
            if (!numbers.contains(i)) {
                return i;
            }
        }

        return -1;
    }
};