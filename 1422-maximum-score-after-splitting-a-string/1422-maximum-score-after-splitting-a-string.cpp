class Solution {
public:
    int maxScore(string s) {
        int max = 0;
        int nrOnes, nrZeros;
        int i;

        if (s.size() == 2) {
            if (s[0] == '0') {
                max++;
            }
            if (s[1] == '1') {
                max++;
            }
            return max;
        }

        for (i = 1; i < s.size() - 1; i++) {
            nrZeros = count(s, 0, i, 0);
            nrOnes = count(s, i, s.size() - 1, 1);

            if (nrZeros + nrOnes > max) {
                max = nrZeros + nrOnes;
            }
        }

        return max;
    }

private:
    int count(string s, int start, int end, int val) {
        int nr = 0;

        for (int i = start; i <= end; i++) {
            if (s[i] - '0' == val) {
                nr++;
            }
        }

        return nr;
    }
};