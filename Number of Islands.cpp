class Solution {
public:
    void BFS(vector<vector<char>>& grid, vector<vector<int>>& group, pair<int,int> root, int id) {
        queue<pair<int,int>> q;
        q.push(root);
        group[root.first][root.second] = id;
        while(q.size() > 0) {
            pair<int,int> node = q.front();
            q.pop();
            int row = node.first;
            int col = node.second;
            // up
            if(row > 0 && grid[row-1][col] == '1' && group[row-1][col]==-1) {
                q.push(pair<int,int>(row-1,col));
                group[row-1][col] = id;
            } 
            if(row + 1 < grid.size() && grid[row+1][col] == '1' && group[row+1][col]==-1) {
                q.push(pair<int,int>(row+1,col));
                group[row+1][col] = id;
            }
            if(col > 0 && grid[row][col-1] == '1' && group[row][col-1]==-1) {
                q.push(pair<int,int>(row,col-1));
                group[row][col-1] = id;
            }
            if(col + 1 < grid[0].size() && grid[row][col+1] == '1' && group[row][col+1]==-1) {
                q.push(pair<int,int>(row,col+1));
                group[row][col+1] = id;
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        vector<vector<int>> group(grid.size(), vector<int>(grid[0].size(),-1));
        
        int group_id = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] != '1')
                    continue;
                if(group[i][j] != -1)
                    continue;
                group_id++;
                BFS(grid, group, pair<int,int>(i,j), group_id);
            }
        }
        return group_id;
    }
};