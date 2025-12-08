class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }

        // try removing one occurence of each letter and check
        // if the condition is met
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;

            freq[i]--;

            bool ok = true;
            int common = 0;

            // now check if all frequencies are the same
            for (int f : freq) {
                if (f == 0) continue;

                if (common == 0) common = f;    // first non-zero freq becomes baseline
                else if (f != common) {
                    // found a mismatch => not valid
                    ok = false;
                    break;
                } 
            }

            if (ok == true) return true;

            // undo the deletion
            freq[i]++;
        }

        return false;
    }
};