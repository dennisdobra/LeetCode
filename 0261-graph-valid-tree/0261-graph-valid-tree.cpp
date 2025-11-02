class UnionFind {
public:
    // constructor
    UnionFind(int sz) : root(sz), rank(sz) {
        for (int i = 0; i < sz; i++) {
            root[i] = i;
            rank[i] = 1;
        }
    }

    // find function
    int find(int x) {
        if (x == root[x]) {
            return x;
        }

        return root[x] = find(root[x]);
    }

    // union function
    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                root[rootY] = rootX;
            } else if (rank[rootX] < rank[rootY]) {
                root[rootX] = rootY;
            } else {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }

    // check connectivity function
    bool connected(int x, int y) {
        return find(x) == find(y);
    }

private:
    vector<int> root;
    vector<int> rank;
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        int numComponents = n;
        
        for (vector<int>& edge : edges) {
            int x = edge[0];
            int y = edge[1];
            
            if (uf.find(x) == uf.find(y)) return false;
            
            uf.unionSet(x, y);
            numComponents--;
        }
        
        return numComponents == 1;
    }
};