class TicTacToe {
public:
    /** Initialize your data structure here. */
    vector<int> horizontal1;
    vector<int> horizontal2;
    vector<int> vertical1;
    vector<int> vertical2;
    int d11;
    int d12;
    int d21;
    int d22;
    int len;
    TicTacToe(int n) {
        for(int i = 0; i < n; i++) {
            horizontal1.push_back(0);
            horizontal2.push_back(0);
            vertical1.push_back(0);
            vertical2.push_back(0);
        }
        d11 = 0;
        d12 = 0;
        d21 = 0;
        d22 = 0;
        len = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if(player == 1) {
            horizontal1[row]++;
            vertical1[col]++;
            if(len == horizontal1[row] || len == vertical1[col])
                return 1;
            if(row == col)
                d11++;
            if(row + col == len-1)
                d21++;
            if(d11 == len || d21 == len)
                return 1;
        }
        else {
            horizontal2[row]++;
            vertical2[col]++;
            if(len == horizontal2[row] || len == vertical2[col])
                return 2;
            if(row == col)
                d12++;
            if(row + col == len-1)
                d22++;
            if(d12 == len || d22 == len)
                return 2;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */