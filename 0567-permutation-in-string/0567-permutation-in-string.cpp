class Solution {
public:
    /* APPROACH 1 : SORTING */
    bool checkInclusion_(string s1, string s2) {
        // we want to find if any of s1's permutations is a substring of s2
        // to see this we can sort s1 and then iterate s2 in windows of
        // size s1.size(), starting from index 0, also sort the window and
        // check if they are equal

        if (s2.size() < s1.size()) return false;

        sort(s1.begin(), s1.end());

        for (int i = 0; i <= s2.size() - s1.size(); i++) {
            // get the current window
            string window = s2.substr(i, s1.size());
            
            // sort the window
            sort(window.begin(), window.end());

            if (s1 == window) return true;
        }

        return false;
    }

    /* APPROACH 2 : HASH MAPS */
    bool checkInclusion__(string s1, string s2) {
        if (s2.size() < s1.size()) return false;

        // map to track the frequency of characters in s1
        unordered_map<char,int> s1map;
        for (char c : s1) {
            s1map[c]++;
        }

        // we now consider every possible substring from s2
        // of size s1.size(), create its hashmap and then
        // compare it to s1map. If they are equal it means
        // tehere is a permutation of s1 as a substring in s2

        int left = 0;
        unordered_map<char,int> s2map;
        for (int right = 0; right < s2.size(); right++) {
            s2map[s2[right]]++;

            if (right - left + 1 > s1.size()) {
                s2map[s2[left]]--;

                if (s2map[s2[left]] == 0) {
                    s2map.erase(s2[left]);
                }

                left++;
            }

            if (right - left + 1 == s1.size()) {
                // compare hash maps
                if (equal(s1map, s2map) == true) {
                    return true;
                }
            }
        }

        return false;
    }

    bool equal(unordered_map<char,int>& map1, unordered_map<char,int>& map2) {
        for (auto pair : map1) {
            if (!map2.contains(pair.first)) return false;

            if (pair.second != map2[pair.first]) return false;
        }

        return true;
    }

    /* APPROACH 3 : HASH MAPS */
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        unordered_set<char> set(s1.begin(), s1.end());

        unordered_map<char, int> map;
        for (char c : s1) {
            map[c]++;
        }

        for (int i = 0; i < s2.size(); i++) {
            // add the character to the right
            if (set.contains(s2[i])) {
                map[s2[i]]--;
                if (map[s2[i]] == 0) {
                    map.erase(s2[i]);
                }
            }

            if (i >= s1.size()) {
                // remove from left
                if (set.contains(s2[i - s1.size()])) {
                    map[s2[i - s1.size()]]++;
                    if (map[s2[i - s1.size()]] == 0) {
                        map.erase(s2[i - s1.size()]);
                    }
                }
            }

            if (map.size() == 0) return true;
        }

        return false;
    }

    
};