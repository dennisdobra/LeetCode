class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "";

        int nr = 1;
        for (int i = 0; i < chars.size() - 1; i++) {
            if (chars[i] == chars[i + 1]) {
                nr++;
            } else {
                s += chars[i];

                if (nr > 1) {
                    s += to_string(nr);
                    nr = 1;
                }
            }
        }

        s += chars[chars.size() - 1];
        if (nr > 1) {
            s += to_string(nr);
        }

        for (int i = 0; i < s.size(); i++) {
            chars[i] = s[i];
        }

        return s.size();
    }
};