class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size()) return false;

        sort(s1.begin(), s1.end());

        // initial window
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
    }
};