class Solution {
public:
    vector<int> parent;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // path compression
        return parent[x];
    }

    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);
        if (pa != pb)
            parent[pa] = pb;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        // Step 1: Not enough cables
        if (connections.size() < n - 1)
            return -1;

        // Step 2: Initialize DSU
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;

        // Step 3: Union all connections
        for (auto &c : connections)
            unite(c[0], c[1]);

        // Step 4: Count components
        int components = 0;
        for (int i = 0; i < n; i++) {
            if (find(i) == i)
                components++;
        }

        // Step 5: operations needed
        return components - 1;
    }
};