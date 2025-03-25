class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> duplicates;

        unordered_map<int, int> hashTable;

        for (int i = 0; i < nums.size(); i++) {
            if (hashTable.find(nums[i]) == hashTable.end()) {
                hashTable[nums[i]] = 1;
            } else {
                hashTable[nums[i]]++;
            }
        }

        for (const auto& pair : hashTable) {
            if (pair.second == 2) {
                duplicates.push_back(pair.first);
            }
        }

        return duplicates;
    }
};