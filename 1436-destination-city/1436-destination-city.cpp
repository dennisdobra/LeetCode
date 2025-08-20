class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> transit_cities;

        for (auto& arr : paths) {
            transit_cities.insert(arr[0]);
        }

        for (auto& arr : paths) {
            if (!transit_cities.contains(arr[1])) {
                return arr[1];
            }
        }

        return "";
    }
};