class Solution {
public:
    vector<int> primes;
    vector<vector<int>> factors;
    void getPrimes(int max) {
        primes.push_back(2);
        primes.push_back(3);
        primes.push_back(5);
        primes.push_back(7);
        for(int i = 11; i <= max; i++) {
            int j = 0;
            for(; j < primes.size(); j++) {
                if(i % primes[j] == 0)
                    break;
            }
            if(j >= primes.size())
                primes.push_back(i);
        }
    }
    void getFactors(vector<int> &A) {
        for(int i = 0; i < A.size(); i++) {
            vector<int> temp;
            for(int j = 0; j < primes.size(); j++) {
                int p = primes[j];
                if(p > A[i]) break;
                if(A[i] % p == 0)
                    temp.push_back(p);
            }
            factors.push_back(temp);
        }
    }
    bool commonFactor(int a, int b) {
        /*for(int i = 0; i < primes.size(); i++) {
            int p = primes[i];
            if(p > a || p > b)
                break;
            if(a % p == 0 && b % p == 0)
                return true;
        }
        return false;*/
        int i = 0;
        int j = 0;
        while(i < factors[a].size() && j < factors[b].size()) {
            if(factors[a][i] == factors[b][j])
                return true;
            else if(factors[a][i] < factors[b][j])
                i++;
            else j++;
        }
        return false;
    }
    int dfs(vector<vector<int>> &graph, vector<int> & group, int group_id, int root) {
        int size = group.size();
        stack<int> nodes;
        int count = 0;
        nodes.push(root);
        while(nodes.size() > 0) {
            int p = nodes.top();
            nodes.pop();
            if(group[p] != -1)
                continue;
            group[p] = group_id;
            count++;
            for(int i = 0; i < size; i++) {
                if(graph[p][i] == 1 && group[i] == -1)
                    nodes.push(i);
            }
        }
        return count;
    }
    int largestComponentSize(vector<int>& A) {
        if(A.size() <= 1)
            return A.size();
        vector<vector<int>> graph(A.size(), vector<int>(A.size(), 0));
        int max_n = 0;
        for(int i = 0; i < A.size(); i++) {
            if(max_n < A[i]) max_n = A[i];
        }
        getPrimes(max_n);
        getFactors(A);
        for(int i = 0; i < A.size(); i++) {
            graph[i][i] = 1;
            for(int j = i + 1; j < A.size(); j++) {
                if(commonFactor(i, j)) {
                    graph[i][j] = 1;
                    graph[j][i] = 1;
                }
            }
        }
        vector<int> group(A.size(), -1);
        int max = 0;
        int group_id = 1;
        for(int i = 0; i < A.size(); i++) {
            if(group[i] != -1)
                continue;
            int count = dfs(graph, group, group_id, i);
            if(count > max) max = count;
            group_id = group_id + 1;
        }
        return max;
    }
};