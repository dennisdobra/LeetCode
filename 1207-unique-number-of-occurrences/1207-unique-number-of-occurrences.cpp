class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> occ;

        for (int num : arr) {
            occ[num]++;
        }

        unordered_set<int> unique;

        for (auto& pair : occ) {
            if (unique.contains(pair.second)) {
                return false;
            }

            unique.insert(pair.second);
        }

        return true;
    }
};