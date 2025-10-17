class Solution {
public:
    // create a set for wordList for O(1) search
    unordered_set<string> wordListSet;

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // set for wordList
        for (string& s : wordList) {
            wordListSet.insert(s);
        }

        // check if endWord is in the set. If not return 0;
        if (!wordListSet.contains(endWord)) return 0;

        // start a BFS from node beginWord and steps = 0;
        queue<pair<string, int>> queue;
        queue.push({beginWord, 1});

        // set to track already visited words
        unordered_set<string> seen;
        seen.insert(beginWord);

        while (!queue.empty()) {
            auto [node, steps] = queue.front();
            queue.pop();

            // check if we have reached the target
            if (node == endWord) return steps;

            // get all valid neighbors from wordList for current node
            vector<string> neighs = getNeighbors(node);
            for (string& neigh : neighs) {
                if (!seen.contains(neigh)) {
                    seen.insert(neigh);
                    queue.push({neigh, steps + 1});
                }
            }
        }

        return 0;
    }

    vector<string> getNeighbors(string node) {
        vector<string> ans;

        for (const string& neigh : wordListSet) {
            // check if it is a valid neighbor
            if (countDifferences(node, neigh) == 1) {
                ans.push_back(neigh);
            }
        }

        return ans;
    }

    int countDifferences(string s1, string s2) {
        int cnt = 0;

        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) cnt++;
        }

        return cnt;
    }
};