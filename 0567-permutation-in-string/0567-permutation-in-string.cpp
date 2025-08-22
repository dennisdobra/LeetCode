class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        /*
        if (s2.size() < s1.size()) return false;

        sort(s1.begin(), s1.end());

        // build the initial window
        string curr = "";
        int k;
        for (k = 0; k < s1.size(); k++) {
            curr += s2[k];
        }

        string sorted = curr;
        sort(sorted.begin(), sorted.end());

        if (s1 == sorted) {
            return true;
        }

        for (int i = k; i < s2.size(); i++) {
            // slide the window
            curr.erase(0, 1);
            curr += s2[i];

            // check if the current window is a permutation of s1
            sorted = curr;
            sort(sorted.begin(), sorted.end());

            if (s1 == sorted) {
                return true;
            }
        }

        return false;
        */

        if (s2.size() < s1.size()) return false;
        unordered_map<char,int> s1map;

        for (char c : s1) {
            s1map[c]++;
        }

        string window = "";
        for (int k = 0; k < s1.size(); k++) {
            window += s2[k];
        }

        unordered_map<char,int> s2map;
        for (char c : window) {
            s2map[c]++;
        }

        if (s1map == s2map) return true;

        for (int i = s1.size(); i < s2.size(); i++) {
            // slide the window
            window += s2[i];
            window.erase(0, 1);

            s2map.clear();

            // build the map for the current window
            for (char c : window) {
                s2map[c]++;
            }

            if (s1map == s2map) return true;
        }

        return false;
    }

    bool equal(unordered_map<char,int> map1, unordered_map<char,int> map2) {
        if (map1.size() != map2.size()) return false;

        for (auto& pair : map1) {
            if (!map2.contains(pair.first) || pair.second != map2[pair.first]) {
                return false;
            }
        }

        return true;
    }
};