class Solution {
public:
    int dotProd(vector<pair<int,int>>& a, vector<pair<int,int>>& b) {
        // it's similar to merge
        // we find any common index of a and b and multiply their corresponding value
        int i = 0;
        int j = 0;
        int sum = 0;
        while(i < a.size() && j < b.size()) {
            if(a[i].first == b[j].first) {
                sum += a[i].second * b[j].second;
                i++;
                j++;
            }
            else if(a[i].first < b[j].first)
                i++;
            else j++;
        }
        return sum;
    }
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        // normal way
        // brute force
        // O(A.size() * B.size * B[0].size())
        // because A and B are sparse matrix
        // consider using a different data structure to store the elements of A and B
        if(A.size() == 0 || A[0].size() == 0 || A[0].size() != B.size() || B[0].size() == 0) {
            vector<vector<int>> result;
            return result;
        }
        vector<vector<int>> result(A.size(), vector<int>(B[0].size(), 0));
        vector<vector<pair<int,int>>> A_s(A.size());
        vector<vector<pair<int,int>>> B_s(B[0].size());
        // A_s[i] is the sparse representation of the i-th row of A
        // B_s[j] is the sparse representation of the i-th col of B
        // C[i][j] = A[i]_s dot multiply B[j]_s
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < A[0].size(); j++) {
                if(A[i][j] != 0)
                    A_s[i].push_back(pair<int,int>(j, A[i][j]));
            }
        }
        for(int i = 0; i < B.size(); i++) {
            for(int j = 0; j < B[0].size(); j++) {
                if(B[i][j] != 0)
                    B_s[j].push_back(pair<int,int>(i, B[i][j]));
            }
        }
        for(int i = 0; i < result.size(); i++) {
            for(int j = 0; j < result[0].size(); j++) {
                // calculate result[i][j]
                // by apply dot product on A_s[i] and B_s[j]
                result[i][j] = dotProd(A_s[i], B_s[j]);
            }
        }
        return result;
    }
};