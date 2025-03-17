class Solution {
public:
    string longestNiceSubstring(string s) {
        int longest = 0;
        int start = 0;
        int end = 0;

        if (s.size() == 0 || s.size() == 1) {
            return "";
        }

        for (int i = 0; i < s.size() - 1; i++) {
            for (int j = i + 1; j < s.size(); j++) {
                if (isNice(s, i, j)) {
                    int curr_len = j - i;
                    if (curr_len > longest) {
                        longest = curr_len;
                        start = i;
                        end = j;
                    }
                }
            }
        }

        string result = "";
        if (end != 0) {
            for (int i = start; i <= end; i++) {
                result += s[i];
            }
        }

        return result;
    }

    bool isNice(string& s, int start, int end) {
        vector<int> ap(52, 0);

        for (int i = start; i <= end; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                ap[s[i] - 'a']++;
            } else if (s[i] >= 'A' && s[i] <= 'Z') {
                ap[(s[i] - 'A') + 26]++;
            }
        }

        /* print the ap vector */
        for (int i = 0; i < ap.size(); i++) {
            cout << ap[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < 26; i++) {
            if (ap[i] != 0) {
                if (ap[i + 26] == 0) {
                    return false;
                }
            }
        }

        for (int i = 26; i < 52; i++) {
            if (ap[i] != 0) {
                if (ap[i - 26] == 0) {
                    return false;
                }
            }
        }

        return true;
    }
};