class Solution {
public:
    int strStr(string haystack, string needle) {

        if (needle.size() > haystack.size()) {
            return -1;
        }

        if (needle.size() == haystack.size()) {
            for (int i = 0; i < needle.size(); i++) {
                if (needle[i] != haystack[i]) {
                    return -1;
                }
            }

            return 0;
        }

        int idx = -1, cnt;
        for (int i = 0; i <= haystack.size() - needle.size(); i++) {
            cnt = 0;
            for (int j = 0; j < needle.size(); j++) {
                if (haystack[i + j] == needle[j]) {
                    cnt++;
                } else {
                    break;
                }
            }

            if (cnt == needle.size()) {
                idx = i;
                break;
            }
        }

        return idx;
    }
};