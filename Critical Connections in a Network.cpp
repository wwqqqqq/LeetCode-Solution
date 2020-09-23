class Solution {
public:
    bool DFS(vector<vector<int>>& graph, vector<set<int>>& edgeList, int v, int b, int n, set<int>& visited) {
        if(v == b) {
            return true;
        }
        if(edgeList[v].find(b) != edgeList[v].end()) {
            graph[v][b] = 2;
            graph[b][v] = 2;
            return true;
        }
        for(auto iter = edgeList[v].begin(); iter != edgeList[v].end(); iter++) {
            int i = *iter;
            if(graph[v][i] > 0) {
                if(visited.find(i) != visited.end())
                    continue;
                visited.insert(i);
                if(i == b || DFS(graph, edgeList, i, b, n, visited)) {
                    graph[v][i] = 2;
                    graph[i][v] = 2;
                    return true;
                }
            }
        }
        return false;
    }
    bool canAccess(vector<vector<int>>& graph, vector<set<int>>& edgeList, int a, int b, int n) {
        // return is the path exists.
        // if path exists, find the path, and mark every edge on the path '2' on the graph
        // use DFS
        set<int> visited;
        return DFS(graph, edgeList, a, b, n, visited);
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n, vector<int>(n, 0));
        vector<set<int>> edgeList(n, set<int>());
        vector<vector<int>> result;
        for(int i = 0; i < connections.size(); i++) {
            int v1 = connections[i][0];
            int v2 = connections[i][1];
            graph[v1][v2] = 1;
            graph[v2][v1] = 1;
            edgeList[v1].insert(v2);
            edgeList[v2].insert(v1);
        }
        for(int i = 0; i < connections.size(); i++) {
            int v1 = connections[i][0];
            int v2 = connections[i][1];
            if(graph[v1][v2] == 2)
                continue;
            graph[v1][v2] = 0;
            graph[v2][v1] = 0;
            edgeList[v1].erase(v2);
            edgeList[v2].erase(v1);
            if(!canAccess(graph, edgeList, v1, v2, n)) {
                result.push_back({v1, v2});
                graph[v1][v2] = 1;
                graph[v2][v1] = 1;
            }
            else {
                graph[v1][v2] = 2;
                graph[v2][v1] = 2;
            }
            edgeList[v1].insert(v2);
            edgeList[v2].insert(v1);
        }
        return result;
    }
};