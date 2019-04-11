class Solution {
public:
    bool isSolvable(vector<vector<char>>& board, vector<vector<int>> &rows, vector<vector<int>> &cols,
                    vector<vector<int>> &boxes, vector<pair<int,int>> &blank, int st) {
        if(st >= blank.size())
            return true;
        int r = blank[st].first, c = blank[st].second;
        int b = (r / 3) * 3 + c / 3;
        for(int i = 0; i < 9; i++) {
            if(rows[r][i] == 1 || cols[c][i] == 1 || boxes[b][i] == 1)
                continue;
            rows[r][i] = 1; cols[c][i] = 1; boxes[b][i] = 1;
            board[r][c] = i + 1 + '0';
            if(isSolvable(board, rows, cols, boxes, blank, st+1))
                return true;
            rows[r][i] = 0; cols[c][i] = 0; boxes[b][i] = 0;
            board[r][c] = '.';
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rows(9, vector<int>(9, 0));
        vector<vector<int>> cols(9, vector<int>(9, 0));
        vector<vector<int>> boxes(9, vector<int>(9, 0));
        vector<pair<int,int>> blank;
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {
                    blank.push_back(make_pair(i, j));
                    continue;
                }
                
                int box_ind = (i / 3) * 3 + j / 3;
                int num = board[i][j] - '0' - 1;
                if(num >= 9 || num < 0)
                    return;
                if(rows[i][num] != 0)
                    return;
                if(cols[j][num] != 0)
                    return;
                if(boxes[box_ind][num] != 0)
                    return;
                rows[i][num] = 1;
                cols[j][num] = 1;
                boxes[box_ind][num] = 1;
            }
        }
        
        isSolvable(board, rows, cols, boxes, blank, 0);
         
    }
};