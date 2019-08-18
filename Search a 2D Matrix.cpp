class Solution {
public:
    /*pair<int,int> getIndex(int rows, int cols, int index) {
        // a matrix with `rows` rows, `cols` columns
        // current number is the index-th number in the matrix
        // return its row index and col index
        // 0 -> (0,0)
        // rows x cols -1 -> (rows-1, cols-1)
        // index -> (x,y)
        int rindex = x / cols;
        int cindex = x % cols;
        return pair<int,int>(rindex, cindex);
    }*/
    int getRowIndex(int rows, int cols, int index) {
        return index / cols;
    }
    int getColIndex(int rows, int cols, int index) {
        return index % cols;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int begin = 0;
        int end = rows * cols - 1;
        while(begin <= end) {
            int mid = (begin + end) / 2;
            int rind = getRowIndex(rows, cols, mid);
            int cind = getColIndex(rows, cols, mid);
            if(matrix[rind][cind] == target)
                return true;
            else if(matrix[rind][cind] < target)
                begin = mid + 1;
            else end = mid - 1;
        }
        return false;
    }
};