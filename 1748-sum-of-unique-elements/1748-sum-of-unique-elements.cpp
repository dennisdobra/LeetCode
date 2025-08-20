class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> freq;

        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]]++;
        }

        int sum = 0;
        for (auto& pair : freq) {
            if (pair.second == 1) {
                sum += pair.first;
            }
        }

        return sum;
    }
};