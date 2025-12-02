class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for (string s : strs) {
            string copy = s;
            sort(copy.begin(), copy.end());

            map[copy].push_back(s);
        }

        vector<vector<string>> ans;
        for (auto pair : map) {
            vector<string> tmp;
            for (string anagram : map[pair.first]) {
                tmp.push_back(anagram);
            }

            ans.push_back(tmp);
        }

        return ans;
    }
};