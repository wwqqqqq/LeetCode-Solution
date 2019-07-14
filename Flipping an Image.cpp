class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(int i = 0; i < A.size(); i++) {
            for(int j = 0; j < A[i].size() && A[i].size() - j - 1 >= j; j++) {
                int temp = 1 - A[i][A[i].size() - j - 1];
                A[i][A[i].size() - j - 1] = 1 - A[i][j];
                A[i][j] = temp;
            }
        }
        return A;
    }
};