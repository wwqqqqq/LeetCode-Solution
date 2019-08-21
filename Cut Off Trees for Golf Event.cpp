class Solution {
public:
    int getRowIndex(int rows, int cols, int index) {
        return (index / cols);
    }
    int getColIndex(int rows, int cols, int index) {
        return (index % cols);
    }
    int getIndex(int rows, int cols, int rind, int cind) {
        return (cind + rind * cols);
    }
    int shortestPath(vector<vector<int>>& forest, vector<vector<int>>& map, int start, int dest) {
        if(dest == start)
            return 0;
        int rows = forest.size();
        int cols = forest[0].size();
        int count = rows * cols;
        /*int rs = getRowIndex(rows, cols, start);
        int cs = getColIndex(rows, cols, start);
        if(forest[rs][cs] == 0)
            return;*/
        // BFS
        queue<int> s;
        s.push(start);
        set<int> visited = {start};
        map[start][start] = 0;
        while(s.size() > 0) {
            int i = s.front();
            s.pop();
            /*if(map[i][dest] != -1)
                return map[i][dest] + map[start][i];*/ // WRONG statement!
            int step = map[start][i];
            int r = getRowIndex(rows, cols, i);
            int c = getColIndex(rows, cols, i);
            // right
            if(c + 1 < cols && forest[r][c+1] > 0 && 
               visited.find(getIndex(rows, cols, r, c+1)) == visited.end()) {
                map[start][i+1] = step + 1;
                map[i+1][start] = step + 1;
                if(i+1 == dest)
                    return step+1;
                visited.insert(i+1);
                s.push(i+1);
            }
            // down
            if(r + 1 < rows && forest[r+1][c] > 0 && 
               visited.find(getIndex(rows, cols, r+1, c)) == visited.end()) {
                map[start][i+cols] = step + 1;
                map[i+cols][start] = step + 1;
                if(i+cols == dest)
                    return step+1;
                visited.insert(i+cols);
                s.push(i+cols);
            }
            // left
            if(c - 1 >= 0 && forest[r][c-1] > 0 && 
               visited.find(getIndex(rows, cols, r, c-1)) == visited.end()) {
                map[start][i-1] = step + 1;
                map[i-1][start] = step + 1;
                if(i-1 == dest)
                    return step+1;
                visited.insert(i-1);
                s.push(i-1);
            }
            // up
            if(r - 1 >= 0 && forest[r-1][c] > 0&& 
               visited.find(getIndex(rows, cols, r-1, c)) == visited.end()) {
                map[start][i-cols] = step + 1;
                map[i-cols][start] = step + 1;
                if(i-cols == dest)
                    return step+1;
                visited.insert(i-cols);
                s.push(i-cols);
            }
        }
        return -1;
    }
    const int EQUAL = 0;
    const int LESS = 1;
    const int LARGER = 2;
    int compare(vector<vector<int>>& forest, int pos1, int pos2) {
        int rows = forest.size();
        int cols = forest[0].size();
        int r1 = getRowIndex(rows, cols, pos1);
        int c1 = getColIndex(rows, cols, pos1);
        int r2 = getRowIndex(rows, cols, pos2);
        int c2 = getColIndex(rows, cols, pos2);
        if(forest[r1][c1] == forest[r2][c2])
            return EQUAL;
        else if(forest[r1][c1] < forest[r2][c2])
            return LESS;
        else return LARGER;
        return LARGER;
    }
    void insert2SortedList(vector<vector<int>>& forest, vector<int>& list, int e) {
        int begin = 0;
        int end = list.size() - 1;
        while(begin <= end) {
            int mid = (begin + end) / 2;
            int c = compare(forest, list[mid], e);
            if(c == EQUAL) {
                list.insert(list.begin() + mid, e);
                return;
            }
            else if(c == LESS)
                begin = mid + 1;
            else end = mid - 1;
        }
        // Now begin > end
        // so the case is `list[begin-1] < e` or `list[end+1] > e`
        // aka `list[end] < e` or `list[begin] > e`
        // there is one thing for sure: `list[end] < list[begin]`
        // if list[end] < e, then list[begin] either does not exist, or larger than e
        // if list[begin] is less than e, end will not be less than begin in the first place
        // so e must be located between end and begin
        list.insert(list.begin() + begin, e);
    }
    int cutOffTree(vector<vector<int>>& forest) {
        if(forest.size()==0 || forest[0].size()==0 || forest[0][0] == 0)
            return -1;
        int rows = forest.size();
        int cols = forest[0].size();
        int count = rows * cols;
        vector<vector<int>> map(count, vector(count, -1));
        /*//buildMap(forest, map);
        for(int i = 0; i < count; i++)
            shortestPath(forest, map, i);*/
        // sort the height of trees
        vector<int> list;
        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++) {
                int index = getIndex(rows, cols, i, j);
                if(forest[i][j] > 1)
                    insert2SortedList(forest, list, index);
            }
        // walk through forest from the shortest tree to the highest
        int sum = 0;
        int current = 0;
        for(int i = 0; i < list.size(); i++) {
            int path = shortestPath(forest, map, current, list[i]);
            if(path == -1)
                return -1;
            sum += path;
            current = list[i];
        }
        return sum;
    }
};