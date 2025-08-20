class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> freq;

        for (int i = 0; i < arr.size(); i++) {
            freq[arr[i]]++;
        }

        int ans = -1;
        for (auto& pair : freq) {
            if (pair.first == pair.second && pair.first > ans) {
                ans = pair.first;
            }
        }

        return ans;
    }
};