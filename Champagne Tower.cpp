class Solution {
public:
    double extra(int poured, int row, int glass, vector<vector<double>>& Tower) {
        if(row == -1 && (glass == 0 || glass == -1))
            return poured;
        if(row < glass || glass < 0 || row < 0)
            return 0;
        if(Tower[row][glass] != -1)
            return Tower[row][glass];
        double left = extra(poured, row - 1, glass - 1, Tower);
        double right = extra(poured, row - 1, glass, Tower);
        double current = (left + right) / 2.0;
        if(current > 1)
            Tower[row][glass] = current - 1;
        else Tower[row][glass] = 0;
        return Tower[row][glass];
    }
    double champagneTower(int poured, int query_row, int query_glass) {
        if(query_row < query_glass || query_glass < 0 || query_row < 0)
            return 0;
        vector<vector<double>> Tower(query_row, vector<double>(query_glass + 1, -1));
        double left = extra(poured, query_row - 1, query_glass - 1, Tower);
        double right = extra(poured, query_row - 1, query_glass, Tower);
        double current = (left + right) / 2.0;
        if(current > 1)
            return 1;
        else return current;
    }
};