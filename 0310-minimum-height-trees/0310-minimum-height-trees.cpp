class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        /* Brute Force: Start a BFS from every node and track the height */
        // unordered_map<int, vector<int>> graph;
        // unordered_map<int, int> heights;
        // int minHeight = INT_MAX;

        // // build the graph
        // for (vector<int>& edge : edges) {
        //     int x = edge[0];
        //     int y = edge[1];

        //     // the graph is undirected
        //     graph[x].push_back(y);
        //     graph[y].push_back(x);
        // }

        // // start a BFS from every node
        // for (int i = 0; i < n; i++) {
        //     queue<int> queue;
        //     queue.push(i);

        //     int levels = 0;
        //     while (!queue.empty()) {
        //         int nodesInCurrLevel = queue.size();

        //         for (int i = 0; i < nodesInCurrLevel; i++) {
        //             int currNode = queue.front();
        //             queue.pop();

        //             for (int neigh : graph[currNode]) {
        //                 queue.push(neigh);
        //             }
        //         }

        //         levels++;
        //     }

        //     // done with the BFS for node i
        //     heights[i] = levels;

        //     if (levels < minHeight) {
        //         minHeight = levels;
        //     }
        // }

        // vector<int> answer;
        // for (int i = 0; i < n; i++) {
        //     if (heights[i] == minHeight) {
        //         answer.push_back(i);
        //     }
        // }

        // return answer;


        /* TOPOLOGICAL SORT */

        // edge case
        if (n < 2) {
            vector<int> centroids;
            for (int i = 0; i < n; i++) {
                centroids.push_back(i);
            }
            return centroids;
        }

        // create the graph as an adjacency list
        unordered_map<int, unordered_set<int>> graph;
        for (vector<int>& edge : edges) {
            int src = edge[0];
            int dst = edge[1];

            graph[src].insert(dst);
            graph[dst].insert(src);
        }

        // create a queue that initially stores all leaf nodes
        vector<int> leaves;
        for (int i = 0; i < n; i++) {
            if (graph[i].size() == 1) {
                leaves.push_back(i);
            }
        }

        // remove the leaves until we only have 2 nodes left
        int remainingNodes = n;
        while (remainingNodes > 2) {
            remainingNodes -= leaves.size();

            vector<int> newLeaves;

            // remove the current leaves along with the edges
            for (int leaf : leaves) {
                // each leaf has only one neighbor (parent)
                // => we want to find that neighbor (parent)
                int neighbor = *graph[leaf].begin();

                // remove the edge between th eneighbor and the leaf
                graph[neighbor].erase(leaf);

                // check if the neighbor has become a leaf after trimming
                if (graph[neighbor].size() == 1) {
                    newLeaves.push_back(neighbor);
                }
            }

            leaves = newLeaves;
        }

        return leaves;
    }
};