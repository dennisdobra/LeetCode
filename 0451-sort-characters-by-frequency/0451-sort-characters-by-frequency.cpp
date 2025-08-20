class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;

        for (char c : s) {
            freq[c]++;
        }

        vector<pair<char,int>> sorted(freq.begin(), freq.end());

        sort(sorted.begin(), sorted.end(),
            [](const auto &a, const auto &b) {
                return a.second > b.second; // sort by value
            });

        string result = "";

        for (auto & pair : sorted) {
            while (pair.second != 0) {
                result += pair.first;
                pair.second--;
            }
        }

        return result;
    }
};