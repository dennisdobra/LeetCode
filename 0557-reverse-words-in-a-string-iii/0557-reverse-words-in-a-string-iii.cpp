class Solution {
public:
    string reverseWords(string s) {
        int left = 0;
        int right = s.find(' ') - 1;

        while (right < s.size()) {
            swapLetters(s, left, right);

            left = right + 2;
            right = s.find(' ', left) - 1;
        }

        // swap last word
        swapLetters(s, left, s.size() - 1);

        return s;
    }

    void swapLetters(string& s, int left, int right) {
        while (left < right) {
            swap(s[left], s[right]);

            left++;
            right--;
        }
    }
};