class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> numIdx;

        for (int i = 0; i < nums.size(); i++) {
            numIdx.push_back(make_pair(nums[i], i));
        }

        sort(numIdx.begin(), numIdx.end());

        int left = 0, right = nums.size() - 1;
        while (left < right) {
            if (numIdx[left].first + numIdx[right].first == target) {
                return {numIdx[left].second, numIdx[right].second};
            }

            if (numIdx[left].first + numIdx[right].first > target) {
                right--;
            } else {
                left++;
            }
        }

        return {-1, -1};
    }
};