class Solution {
public:
    bool conflict(int n, vector<int>& pos, int c2) {
        int r2 = pos.size();
        for(int i = 0; i < pos.size(); i++) {
            int r1 = i;
            int c1 = pos[i];
            if(c1 == c2 || r1 == r2)
                return true;
            if(c1 - r1 == c2 - r2 || c1 - c2 == r2 - r1)
                return true;
        }
        return false;
    }
    vector<string> constructGraph(vector<int>& pos) {
        vector<string> result;
        for(int i = 0; i < pos.size(); i++) {
            string s;
            s.append(pos[i],'.');
            s.append("Q");
            s.append(pos.size()-pos[i]-1, '.');
            result.push_back(s);
        }
        return result;
    }
    void solveNQueens(int n, vector<int>& pos, vector<vector<string>>& result) {
        if(pos.size() == n) {
            vector<string> solution = constructGraph(pos);
            result.push_back(solution);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(!conflict(n, pos, i)) {
                pos.push_back(i);
                solveNQueens(n, pos, result);
                pos.erase(pos.end()-1,pos.end());
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<int> pos;
        solveNQueens(n, pos, result);
        return result;
    }
};