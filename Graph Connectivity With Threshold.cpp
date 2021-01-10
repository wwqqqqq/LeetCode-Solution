class Solution {
public:
    void dfs(int node, int label, vector<vector<int>>& neighbors, vector<int>& labels) {
        if (node < 1 || node >= neighbors.size() || labels[node] >= 0) {
            return;
        }
        labels[node] = label;
        for (int i = 0; i < neighbors[node].size(); i++) {
            dfs(neighbors[node][i], label, neighbors, labels);
        }
    }
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        vector<vector<int>> neighbors(n+1, vector<int>());
        // generate connected relationship
        for (int i = threshold + 1; i <= n; i++) {
            for (int j = 2; i * j <= n; j++) {
                neighbors[i].push_back(i*j);
                neighbors[i*j].push_back(i);
            }
        }
        // find connected components
        int count = 0;
        vector<int> labels(n+1, -1);
        for (int i = 1; i <= n; i++) {
            if (labels[i] == -1) {
                dfs(i, count, neighbors, labels);
                count++;
            }
        }
        
        // determine if connected
        vector<bool> result;
        for (int i = 0; i < queries.size(); i++) {
            int n1 = queries[i][0];
            int n2 = queries[i][1];
            result.push_back(labels[n1] == labels[n2]);
        }
        return result;
    }
};