class Solution {
    // Find function with path compression for DSU
    int find(int x, vector<int>& parent) {
        if (x == parent[x])
            return x;
        return parent[x] = find(parent[x], parent);
    }

    // Union by rank for DSU
    void Union(int x, int y, vector<int>& parent, vector<int>& rank) {
        int x_parent = find(x, parent);
        int y_parent = find(y, parent);

        if (x_parent == y_parent) return;

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        } else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        } else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    }

    // Kruskal's algorithm with variations:
    // operation = -1 → Standard
    // operation = 1  → Exclude `incl`
    // operation = 2  → Force-include `incl`
    int Kruskal(vector<vector<int>>& vec, vector<int>& incl, int n, int operation) {
        int sum = 0;
        vector<int> parent(n), rank(n, 0);

        for (int i = 0; i < n; i++) parent[i] = i;

        if (operation == 2) {
            int u = incl[0], v = incl[1];
            Union(u, v, parent, rank);
            sum += incl[2];
        }

        for (auto& edge : vec) {
            int u = edge[0], v = edge[1], wt = edge[2];

            if (operation == 1 &&
                edge[0] == incl[0] &&
                edge[1] == incl[1] &&
                edge[2] == incl[2]) {
                continue;
            }

            if (find(u, parent) != find(v, parent)) {
                Union(u, v, parent, rank);
                sum += wt;
            }
        }

        // Verify that all nodes are connected
        int root = find(0, parent);
        bool allConnected = true;
        for (int i = 1; i < n; i++) {
            if (find(i, parent) != root) {
                allConnected = false;
                break;
            }
        }

        if (!allConnected) return -1;
        return sum;
    }

public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        // Store original index of each edge
        for (int i = 0; i < edges.size(); i++) {
            edges[i].push_back(i);
        }

        // Sort edges based on weight
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });

        int baseMSTWeight = Kruskal(edges, edges[0], n, -1);
        vector<int> critical, pseudoCritical;

        for (int i = 0; i < edges.size(); i++) {
            vector<int>& edge = edges[i];

            // Try excluding this edge
            int excludedWeight = Kruskal(edges, edge, n, 1);
            if (excludedWeight == -1 || excludedWeight > baseMSTWeight) {
                critical.push_back(edge[3]);
                continue;
            }

            // Try force-including this edge
            int includedWeight = Kruskal(edges, edge, n, 2);
            if (includedWeight == baseMSTWeight) {
                pseudoCritical.push_back(edge[3]);
            }
        }

        vector<vector<int>> result;
        result.push_back(critical);
        result.push_back(pseudoCritical);
        return result;
    }
};
