class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> answer;

        // for each node i, find all the nodes that can reach it

        // build the graph
        unordered_map<int, vector<int>> graph;
        for (vector<int> edge : edges) {
            int src = edge[0], dst = edge[1];
            graph[dst].push_back(src);
        }

        for (int i = 0; i < n; i++) {
            vector<bool> seen(n, false);
            queue<int> queue;

            queue.push(i);
            seen[i] = true;

            vector<int> ancestors;
            while (!queue.empty()) {
                int curr = queue.front();
                queue.pop();

                for (int neigh : graph[curr]) {
                    if (seen[neigh] == false) {
                        queue.push(neigh);
                        seen[neigh] = true;
                        ancestors.push_back(neigh);
                    }
                }
            }

            sort(ancestors.begin(), ancestors.end());
            answer.push_back(ancestors);
        }

        return answer;
    }
};