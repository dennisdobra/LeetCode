class Solution {
public:
    unordered_map<string, unordered_map<string, double>> graph;

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // build the graph
        for (int i = 0; i < equations.size(); i++) {
            string src = equations[i][0];
            string dst = equations[i][1];
            double cost = values[i];

            graph[src][dst] = cost;
            graph[dst][src] = 1 / cost; 
        }

        vector<double> ans(queries.size(), -1);
        for (int i = 0; i < queries.size(); i++) {
            vector<string> fraction = queries[i];
            ans[i] = fractionVal(fraction[0], fraction[1]);
        }

        return ans;
    }

    double fractionVal(string src, string dst) {
        if (!graph.count(src) || !graph.count(dst)) return -1.0;

        queue<pair<string, double>> queue;
        queue.push({src, 1.0});

        unordered_set<string> seen;
        seen.insert(src);

        while (!queue.empty()) {
            int nodesInCurrLevel = queue.size();

            for (int i = 0; i < nodesInCurrLevel; i++) {
                auto [node, cost] = queue.front();
                queue.pop();

                // check if we have reached the target
                if (node == dst) return cost;

                for (const auto& pair : graph[node]) {

                    if (!seen.contains(pair.first)) {
                        seen.insert(pair.first);
                        queue.push({pair.first, cost * pair.second});
                    }
                }
            }
        }

        return -1;
    }
};