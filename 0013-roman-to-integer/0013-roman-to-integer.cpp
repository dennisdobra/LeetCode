class Solution {
public:
    int romanToInt(string s) {
        vector<char> romanDigits = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        vector<int> romanValues = {1, 5, 10, 50, 100, 500, 1000};

        unordered_map<char,int> order;
        for (int i = 0; i < romanDigits.size(); i++) {
            order[romanDigits[i]] = i;
        }

        int integerValue = 0;
        for (int i = 0; i < s.size(); i++) {
            if (order[s[i]] >= order[s[i + 1]]) {
                integerValue += romanValues[order[s[i]]];
            } else if (i != s.size() - 1) {
                integerValue += (romanValues[order[s[i + 1]]] - romanValues[order[s[i]]]);
                i++; // skip the next one
            }
        }

        return integerValue;
    }
};