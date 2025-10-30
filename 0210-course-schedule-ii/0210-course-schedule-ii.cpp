class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<int> state;
    vector<int> courseOrder;

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        for (vector<int>& edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]);
        }

        state = vector<int>(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (state[i] == 0 && dfs(i) == true) {
                return {};
            }
        }

        reverse(courseOrder.begin(), courseOrder.end());
        return courseOrder;
    }

    bool dfs(int node) {
        // mark the current node as visiting
        state[node] = 1;

        for (int& neigh : graph[node]) {
            if (state[neigh] == 0) {
                // check if there is a cycle deeper
                if (dfs(neigh) == true) {
                    return true;
                }
            } else if (state[neigh] == 1) {
                return true;
            }
        }

        // no cycle found starting DFS from this node
        state[node] = 2;
        courseOrder.push_back(node);
        return false;
    }
};