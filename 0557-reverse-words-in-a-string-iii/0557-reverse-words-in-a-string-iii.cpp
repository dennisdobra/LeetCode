class Solution {
public:
    string reverseWords(string s) {
        int i = 0;  // start for each word
        int j = 0;  // end for end word

        while (j < s.size()) {
            while (s[j] != ' ' && j < s.size()) {
                j++;
            }

            // j is at ' ' now => move one more
            int next_pos = j + 1;

            j--;

            // reverse each word
            while (i < j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }

            // set indices for next word
            i = j = next_pos;
        }

        return s;
    }
};