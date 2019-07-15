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
    int largestComponentSize(vector<int>& A) {
        if(A.size() <= 1)
            return A.size();
        int max_n = 0;
        for(int i = 0; i < A.size(); i++) {
            if(max_n < A[i]) max_n = A[i];
        }
        getPrimes(max_n);
        getFactors(A);
        vector<int> group(A.size(), 0);
        group[0] = 1;
        vector<int> visited = {0};
        int group_id = 2;
        for(int i = 1; i < A.size(); i++) {
            for(int j = 0; j < visited.size(); j++) {
                if(group[i] == group[visited[j]])
                    continue;
                if(commonFactor(i, visited[j])) {
                    if(group[i] == 0) {
                        group[i] = group[visited[j]];
                        visited.push_back(i);
                    }
                    else {
                        for(auto iter = visited.begin(); iter != visited.end(); iter++)
                            if(group[*iter] == group[visited[j]])
                                group[*iter] = group[i];
                    }
                }
            }
            if(group[i] == 0) {
                group[i] = group_id;
                group_id++;
                visited.push_back(i);
            }
        }
        vector<int> group_size(group_id, 0);
        int max = 0;
        for(int i = 0; i < A.size(); i++) {
            group_size[group[i]]++;
            if(group_size[group[i]] > max) max = group_size[group[i]];
        }
        for(int i = 0; i < group_size.size(); i++)
            if(max < group_size[i]) max = group_size[i];
        return max;
    }
};