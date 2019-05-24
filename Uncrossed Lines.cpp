class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B, int a, int b, vector<vector<int>>& result) {
        if(a >= A.size() || b >= B.size())
            return 0;
        if(result[a][b] != -1)
            return result[a][b];
        int max = 0;
        for(int i = b; i < B.size(); i++) {
            if(B[i] == A[a]) {
                int t = maxUncrossedLines(A, B, a+1, i+1, result) + 1;
                if(max < t) max = t;
            }
        }
        int t = maxUncrossedLines(A, B, a+1, b, result);
        if(max < t) max = t;
        result[a][b] = max;
        return max;
    }
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        vector<vector<int>> result(A.size(), vector<int>(B.size(), -1));
        return maxUncrossedLines(A, B, 0, 0, result);
    }
};