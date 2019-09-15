class Solution {
public:
    bool DFS(vector<vector<int>>& graph, int v, int b, int n, set<int>& visited) {
        for(int i = 0; i < n; i++) {
            if(graph[v][i] > 0) {
                if(i == b) {
                    graph[v][b] = 2;
                    graph[b][v] = 2;
                    return true;
                }
                if(visited.find(i) != visited.end())
                    continue;
                int t = graph[v][i];
                graph[v][i] = 2;
                graph[i][v] = 2;
                visited.insert(i);
                if(DFS(graph, i, b, n, visited))
                    return true;
                graph[v][i] = t;
                graph[i][v] = t;
            }
        }
        return false;
    }
    bool canAccess(vector<vector<int>>& graph, int a, int b, int n) {
        // return is the path exists.
        // if path exists, find the path, and mark every edge on the path '2' on the graph
        // use DFS
        set<int> visited;
        return DFS(graph, a, b, n, visited);
        /*// use BFS
        queue<int> nodes;
        set<int> visited;
        nodes.push(a);
        while(nodes.size() > 0) {
            int v = nodes.front();
            nodes.pop();
            visited.insert(v);
            for(int i = 0; i < n; i++) {
                if(graph[v][i] == 1) {
                    if(i == b)
                        return true;
                    if(visited.find(i) != visited.end())
                        continue;
                    nodes.push(i);
                }
            }
        }*/
        return false;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n, vector<int>(n, 0));
        vector<vector<int>> result;
        for(int i = 0; i < connections.size(); i++) {
            int v1 = connections[i][0];
            int v2 = connections[i][1];
            graph[v1][v2] = 1;
            graph[v2][v1] = 1;
        }
        for(int i = 0; i < connections.size(); i++) {
            int v1 = connections[i][0];
            int v2 = connections[i][1];
            if(graph[v1][v2] == 2)
                continue;
            graph[v1][v2] = 0;
            graph[v2][v1] = 0;
            if(!canAccess(graph, v1, v2, n)) {
                vector<int> temp = {v1, v2};
                result.push_back(temp);
            }
            graph[v1][v2] = 1;
            graph[v2][v1] = 1;
        }
        return result;
    }
};