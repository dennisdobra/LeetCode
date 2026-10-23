class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> map;

        for (char c : s) {
            map[c]++;
        }

        vector<pair<char, int>> vec(map.begin(), map.end());

        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            if (a.second != b.second) return a.second > b.second;
            return a.first < b.first;
        });

        // sort(vec.begin(), vec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
        //     if (a.second != b.second) return a.second > b.second;
        //     return a.first < b.first;
        // });

        string sorted = "";
        for (auto& pair : vec) {
            sorted.append(pair.second, pair.first);
        }

        return sorted;
    }
};