class Solution {
public:
    string reverseWords(string s) {
        // delete white spaces from the begining
        while (s[0] == ' ') {
            s.erase(0, 1);
        }

        // delete white spaces from the end
        while (s[s.size() - 1] == ' ') {
            s.erase(s.size() - 1, 1);
        }

        // delete whiet spaces from between words
        vector<string> words;
        string curr = "";
        int i = 0;
        while (i < s.size()) {
            while (s[i] == ' ') {
                i++;
            }

            curr = "";
            while (s[i] != ' ' && i < s.size()) {
                curr += s[i];
                i++;
            }

            words.push_back(curr);
        }

        // reverse the words
        for (int i = 0; i < words.size() / 2; i++) {
            swap(words[i], words[words.size() - 1 - i]);
        }

        s = "";
        for (int i = 0; i < words.size() - 1; i++) {
            s += words[i];
            s += ' ';
        }
        s += words[words.size() - 1];

        return s;
    }
};