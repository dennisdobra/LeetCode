class Solution {
public:
    int countAsterisks(string s) {
        int count = 0;

        int countBars = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '|') {
                countBars++;
            }
            if (s[i] == '*' && countBars % 2 == 0) {
                count++;
            }
        }

        return count;
    }
};