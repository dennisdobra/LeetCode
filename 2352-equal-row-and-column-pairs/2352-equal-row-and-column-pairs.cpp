class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int> row_freq;
        unordered_map<string,int> col_freq;

        int ans = 0;

        // iterate over each row
        for (int i = 0; i < grid.size(); i++) {
            row_freq[hashFunc(grid[i])]++;
        }

        // iterate over each col
        for (int i = 0; i < grid.size(); i++) {
            vector<int> curr_col;
            for (int j = 0; j < grid.size(); j++) {
                curr_col.push_back(grid[j][i]);
            }

            col_freq[hashFunc(curr_col)]++;
        }

        // iterate over the 2 hash maps
        for (auto& pair : row_freq) {
            if (col_freq.contains(pair.first)) {
                ans += (pair.second * col_freq[pair.first]);
            }
        }

        return ans;
    }

    string hashFunc(vector<int> nums) {
        string s = "";

        for (int i = 0; i < nums.size(); i++) {
            s += to_string(nums[i]) + ',';
        }

        return s;
    }
};