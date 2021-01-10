class Solution {
public:
    void dfs(int node, vector<vector<int>>& neighbors, int label, vector<int>& labels) {
        if (labels[node] >= 0) return;
        labels[node] = label;
        for (int i = 0; i < neighbors[node].size(); i++) {
            dfs(neighbors[node][i], neighbors, label, labels);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> labels(n, -1);
        vector<vector<int>> neighbors(n, vector<int>());
        for (int i = 0; i < edges.size(); i++) {
            int n1 = edges[i][0];
            int n2 = edges[i][1];
            neighbors[n1].push_back(n2);
            neighbors[n2].push_back(n1);
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (labels[i] >= 0) {
                continue;
            }
            dfs(i, neighbors, count, labels);
            count++;
        }
        return count;
    }
};