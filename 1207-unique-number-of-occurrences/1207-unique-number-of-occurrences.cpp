class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> map;
        unordered_set<int> set;

        for (int num : arr) {
            map[num]++;
        }

        for (auto pair : map) {
            if (set.contains(pair.second)) {
                return false;
            }

            set.insert(pair.second);
        }

        return true;
    }
};