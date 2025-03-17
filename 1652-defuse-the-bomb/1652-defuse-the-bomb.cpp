class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> copy = code;

        if (k == 0) {
            for (int i = 0; i < code.size(); i++) {
                code[i] = 0;
            }
        } else if (k > 0) {
            for (int i = 0; i < code.size(); i++) {
                code[i] = sumOfNextK(copy, i, k);
            }
        } else if (k < 0) {
            for (int i = 0; i < code.size(); i++) {
                code[i] = sumOfPrevK(copy, i, k);
            }
        }

        return code;
    }

    int sumOfNextK(vector<int>& code, int idx, int k) {
        int sum = 0;
        int n = code.size();

        while (k > 0) {
            idx = (idx + 1) % n;
            sum += code[idx];
            k--;
        }

        return sum;
    }

    int sumOfPrevK(vector<int>& code, int idx, int k) {
        int sum = 0;
        int n = code.size();

        while (k < 0) {
            idx = (idx - 1 + n) % n;
            sum += code[idx];
            k++;
        }

        return sum;
    }
};