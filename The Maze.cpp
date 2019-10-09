class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        // there are two options to get to the result
        // DFT
        // BFT *
        if(start[0] == destination[0] && start[1] == destination[1])
            return true;
        if(maze.size() == 0 || maze[0].size() == 0)
            return false;
        queue<pair<int,int>> q;
        q.push(pair<int,int>(start[0], start[1]));
        set<pair<int,int>> visited;
        while(q.size() > 0) {
            pair<int,int> node = q.front();
            int row = node.first;
            int col = node.second;
            q.pop();
            // we should determine which nodes in the maze that we can approach to from node
            // up
            int i;
            if(row > 0 && maze[row-1][col] != 1) {
                // the ball can go up
                for(i = row-1; i >= 0; i--) {
                    if(maze[i][col] == 1)
                        break;
                }
                i++;
                if(i == destination[0] && col == destination[1])
                    return true;
                pair<int,int> next(i, col);
                if(visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push(next);
                }
            }
            // down
            if(row < maze.size()-1 && maze[row+1][col] != 1) {
                // the ball can go down
                for(i = row+1; i < maze.size(); i++) {
                    if(maze[i][col] == 1)
                        break;
                }
                i--;
                if(i == destination[0] && col == destination[1])
                    return true;
                pair<int,int> next(i, col);
                if(visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push(next);
                }
            }
            // left
            if(col > 0 && maze[row][col-1] != 1) {
                for(i = col-1; i >= 0; i--)
                    if(maze[row][i] == 1)
                        break;
                i++;
                if(row == destination[0] && i == destination[1])
                    return true;
                pair<int,int> next(row, i);
                if(visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push(next);
                }
            }
            // right
            if(col < maze[0].size()-1 && maze[row][col+1] != 1) {
                for(i = col+1; i < maze[0].size(); i++) 
                    if(maze[row][i] == 1)
                        break;
                i--;
                if(row == destination[0] && i == destination[1])
                    return true;
                pair<int,int> next(row, i);
                if(visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }
        return false;
    }
};