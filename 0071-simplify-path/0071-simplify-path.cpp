class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;

        stringstream ss(path);
        string curr;

        // split by "/"
        while (getline(ss, curr, '/')) {
            if (curr == "..") {
                if (!stack.empty()) {
                    stack.pop_back();
                }
            } else if (curr == "." || curr.empty()) {
                continue;
            } else {
                stack.push_back(curr);
            }
        }

        string res = "";

        // build the simplified path
        for (string str : stack) {
            res += "/" + str;
        }

        return res.empty() ? "/" : res;
    }
};