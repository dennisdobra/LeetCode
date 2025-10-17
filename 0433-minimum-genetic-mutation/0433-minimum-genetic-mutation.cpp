class Solution {
public:
    vector<char> letters = {'A', 'C', 'G', 'T'};

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string, int>> queue;  // node, steps
        queue.push({startGene, 0});

        unordered_set<string> seen;
        seen.insert(startGene);

        // convert bank into a set
        unordered_set<string> validGenes;
        for (string& gene : bank) {
            validGenes.insert(gene);
        }

        while (!queue.empty()) {
            auto [node, steps] = queue.front();
            queue.pop();

            // check if we have reached the target
            if (node == endGene) return steps;

            vector<string> neighs = findNeighbors(node);
            for (string& neigh : neighs) {
                // check bank to see if it is a valid muattaion
                if (validGenes.contains(neigh)) {
                    // check if we have not visited this state
                    if (!seen.contains(neigh)) {
                        seen.insert(neigh);
                        queue.push({neigh, steps + 1});
                    }
                }
            }
        }

        return -1;
    }

    vector<string> findNeighbors(string node) {
        vector<string> ans;

        // iterate through each letter of the gene
        for (int i = 0; i < 8; i++) {
            char currLetter = node[i];

            // change each letter of the gene with all possibilities
            for (int j = 0; j < letters.size(); j++) {
                string neighbor = node;

                // make sure we don't mark the current state as a neighbor of itself
                if (currLetter != letters[j]) {
                    neighbor[i] = letters[j];
                    ans.push_back(neighbor);
                }
            }
        }

        return ans;
    }
};