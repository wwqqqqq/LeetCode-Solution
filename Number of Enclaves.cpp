class Solution {
public:
    void expand(vector<vector<int>>& A, int x, int y) {
        if(A.size() == 0 || A[0].size() == 0)
            return;
        stack<pair<int,int>> ones;
        ones.push(pair<int,int>(x,y));
        A[x][y] = -1;
        while(ones.size() > 0) {
            auto pos = ones.top();
            ones.pop();
            x = pos.first;
            y = pos.second;
            // left
            if(x > 0 && A[x-1][y] == 1) {
                A[x-1][y] = -1;
                ones.push(pair<int,int>(x-1, y));
            }
            // right
            if(x < A.size() - 1 && A[x+1][y] == 1){
                A[x+1][y] = -1;
                ones.push(pair<int,int>(x+1, y));
            }
            // down
            if(y < A[0].size() - 1 && A[x][y+1] == 1){
                A[x][y+1] = -1;
                ones.push(pair<int,int>(x, y+1));
            }
            // up
            if(y > 0 && A[x][y-1] == 1){
                A[x][y-1] = -1;
                ones.push(pair<int,int>(x, y-1));
            }
        }
    }
    int numEnclaves(vector<vector<int>>& A) {
        if(A.size() == 0 || A[0].size() == 0)
            return 0;
        for(int i = 0; i < A.size(); i++) {
            if(A[i][0] == 1)
                expand(A, i, 0);
            if(A[i][A[0].size()-1] == 1)
                expand(A, i, A[0].size()-1);
        }
        for(int i = 0; i < A[0].size(); i++) {
            if(A[0][i] == 1)
                expand(A, 0, i);
            if(A[A.size()-1][i] == 1)
                expand(A, A.size()-1, i);
        }
        int count = 0;
        for(int i = 0; i < A.size(); i++)
            for(int j = 0; j < A[0].size(); j++)
                if(A[i][j] == 1)
                    count++;
        return count;
    }
};