class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int> rowsFreq;
        for (int i = 0; i < grid.size(); i++) {
            string row = "";
            for (int j = 0; j < grid[0].size(); j++) {
                row += to_string(grid[i][j]);
                row += ',';
            }
            row.pop_back();

            rowsFreq[row]++;
        }

        int ans = 0;
        for (int j = 0; j < grid[0].size(); j++) {
            string col = "";
            for (int i = 0; i < grid.size(); i++) {
                col += to_string(grid[i][j]);
                col += ',';
            }
            col.pop_back();

            if (rowsFreq.contains(col)) {
                ans += rowsFreq[col];
            }
        }

        return ans;
    }
};