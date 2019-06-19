class Solution {
public:
    /*vector<vector<int>> combine(int n, int k) {
        // iteratively
        // n >= k
        vector<vector<int>> result;
        if(n == k) {
            vector<int> temp;
            for(int i = 1; i <= n; i++)
                temp.push_back(i);
            result.push_back(temp);
            return result;
        }
        if(k == 1) {
            for(int i = 1; i <= n; i++) {
                vector<int> temp = {i};
                result.push_back(temp);
            }
            return result;
        }
        for(int i = n; i >= k; i--) {
            vector<vector<int>> r = combine(i-1, k-1);
            for(int j = 0; j < r.size(); j++)
                r[j].push_back(i);
            result.insert(result.end(), r.begin(), r.end());
        }
        return result;
    }*/
    vector<vector<int>> combine(int n, int k) {
        // non-iterative
        if(n == k) {
            vector<vector<int>> result;
            vector<int> temp;
            for(int i = 1; i <= n; i++)
                temp.push_back(i);
            result.push_back(temp);
            return result;
        }
        if(k == 1) {
            vector<vector<int>> result;
            for(int i = 1; i <= n; i++) {
                vector<int> temp = {i};
                result.push_back(temp);
            }
            return result;
        }
        vector<vector<vector<int>>> results;
        for(int i = 1; i <= n-k+1; i++) {
            vector<vector<int>> temp;
            vector<int> temp2 = {i};
            temp.push_back(temp2);
            results.push_back(temp);
        }
        for(int i = 2; i <= k; i++) {
            vector<vector<vector<int>>> temp;
            for(int j = 0; j < n-k+1; j++) {
                vector<vector<int>> temp2;
                for(int m = 0; m <= j; m++) {
                    vector<vector<int>> temp3 = results[m];
                    for(int n = 0; n < temp3.size(); n++)
                        temp3[n].push_back(j + i);
                    temp2.insert(temp2.end(), temp3.begin(), temp3.end());
                }
                temp.push_back(temp2);
            }
            results = temp;
        }
        vector<vector<int>> result;
        for(int i = 0; i < results.size(); i++)
            result.insert(result.end(), results[i].begin(), results[i].end());
        return result;
    }
};