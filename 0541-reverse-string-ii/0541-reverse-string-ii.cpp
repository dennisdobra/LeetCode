class Solution {
public:
    string reverseStr(string s, int k) {
        if (s.size() < k) {
            reverse(s, 0, s.size() - 1);
            return s;
        }

        int i = 0;
        while (i < s.size()) {
            reverse(s, i, i + k - 1);
            i = i + 2 * k;
        }

        return s;
    }

    void reverse(string &s, int start, int end) {
        while (start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};