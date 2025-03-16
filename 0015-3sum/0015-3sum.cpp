class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort(nums.begin(), nums.end());

        // vector<pair<int, int>> pairs;
        // for (int i = 0; i < nums.size() - 2 && nums[i] <= 0; i++) {
        //     for (int j = i + 1; j < nums.size() - 1 && nums[j] <= 0; j++) {
        //         if (nums[i] + nums[j] <= 0) {
        //             pairs.push_back({i, j});
        //         }
        //     }
        // }

        // vector<vector<int>> result;
        // for (int i = 0; i < pairs.size(); i++) {
        //     for (int k = pairs[i].second + 1; k < nums.size(); k++) {
        //         if (nums[pairs[i].first] + nums[pairs[i].second] + nums[k] == 0) {
        //             result.push_back({nums[pairs[i].first], nums[pairs[i].second], nums[k]});
        //         } else if (nums[pairs[i].first] + nums[pairs[i].second] + nums[k] > 0) {
        //             break;
        //         }
        //     }
        // }

        // sort(result.begin(), result.end());
        // result.erase(unique(result.begin(), result.end()), result.end());
        // return result;


        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        for (int i = 0; i < nums.size() && nums[i] <= 0; i++) {
            if (i == 0 || nums[i - 1] != nums[i]) {
                twoSum(nums, i, result);
            }
        }

        return result;
    }

    void twoSum(vector<int>& nums, int i, vector<vector<int>>& res) {
        int low = i + 1;
        int high = nums.size() - 1;

        while (low < high) {
            int sum = nums[i] + nums[low] + nums[high];

            if (sum < 0) {
                low++;
            } else if (sum > 0) {
                high--;
            } else {
                // found a triplet
                res.push_back({nums[i], nums[low], nums[high]});
                low++;
                high--;

                // avoid duplicate triplets by skipping consec duplicate values
                while (low < high && nums[low] == nums[low - 1]) low++;
            }
        }
    }
};