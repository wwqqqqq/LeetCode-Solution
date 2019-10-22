class Solution {
public:
    bool exist(vector<vector<char>>& board, string word, int row, int col, set<pair<int,int>>& visited) {
        if(word.size() == 0)
            return true;
        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
            return false;
        pair<int,int> pos(row,col);
        if(visited.find(pos) != visited.end() || board[row][col] != word[0])
            return false;
        if(word.size() == 1)
            return true;
        string s = word.substr(1);
        visited.insert(pos);
        if(exist(board,s,row-1,col,visited)) {
            visited.erase(pos);
            return true;
        }
        if(exist(board,s,row+1,col,visited)) {
            visited.erase(pos);
            return true;
        }
        if(exist(board,s,row,col-1,visited)) {
            visited.erase(pos);
            return true;
        }
        if(exist(board,s,row,col+1,visited)) {
            visited.erase(pos);
            return true;
        }
        visited.erase(pos);
        return false;
    }
    /* BFS is not right in this!!! Because other path may use the visited nodes!!!
    bool exist(vector<vector<char>>& board, string word, int row, int col) {
        set<pair<int,int>> visited;
        queue<pair<int,int>> q;
        queue<int> index;
        q.push(pair<int,int>(row, col));
        index.push(0);
        visited.insert(pair<int,int>(row, col));
        while(q.size() > 0) {
            auto pos = q.front();
            int r = pos.first;
            int c = pos.second;
            int ind = index.front();
            q.pop();
            index.pop();
            if(ind >= word.size())
                return false;
            if(word[ind] != board[r][c])
                continue;
            ind++;
            if(ind == word.size())
                return true;
            if(r > 0 && board[r-1][c] == word[ind]) {
                pair<int,int> temp(r-1,c);
                if(visited.find(temp) == visited.end()) {
                    index.push(ind);
                    q.push(temp);
                    visited.insert(temp);
                }
            }
            if(r + 1 < board.size() && board[r+1][c] == word[ind]) {
                pair<int,int> temp(r+1,c);
                if(visited.find(temp) == visited.end()) {
                    index.push(ind);
                    q.push(temp);
                    visited.insert(temp);
                }
            }
            if(c > 0 && board[r][c-1] == word[ind]) {
                pair<int,int> temp(r,c-1);
                if(visited.find(temp) == visited.end()) {
                    index.push(ind);
                    q.push(temp);
                    visited.insert(temp);
                }
            }
            if(c + 1 < board[0].size() && board[r][c+1] == word[ind]) {
                pair<int,int> temp(r,c+1);
                if(visited.find(temp) == visited.end()) {
                    index.push(ind);
                    q.push(temp);
                    visited.insert(temp);
                }
            }
        }
        return false;
    }*/
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() == 0 || board.size() == 0 || board[0].size() == 0)
            return false;
        set<pair<int,int>> s;
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(word[0] == board[i][j] && exist(board, word, i, j, s))
                    return true;
            }
        }
        return false;
    }
};