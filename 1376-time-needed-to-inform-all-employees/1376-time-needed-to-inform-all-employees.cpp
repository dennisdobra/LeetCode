class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        // build the graph as a map: manager -> subordinates
        unordered_map<int, vector<int>> graph;

        for (int i = 0; i < n; i++) {
            // the head does not have a manager
            if (i == headID) continue;

            // i'th employee has manager manager[i]
            graph[manager[i]].push_back(i);
        }

        queue<pair<int, int>> queue;
        queue.push({headID, 0});

        int totalTime = -1;
        while (!queue.empty()) {
            auto [currEmp, timeSoFar] = queue.front();
            queue.pop();

            totalTime = max(totalTime, timeSoFar);

            // add subordinates of current employee in the queue
            for (int emp : graph[currEmp]) {
                queue.push({emp, timeSoFar + informTime[currEmp]});
            }
        }

        return totalTime;
    }
};