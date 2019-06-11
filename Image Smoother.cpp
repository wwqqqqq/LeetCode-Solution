class Solution {
public:
    int average(vector<vector<int>> &M, int x, int y) {
        int sum = 0, count = 0;
        for(int i = -1; i <= 1; i++) {
            if(x + i < 0 || x + i >= M.size())
                continue;
            for(int j = -1; j <= 1; j++) {
                if(y + j < 0 || y + j >= M[0].size())
                    continue;
                count++;
                sum += M[x+i][y+j];
            }
        }
        return sum / count;
    }
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        vector<vector<int>> result=M;
        for(int i = 0; i < M.size(); i++) {
            for(int j = 0; j < M[0].size(); j++) {
                result[i][j] = average(M, i, j);
            }
        }
        return result;
    }
};