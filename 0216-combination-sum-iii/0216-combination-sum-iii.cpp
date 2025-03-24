class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> comb;

        backtrack(n, k, comb, 0, result);

        return result;
    }

    void backtrack(int remain, int k, vector<int>& comb, int next_start, vector<vector<int>>& result) {
        if (remain == 0 && comb.size() == k) {
            result.push_back(comb); // found a solution
            return;
        } else if (remain < 0 || comb.size() == k) {
            return;
        }

        // iterate through the reduced list of candidates
        for (int i = next_start; i < 9; i++) {
            comb.push_back(i + 1);

            backtrack(remain - i - 1, k, comb, i + 1, result);
            comb.pop_back();
        }
    }
};