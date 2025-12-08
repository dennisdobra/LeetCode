class Solution {
public:
    string makeGood(string s) {
        string curr = "";

        for (char c : s) {
            if (curr.empty()) {
                curr.push_back(c);
                continue;
            }

            if (abs(curr.back() - c) == 32) {
                curr.pop_back();
                continue;
            }

            curr.push_back(c);
        }

        return curr;
    }
};