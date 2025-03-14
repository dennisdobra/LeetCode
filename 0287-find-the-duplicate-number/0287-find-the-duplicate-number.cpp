class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int, int> map;

        int dupElem = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (map.find(nums[i]) == map.end()) {
                map[nums[i]] += 1;
            } else {
                dupElem = nums[i];
                break;
            }
        }

        return dupElem;
    }
};