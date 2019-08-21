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
    /*void heapInsert(vector<int>& heap, int e, vector<vector<int>>& map, int row) {
        // TODO
    }
    void heapDeleteTop(vector<int>& heap, vector<vector<int>>& map, int row) {
        // TODO
    }
    void heapUpdate(vector<int>& heap, int loc, vector<vector<int>>& map, int row) {
        // TODO
    }
    */
    void shortestPath(vector<vector<int>>& forest, vector<vector<int>>& map, int start) {
        int rows = forest.size();
        int cols = forest[0].size();
        int count = rows * cols;
        int rs = getRowIndex(rows, cols, start);
        int cs = getColIndex(rows, cols, start);
        if(forest[rs][cs] == 0)
            return;
        // BFS
        queue<int> s;
        s.push(start);
        set<int> visited = {start};
        map[start][start] = 0;
        while(s.size() > 0) {
            int i = s.front();
            s.pop();
            int step = map[start][i];
            int r = getRowIndex(rows, cols, i);
            int c = getColIndex(rows, cols, i);
            // right
            if(c + 1 < cols && forest[r][c+1] > 0 && 
               visited.find(getIndex(rows, cols, r, c+1)) == visited.end()) {
                map[start][i+1] = step + 1;
                visited.insert(i+1);
                s.push(i+1);
            }
            // down
            if(r + 1 < rows && forest[r+1][c] > 0 && 
               visited.find(getIndex(rows, cols, r+1, c)) == visited.end()) {
                map[start][i+cols] = step + 1;
                visited.insert(i+cols);
                s.push(i+cols);
            }
            // left
            if(c - 1 >= 0 && forest[r][c-1] > 0 && 
               visited.find(getIndex(rows, cols, r, c-1)) == visited.end()) {
                map[start][i-1] = step + 1;
                visited.insert(i-1);
                s.push(i-1);
            }
            // up
            if(r - 1 >= 0 && forest[r-1][c] > 0&& 
               visited.find(getIndex(rows, cols, r-1, c)) == visited.end()) {
                map[start][i-cols] = step + 1;
                visited.insert(i-cols);
                s.push(i-cols);
            }
        }
        /*// dijikstra
        vector<int> heap;
        for(int i = 0; i < map.size(); i++) {
            if(map[start][i] != -1)
                heapInsert(heap, i);
        }
        while(heap.size() > 0) {
            int i = heap[0];
            heapDeleteTop(heap, map, start);
        }
        */
    }
    void buildMap(vector<vector<int>>& forest, vector<vector<int>>& map) {
        int rows = forest.size();
        int cols = forest[0].size();
        int count = rows * cols;
        for(int i = 0; i < count; i++) {
            map[i][i] = 0;
            int r = getRowIndex(rows, cols, i);
            int c = getColIndex(rows, cols, i);
            if(forest[r][c] == 0) {
                /*for(int j = 0; j < count; j++) {
                    map[i][j] = -1;
                    map[j][i] = -1;
                }*/
                continue;
            }
            // right
            if(c + 1 < cols && forest[r][c+1] > 0) {
                map[i][i+1] = 1;
                map[i+1][i] = 1;
            }
            // down
            if(r + 1 < rows && forest[r+1][c] > 0) {
                map[i][i+cols] = 1;
                map[i+cols][i] = 1;
            }
        }
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
        //buildMap(forest, map);
        for(int i = 0; i < count; i++)
            shortestPath(forest, map, i);
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
            if(map[current][list[i]] == -1)
                return -1;
            sum += map[current][list[i]];
            current = list[i];
        }
        return sum;
    }
};