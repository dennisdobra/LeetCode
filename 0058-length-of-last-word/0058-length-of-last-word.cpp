class Solution {
public:
    int lengthOfLastWord(string s) {
        int idx = s.size() - 1;

        while (s[idx] == ' ') {
            idx--;
            if (idx == 0 && s[0] == ' ') {
                return 0;
            }
        }

        cout << s << endl;
        cout << "idx = " << idx << endl;

        int cnt = 0;
        while (s[idx] != ' ') {
            cnt++;
            idx--;
            if (idx < 0) {
                break;
            }
        }

        return cnt;
    }
};