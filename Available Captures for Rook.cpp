class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int x, y;
        bool found = false;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++)
                if(board[i][j] == 'R') {
                    found = true;
                    x = i;
                    y = j;
                    break;
                }
            if(found)
                break;
        }
        int count = 0;
        // left
        for(int i = x - 1; i >= 0; i--)
            if(board[i][y] == 'B')
                break;
            else if(board[i][y] == 'p') {
                count++;
                break;
            }
        
        // up
        for(int i = y - 1; i >= 0; i--)
            if(board[x][i] == 'B')
                break;
            else if(board[x][i] == 'p'){
                count++;
                break;
            }
        // right
        for(int i = x + 1; i < board.size(); i++)
            if(board[i][y] == 'B')
                break;
            else if(board[i][y] == 'p'){
                count++;
                break;
            }
        // down
        for(int i = y + 1; i < board[0].size(); i++)
            if(board[x][i] == 'B')
                break;
            else if(board[x][i] == 'p'){
                count++;
                break;
            }
        return count;
    }
};