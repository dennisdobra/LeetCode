class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> map;
    
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(nums[i]) != map.end()) {
                nums.erase(nums.begin() + i);
                i--;
            } else {
                map.insert(make_pair(nums[i], 1));
            }
        }

        return nums.size();
    }
};