class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<int> lastLine(board[0].size(), 0);
        for(int i = 0; i < board.size(); i++) {
            int last = 0;
            vector<int> currentLine(board[i]);
            for(int j = 0; j < board[0].size(); j++) {
                int state = board[i][j];
                int numLiveCell = lastLine[j] + last;
                if(j-1 >= 0) 
                    numLiveCell += lastLine[j-1];
                if(j+1 < board[0].size()) 
                    numLiveCell += lastLine[j+1] + board[i][j+1];
                if(i+1 < board.size()) {
                    numLiveCell += board[i+1][j];
                    if(j-1 >= 0) 
                        numLiveCell += board[i+1][j-1];
                    if(j+1 < board[0].size()) 
                        numLiveCell += board[i+1][j+1];
                }
                if(numLiveCell == 3) board[i][j] = 1;
                else if(numLiveCell < 2) board[i][j] = 0;
                else if(numLiveCell > 3) board[i][j] = 0;
                last = state;
            }
            for(int j = 0; j < board[0].size(); j++) {
                lastLine[j] = currentLine[j];
            }
        }
    }
};