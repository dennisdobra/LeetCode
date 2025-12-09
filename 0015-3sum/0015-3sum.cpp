class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /* TIME LIMIT EXCEEDED */

        // sort(nums.begin(), nums.end());
        // vector<vector<int>> res;

        // vector<pair<int,int>> pairs;
        // for (int i = 0; i < nums.size() - 2 && nums[i] <= 0; i++) {
        //     for (int j = i + 1; j < nums.size() - 1; j++) {
        //         if (nums[i] + nums[j] <= 0) {
        //             pairs.push_back({i, j});
        //         }
        //     }
        // }

        // // for each valid pair of two elements find the thir one
        // for (auto pair : pairs) {
        //     for (int k = pair.second + 1; k < nums.size(); k++) {
        //         int triplet = nums[pair.first] + nums[pair.second] + nums[k];

        //         if (triplet == 0) {
        //             res.push_back({nums[pair.first], nums[pair.second], nums[k]});
        //         } else if (triplet > 0) break;
        //     }
        // }

        // // sort the vector of triplets and remove duplicates
        // sort(res.begin(), res.end());

        // // unique() moves duplicate elements to the end and returns an
        // // iterator to the beginning of the duplicates
        // // unique(res.begin(), res.end()) -> returns an iterator to the first duplicate after they are moved to the end
        // res.erase(unique(res.begin(), res.end()), res.end());

        // return res;

        /* ACCEPTED SOLUTION */
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        // iterate the array and fix every element as the first element of the triplet
        for (int i = 0; i < nums.size(); i++) {
            // since array is sorted, if nums[i] > 0 => all elements after nums[i] > 0 => no solution
            if (nums[i] > 0) break;

            // if we fix the same element twice as the first element of the triplet,
            // we will end up having duplicate triplets
            if (i == 0 || nums[i] != nums[i - 1]) {
                twoSum(nums, i, res);
            }
        }

        return res;
    }

    // starting from position i + 1, find all groups of two elements that add up to -nums[i]
    void twoSum(vector<int>& nums, int i, vector<vector<int>>& res) {
        unordered_set<int> seen;

        for (int j = i + 1; j < nums.size(); j++) {
            int complement = 0 - nums[i] - nums[j];

            // we found a valid triplet
            if (seen.contains(complement)) {
                res.push_back({nums[i], complement, nums[j]});

                // avoid fixing the second element of the triplet multiple times
                while (j + 1 < nums.size() && nums[j] == nums[j + 1]) {
                    j++;
                }
            }

            seen.insert(nums[j]);
        }
    }
};