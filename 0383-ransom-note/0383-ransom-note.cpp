class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> map;

        for (int i = 0; i < magazine.size(); i++) {
            if (map.find(magazine[i]) == map.end()) {
                map.insert({magazine[i], 1});
            } else {
                map[magazine[i]]++;
            }
        }

        for (int i = 0; i < ransomNote.size(); i++) {
            if (map.find(ransomNote[i]) == map.end() || map[ransomNote[i]] == 0) {
                return false;
            } else {
                map[ransomNote[i]]--;
            }
        }

        return true;
    }
};