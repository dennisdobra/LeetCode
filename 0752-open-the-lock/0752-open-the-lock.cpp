class Solution {
public:
    vector<string> find_neighbors(string node) {
        // decrement(x) = (x - 1) % 10;
        // increment(x) = (x + 1) % 10;
        
        // vector with all possible neighbor of node
        vector<string> ans;

        // each digit of the lock
        for (int i = 0; i < 4; i++) {
            int digit = node[i] - '0'; // convert string digit to int

            // add and substract one from the digit
            for (int change : {-1, 1}) {
                // get the new digit
                // int new_digit = (digit - '0' + change + 10) % 10 + '0';
                int new_digit = (digit + change + 10) % 10;
                
                // compute the new node
                string neigh = node;
                neigh[i] = new_digit + '0';

                ans.push_back(neigh);
            }
        }

        return ans;
    }

    int openLock(vector<string>& deadends, string target) {
        // turn deadends into a set for O(1) check
        set<string> seen;
        for (string& s : deadends) {
            seen.insert(s);
        }

        // start from '0000'
        if (seen.contains("0000")) return -1;

        queue<pair<string, int>> queue;
        queue.push({"0000", 0});

        // start BFS from '0000'
        while (!queue.empty()) {
            auto [node, steps] = queue.front();
            queue.pop();

            if (node == target) return steps;

            vector<string> neighs = find_neighbors(node);

            for (string neighbor : neighs) {
                if (!seen.contains(neighbor)) {
                    seen.insert(neighbor);
                    queue.push(pair(neighbor, steps + 1));
                }
            }
        }

        return -1;
    }
};