class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;

            freq[i]--;

            int common = 0;
            bool ok = true;

            // check if after decreasing freq[i] all freqeuncies are the same
            for (int f : freq) {
                if (f == 0) continue;

                if (common == 0) {
                    common = f;
                    continue;
                }

                if (f != common) {
                    ok = false;
                    break;
                }
            }

            // all frequencies are the same after we decreased freq[i]
            if (ok == true) return true;

            // undo the deletion
            freq[i]++;
        }

        return false;
    }
};