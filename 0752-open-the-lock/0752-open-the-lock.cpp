class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        // create a set with deadends for O(1) search
        unordered_set<string> seen;
        for (string& s : deadends) {
            seen.insert(s);
        }

        // check if start is in deadends
        if (seen.contains("0000")) return -1;

        queue<pair<string,int>> queue;     // {node, steps}
        queue.push({"0000", 0});

        while (!queue.empty()) {
            auto [node, steps] = queue.front();
            queue.pop();

            // check if we have reached the target
            if (node == target) return steps;

            // get all possible neighbor of the current node
            vector<string> neighs = findNeighbors(node);
            for (string& neigh : neighs) {
                if (!seen.contains(neigh)) {
                    seen.insert(neigh);
                    queue.push({neigh, steps + 1});
                }
            }
        }

        return -1;
    }

    vector<string> findNeighbors(string node) {
        vector<string> ans;

        for (int i = 0; i < 4; i++) {
            int curDigit = node[i] - '0';

            for (int change : {-1, 1}) {
                int newDigit = (curDigit + change + 10) % 10;

                string neighbor = node;
                neighbor[i] = newDigit + '0';

                ans.push_back(neighbor);
            }
        }

        return ans;
    }
};