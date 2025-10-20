class Solution {
public:
    int n;
    unordered_map<int, vector<int>> graph;      // bombIdx - vector or neighbouring bombs

    int maximumDetonation(vector<vector<int>>& bombs) {
        n = bombs.size();

        // build the graph
        for (int i = 0; i < n; i++) {
            long long r = bombs[i][2];
            for (int j = 0; j < n; j++) {
                // check if bomb2 is in the radius of bomb1
                long long dx = bombs[i][0] - bombs[j][0];
                long long dy = bombs[i][1] - bombs[j][1];
                if (dx*dx + dy*dy <= r*r) graph[i].push_back(j);
            }
        }

        int maxDetonated = INT_MIN;

        // start a BFS from each node
        for (int i = 0; i < n; i++) {
            int detonated = bfs(i);
            if (detonated > maxDetonated) {
                maxDetonated = detonated;
            }
        }

        return maxDetonated;
    }

    // start a BFS from the current node and return the nr of visited nodes
    int bfs(int start) {
        queue<int> queue;
        queue.push(start);

        vector<bool> seen(n, false);
        seen[start] = true;

        int visitedNodes = 1;

        while (!queue.empty()) {
            int nodesInCurrLevel = queue.size();

            for (int i = 0; i < nodesInCurrLevel; i++) {
                int curr = queue.front();
                queue.pop();

                for (int neigh : graph[curr]) {
                    if (!seen[neigh]) {
                        visitedNodes++;
                        seen[neigh] = true;
                        queue.push(neigh);
                    }
                }
            }
        }

        return visitedNodes;
    }
};