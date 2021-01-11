class Solution {
public:
    void addEdge(vector<set<int>>& neighbors, int a, int b) {
        if (a < 0 || b < 0 || a >= neighbors.size() || b >= neighbors.size()) {
            return;
        }
        neighbors[a].insert(b);
        neighbors[b].insert(a);
    }
    void removeEdge(vector<set<int>>& neighbors, int a, int b) {
        if (a < 0 || b < 0 || a >= neighbors.size() || b >= neighbors.size()) {
            return;
        }
        auto iter1 = neighbors[a].find(b);
        auto iter2 = neighbors[b].find(a);
        if (iter1 != neighbors[a].end()) {
            neighbors[a].erase(iter1);
        }
        if (iter2 != neighbors[b].end()) {
            neighbors[b].erase(iter2);
        }
    }
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        // count number of new nodes
        int count = 0;
        for (auto& edge : edges) {
            count += edge[2];
        }
        // construct graph
        vector<set<int>> neighbors(N + count, set<int>());
        // for (int i = 0; i < N; i++) {
        //     for (int j = i+1; j < N; j++) {
        //         addEdge(neighbors, i, j);
        //     }
        // }
        
        int index = N;
        for (auto& edge : edges) {
            int n1 = edge[0];
            int n2 = edge[1];
            removeEdge(neighbors, n1, n2);
            
            if (edge[2] > 0) {
                addEdge(neighbors, n1, index);
                for (int i = 0; i < edge[2]-1; i++, index++) {
                    addEdge(neighbors, index, index + 1);
                }
                addEdge(neighbors, index, n2);
                index++;
            }
            else {
                addEdge(neighbors, n1, n2);
            }
        }
        
        // count nodes
        queue<pair<int,int>> q;
        set<int> visited;
        q.push(pair<int,int>(0,M));
        while(q.size() > 0) {
            pair<int,int> p = q.front();
            int node = p.first;
            int m = p.second;
            q.pop();
            if (visited.find(node) != visited.end()) {
                continue;
            }
            visited.insert(node);
            if (m > 0) {
                for (auto& neighbor : neighbors[node]) {
                    q.push(pair<int,int>(neighbor, m-1));
                }
            }
        }
        return visited.size();
    }
};